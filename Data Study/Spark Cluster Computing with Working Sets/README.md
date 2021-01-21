# Spark: Cluster Computing with Working Sets
- Matei Zaharia, Mosharaf Chowdhury, Michael J. Franklin, Scott Shenker, Ion Stoica

- Abstract 요약

MapReduce and its variants have been highly successful in implementing large-scale data-intensive applications on commodity clusters. However, most of these systems are built around an acyclic data flow model that is not suitable for other popular applications. This paper focuses on one such class of applications: those that reuse a working set of data across multiple parallel operations. This includes many iterative machine learning algorithms, as well as interactive data analysis tools. We propose a new framework called Spark that supports these applications while retaining the scalability and fault tolerance of MapReduce. To achieve these goals, Spark introduces an abstraction called resilient distributed datasets (RDDs). An RDD is a read-only collection of objects partitioned across a set of machines that can be rebuilt if a partition is lost. Spark can outperform Hadoop by 10x in iterative machine learning jobs, and can be used to interactively query a 39 GB dataset with sub-second response time.

 맵리듀스와 그 유사 기술들은 범용 클러스터 상에서 대규모의 데이터 집약적인 애플리케이션을 구현하는데 매우 효과적이다. 그러나 이들 대부분의 시스템들은 단방향 데이터 흐름 모델을 기반으로 구축되어 있어서 어떤 애플리케이션에서는 적당하지 않다. 이 논문은 이러한 부류의 애플리케이션, 즉 다수의 병렬 오퍼레이션에서 데이터 작업 셋이 재사용되는 애플리케이션에 집중한다. 여기에는 인터랙티브한 데이터 분석 도구 뿐만아니라 반복적인 기계학습 알고리즘도 포함된다. 이 논문에서 제안하는 Spark는 맵리듀스의 확장성과 내고장성을 그대로 유지하면서 이러한 애플리케이션을 지원한다. 이러한 목적을 달성하기 위해서 스파크는 RDD라는 추상화를 소개한다. RDD는 여러 머신에 걸쳐 파티션이 분산되어있는 읽기 전용의 오브젝트 컬렉션이며 파티션이 유실되었을 경우 재구성할 수 있다. 스파크는 반복적인 기계학습 잡에서 하둡의 10배 이상의 성능을 보여주며, 39GB 데이터셋에 대한 인터랙디브 쿼리에서도 초단위의 응답시간을 갖는다. 

1. Introduction 소개

A new model of cluster computing has become widely popular, in which data-parallel computations are executed on clusters of unreliable machines by systems that automatically provide locality-aware scheduling, fault tolerance, and load balancing. MapReduce [11] pioneered this model, while systems like Dryad [17] and Map-Reduce-Merge [24] generalized the types of data flows supported. These systems achieve their scalability and fault tolerance by providing a programming model where the user creates acyclic data flow graphs to pass input data through a set of operators. This allows the underlying system to manage scheduling and to react to faults without user intervention. 

클러스터 컴퓨팅의 새 모델은 널리 쓰이게 되었다. 이 데이터 - 병렬적인 계산은 신뢰성이 부족한 장비로 구성된 클러스터 상에서 지역성이 반영된 스케줄링, 내고장성, 로드밸런싱을 자동으로 제공하는 시스템에 의해 수행된다. 맵리듀스는 이 모델을 이끌었고 드라이어드와 맵-리듀스-머지 같은 시스템들은 제공된 데이터 흐름의 타입을 일반화했다. 이러한 시스템은 어떤 프로그래밍 모델을 제공하여 확장성과 내고장성을 달성하는데 이 모델에서는 사용자가 일련의 오퍼레이션을 통해 비순환적인 데이터 흐름 그래프를 생성하여 입력 데이터에 전달하게 된다. 이는 기반 시스템이 스케줄링을 관리하고 사용자 인터랙션 없이도 고장에 반응할 수 있게 해준다.

While this data flow programming model is useful for a large class of applications, there are applications that cannot be expressed efficiently as acyclic data flows. In this paper, we focus on one such class of applications: those that reuse a working set of data across multiple parallel operations. This includes two use cases where we have seen Hadoop users report that MapReduce is deficient: 

데이터 흐름 프로그래밍 모델이 많은 부류의 애플리케이션에서 유용하지만, 비순환적인 데이터 흐름으로는 효과적으로 표현하기 힘들 수 있는 애플리케이션도 있다. 이 논문에서는 다수의 병렬 오퍼레이션상에서 작업 데이터 셋을 재사용하는 그런 부류의 애플리케이션에 집중한다. 이는 하둡 사용자들이 맵리듀스로 표현하기 부적당하다고 이야기하는 두 가지 사례를 포함한다. 

• Iterative jobs: Many common machine learning algorithms apply a function repeatedly to the same dataset to optimize a parameter (e.g., through gradient descent). While each iteration can be expressed as a MapReduce/Dryad job, each job must reload the data from disk, incurring a significant performance penalty. 

반복적인 잡: 일반적으로 많은 기계학습 알고리즘은 파라미터를 최적화하기 위해 한 함수를 같은 데이터셋에 반복적으로 적용한다(예를 들어 기울기 하강을 통해). 
각 반복 작업을 맵리듀스/드라이어드 잡으로 표현할 수는 있지만 각 잡은 데이터를 디스크로부터 재적재해야하며 이는 엄청난 성능 상의 불이익을 유발시킨다. 

• Interactive analytics: Hadoop is often used to run ad-hoc exploratory queries on large datasets, through SQL interfaces such as Pig [21] and Hive [1]. Ideally, a user would be able to load a dataset of interest into memory across a number of machines and query it repeatedly. However, with Hadoop, each query incurs significant latency (tens of seconds) because it runs as a separate MapReduce job and reads data from disk. 

인터랙티브한 분석: 거대한 데이터셋에 탐색적인 ad-hoc 쿼리를 수행하는데 종종 하둡이 사용되는데, PIG나 Hive같은 SQL 인터페이스를 이용한다. 이상적으로는 사용자가 관심있는 데이터셋을 다수의 머신상의 메모리로 로드하여 반복적으로 쿼리를 날릴 수 있다. 하지만 하둡은 분석 쿼리를 개별 맵리듀스 잡으로 수행하고 디스크에서 데이터를 읽기 때문에 수십 초 수준의 많은 지연을 발생시킨다

This paper presents a new cluster computing framework called Spark, which supports applications with working sets while providing similar scalability and fault tolerance properties to MapReduce.

 이 논문은 스파크라고 불리는 새로운 클러스터 컴퓨팅 프레임워크를 제안한다. 스파크는 맵리듀스와 비슷한 확장성과 내고장성 특성을 제공하면서도 작업 셋을 가진 애플리케이션을 지원한다. 

The main abstraction in Spark is that of a resilient distributed dataset (RDD), which represents a read-only collection of objects partitioned across a set of machines that can be rebuilt if a partition is lost. Users can explicitly cache an RDD in memory across machines and reuse it in multiple MapReduce-like parallel operations. RDDs achieve fault tolerance through a notion of lineage: if a partition of an RDD is lost, the RDD has enough information about how it was derived from other RDDs to be able to rebuild just that partition. Although RDDs are not a general shared memory abstraction, they represent a sweet-spot between expressivity on the one hand and scalability and reliability on the other hand, and we have found them well-suited for a variety of applications. 

스파크에서 메인 추상화는 RDD이다. RDD는 머신의 집합에서 분할되어있는 읽기 전용의 객체 컬렉션이며 파티션이 유실되었을 경우 재구성할 수도 있다. 사용자는 머신들 상의 메모리에 RDD를 명시적으로 캐시할 수 있고 맵리듀스와 유사한 다수의 병렬 작업에서 그것을 재사용할 수 있다. RDD는 리니지(?) 개념을 통해 내고장성을 지원한다. 만약 RDD의 일부분이 유실되더라도 RDD는 유실된 부분을 다른 RDD로부터 어떻게 도출하는지에 대한 충분한 정보를 갖고있다. RDD가 일반적인 공유 메모리 추상화는 아니지만, 표현력이라는 측면과 확장성과 신뢰성이라는 다른 측면 사이에서의 절충점을 제공한다. 그리고 우리는 그것이 다양한 애플리케이션에서 잘 들어맞는 것을 발견했다.

Spark is implemented in Scala [5], a statically typed high-level programming language for the Java VM, and exposes a functional programming interface similar to DryadLINQ [25]. In addition, Spark can be used interactively from a modified version of the Scala interpreter, which allows the user to define RDDs, functions, variables and classes and use them in parallel operations on a cluster. We believe that Spark is the first system to allow an efficient, general-purpose programming language to be used interactively to process large datasets on a cluster.  

스파크는 스칼라로 구현되었고, 자바 VM을 위한 강 타입의 고수준 프로그래밍 언어이며 DryadLINQ와 유사한 함수형 언어 인터페이스를 제공한다. 게다가 스파크는 수정된 버전의 스칼라 인터프리터에서 인터랙티브하게 사용할 수 있으며, 이 인터프리터는 사용자가 클러스터 상의 병렬적인 작업에서 RDD, 함수, 변수, 클래스를 정의하고 사용할 수 있게 해준다. 우리는 스파크가 클러스터상의 거대한 데이터를 인터랙티브하게 처리하는데 사용되는 효율적이며 일반 목적으로 사용할 수 있게 해주는 최초의 프로그래밍 언어라고 생각한다. 

Although our implementation of Spark is still a prototype, early experience with the system is encouraging. We show that Spark can outperform Hadoop by 10x in iterative machine learning workloads and can be used interactively to scan a 39 GB dataset with sub-second latency. 

우리의 스파크 구현은 아직 프로토타입이지만, 초기 시스템을 사용해본 결과는 매우 고무적이었다. 스파크는 반복적인 기계학습 작업에서는 하둡보다 10배 이상 빨랐으며 39 GB 데이터셋을 인터랙티브하게 스캔하는데 수 초 단위의 지연만으로 사용할 수 있었다. 

This paper is organized as follows. Section 2 describes Spark’s programming model and RDDs. Section 3 shows some example jobs. Section 4 describes our implementation, including our integration into Scala and its interpreter. Section 5 presents early results. We survey related work in Section 6 and end with a discussion in Section 7. 

이 논문은 다음과 같이 구성되어 있다. 2절은 스파크 프로그래밍 모델과 RDD를 설명한다. 3절은 몇 가지 예제 잡을 보여준다. 4절은 스칼라와 스칼라 인터프리터에 대한 통합을 포함해서 구현을 설명하고 5절은 초기 결과를 보여준다. 6절에서는 관련 연구를 조사하고 7절에서 논의하며 끝낸다.

2 Programming Model

To use Spark, developers write a driver program that implements the high-level control flow of their application and launches various operations in parallel. Spark provides two main abstractions for parallel programming: resilient distributed datasets and parallel operations on these datasets (invoked by passing a function to apply on a dataset). In addition, Spark supports two restricted types of shared variables that can be used in functions running on the cluster, which we shall explain later. 

스파크를 사용하기 위해, 개발자는 드라이버 프로그램을 작성하여 고수준에서의 애플리케이션 흐름을 제어하고 병렬로 다양한 작업을 실행시킨다. 스파크는 병렬 프로그래밍을 위한 두 가지 주요 추상화를 제공한다. 그것은 RDD와 RDD상에서의 병렬 작업이다 (데이터셋에 적용할 함수를 전달하여 수행됨). 추가로 스파크는 클러스터 상에서 수행중인 함수에서 사용될 수 있는 두 가지 제한적인 타입의 공유 변수를 제공한다. 이건 나중에 설명한다.  

- 2.1 Resilient Distributed Datasets (RDDs)

A resilient distributed dataset (RDD) is a read-only collection of objects partitioned across a set of machines that can be rebuilt if a partition is lost. The elements of an RDD need not exist in physical storage; instead, a handle to an RDD contains enough information to compute the RDD starting from data in reliable storage. This means that RDDs can always be reconstructed if nodes fail.

 RDD는 머신 집합 상에 분할되어있는 읽기 전용의 객체 컬렉션이며 부분적인 유실이 있을 경우 재구성할 수 있다. RDD의 원소가 물리적인 스토리지에 존재할 필요는 없다. 대신 RDD에 대한 핸들은 신뢰성있는 스토리지의 데이터로에서 시작하는 RDD를 계산하는데 충분한 정보를 담고 있다

In Spark, each RDD is represented by a Scala object. Spark lets programmers construct RDDs in four ways: 스파크에서 각 RDD는 스칼라 객체로 표현된다. 스파크는 RDD를 4가지 방법으로 구성하게 해준다. 

From a file in a shared file system, such as the Hadoop Distributed File System (HDFS). HDFSrkxdms 공유 파일시스템의 파일로부터 생성
By “parallelizing” a Scala collection (e.g., an array) in the driver program, which means dividing it into a number of slices that will be sent to multiple nodes. 드라이버 프로그램에서 배열같은 스칼라 컬렉션을 병렬화(parallelizing)하여 생성. 다수의 노드에 보낼 슬라이스 개수로 나누는 방법으로 생성. (?)
By transforming an existing RDD. A dataset with elements of type A can be transformed into a dataset with elements of type B using an operation called flatMap, which passes each element through a user-provided function of type A ⇒ List[B].1 Other transformations can be expressed using flatMap, including map (pass elements through a function of type A ⇒ B) and filter (pick elements matching a predicate). 

이미 존재하는 RDD를 변환(transforming)하여 생성. A 타입의 원소를 가진 데이터셋은 flatMap이라는 오퍼레이션을 사용하여 B타입의 원소를 가진 데이터셋으로 변환할 수 있다. flatMap는 사용자가 제공한 타입 A => List[B] 형태의 함수에 각 원소를 전달한다. map(A=>B 형태의 함수를 통해 원소를 전달함)과 filter(조건을 만족하는 원소를 선택함)같은 또 다른 변환을 flatMap을 사용해 표현될 수 있다. 
By changing the persistence of an existing RDD. By default, RDDs are lazy and ephemeral. That is, partitions of a dataset are materialized on demand when they are used in a parallel operation (e.g., by passing a block of a file through a map function), and are discarded from memory after use.2 However, a user can alter the persistence of an RDD through two actions: 이미 존재하는 RDD의 persistence를 캐시하여 생성. 디폴트로 RDD는 lazy하고 ephemeral하다.
즉, 데이터셋의 파티션은 그들이 병렬 오퍼레이션에서 사용될 때 마다 그때그때 실체화된다(즉 파일의 블럭을 map 함수를 통해 전달하여) 그리고 사용 후에 메모리에서 삭제된다. 그러나 사용자는 두 가지 액션을 통해 RDD의 persistence를 바꿀 수 있다. 
– The cache action leaves the dataset lazy, but hints that it should be kept in memory after the first time it is computed, because it will be reused. cache 액션은 데이터셋을 lazy하게 내버려둔다. 하지만 데이터셋이 재사용되기 때문에 최초로 계산하고나서 메모리에 남겨두어야 하는지에 대한 힌트를 준다.(?) 

– The save action evaluates the dataset and writes it to a distributed filesystem such as HDFS. The saved version is used in future operations on it. 

save 액션은 데이터셋을 평가하고 HDFS 같은 분산 파일시스템에 그것을 쓴다. 저장된 버전은 차후에 그것에 대한 오퍼레이션에서 사용된다.

We note that our cache action is only a hint: if there is not enough memory in the cluster to cache all partitions of a dataset, Spark will recompute them when they are used. We chose this design so that Spark programs keep working (at reduced performance) if nodes fail or if a dataset is too big. This idea is loosely analogous to virtual memory. 

우리는 cache 액션이 단순히 힌트라는 것을 알아두어라. 만약 클러스터에 데이터셋의 모든 파티션을 캐쉬할 충분한 메모리가 없다면 스파크는 데이터셋이 사용될 때 그것을 재계산할 것이다. 우리는 노드에 장애가 나거나 데이터셋이 너무 클 때에도 스파크 프로그램이 계속 동작할 수 있도록 (성능은 떨어지지만) 이 디자인을 선택했다. 이 아이디어는 가상 메모리와 약간 비슷하다. 

We also plan to extend Spark to support other levels of persistence (e.g., in-memory replication across multiple nodes). Our goal is to let users trade off between the cost of storing an RDD, the speed of accessing it, the probability of losing part of it, and the cost of recomputing it. 

또한 우리는 다른 레벨의 persistence를 제공하도록 스파크를 확장할 계획이다(예를 들어, 다수 노드상에서 메모리 상에 복제본). 우리의 사용자가 RDD에 대한 저장 비용, 접근 속도, 일부를 잃어버릴 확률, 재계산하는 비용 사이에서 취사선택할 수 있도록 하는 것을 목표로 하고 있다. 

2.2 Parallel Operations

Several parallel operations can be performed on RDDs: RDD에 몇 개의 병렬 오퍼레이션을 수행할 수 있다. 

• reduce: Combines dataset elements using an associative function to produce a result at the driver program. reduce: 

드라이버 프로그램에서 결과를 생성하기 위해 결합적(associative) 함수를 이용하여 데이터셋의 원소를 병합한다. 

• collect: Sends all elements of the dataset to the driver program. For example, an easy way to update an array in parallel is to parallelize, map and collect the array. collect: 

데이터셋의 모든 원소를 드라이버 프로그램에 보낸다. 예를 들어, 배열을 병렬로 업데이트하는 간단한 방법은 배열을 parallelize하고 map하고 collect하는 것이다. 

• foreach: Passes each element through a user provided function. This is only done for the side effects of the function (which might be to copy data to another system or to update a shared variable as explained below). 

fore ach: 사용자가 제공한 함수를 통해 각 원소를 전달한다. 이것은 오로지 데이터를 다른 시스템에 복사하거나 아래에서 설명할 공유 변수를 업데이트하는것 같은 함수의 부수효과를 위해서만 수행된다. 

We note that Spark does not currently support a grouped reduce operation as in MapReduce; reduce results are only collected at one process (the driver).3 We plan to support grouped reductions in the future using a “shuffle” transformation on distributed datasets, as described in Section 7. However, even using a single reducer is enough to express a variety of useful algorithms. For example, a recent paper on MapReduce for machine learning on multicore systems [10] implemented ten learning algorithms without supporting parallel reduction.

 스파크는 현재 맵리듀스같은 그룹화된 리듀스 작업은 지원하지 않는다. reduce 결과는 오직 한 프로세스(드라이버)에서 취합된다. 향후 분산 데이터셋에 대한 shuffle 변환을 사용하여 그룹화된 리듀스 작업을 지원할 계획이다. 이건 7절에 소개한다. 그러나 단일 리듀서만 사용해도 많은 유용한 알고리즘들을 표현하기에 충분하다. 예를 들어 ‘MapReduce for machine learning on multicore systems’ 논문에서도 병렬 리듀서의 지원 없이 10개의 학습 알고리즘을 구현했다. 

- 2.3 Shared Variables

Programmers invoke operations like map, filter and reduce by passing closures (functions) to Spark. As is typical in functional programming, these closures can refer to variables in the scope where they are created. Normally, when Spark runs a closure on a worker node, these variables are copied to the worker. However, Spark also lets programmers create two restricted types of shared variables to support two simple but common usage patterns: 

프로그래머는 스파크에게 클로져(함수)를 전달하면서 map, filter, reduce 같은 오퍼레이션을 호출한다. 함수형 언어에서 일반적인 것처럼, 이 클러져는 그것이 생성된 스코프에서 변수를 참조할 수 있다. 보통 스파크가 클로저를 워커 노드에서 수행할 때 이 변수들은 워커로 카피된다. 또한 스파크는 간단하지만 일반적으로 사용되는  두 가지 패턴을 지원하기 위해서 프로그래머가 두 가지 제한된 타입의 공유 변수를 생성할 수 있게 해준다. 

• Broadcast variables: If a large read-only piece of data (e.g., a lookup table) is used in multiple parallel operations, it is preferable to distribute it to the workers only once instead of packaging it with every closure. Spark lets the programmer create a “broadcast variable” object that wraps the value and ensures that it is only copied to each worker once.

 브로드캐스트 변수: 만약 거대한 읽기 전용 데이터 조각(예를 들어 룩업 테이블)이 다수의 병렬 오퍼레이션에서 사용된다면 모든 클로져에 그 데이터를 묶어주는것 보다는 워커들에게 한 번만 분배하는 것이 바람직하다. 

• Accumulators: These are variables that workers can only “add” to using an associative operation, and that only the driver can read. They can be used to implement counters as in MapReduce and to provide a more imperative syntax for parallel sums. Accumulators can be defined for any type that has an “add” operation and a “zero” value. Due to their “add-only” semantics, they are easy to make fault-tolerant. Accumulators: 이것은 워커들이 결합적(associative) 함수를 이용하여 오직 더하기만 수행하고 드라이버에서는 그 값을 읽기만 할 수 있는 변수이다. 

그들은 맵리듀스의 카운터같은 것을 구현하고 병렬 합산을 위한 더욱 엄격한 문법(syntax)를 제공하는데 사용할 수 있다. Accumulator는 add 오퍼레이션과 zero 값을 가지가만 하면 어떤 타입으로도 정의할 수 있다. accumulator는 덧셈 전용 시멘틱 때문에 내고장성을 제공하기 쉽다. 

3.  Examples 예제들

We now show some sample Spark programs. Note that we omit variable types because Scala supports type inference. 여기에서는 몇 가지 스파크 프로그램 샘플을 소개한다. 스칼라는 타입 추론을 지원하기 때문에 변수 타입을 생략하는 것에 주의하라.

3.1 Text Search

Suppose that we wish to count the lines containing errors in a large log file stored in HDFS. This can be implemented by starting with a file dataset object as follows: HDFS에 저장된 거대한 로그파일에서 error가 있는 라인 수를 세고 싶다고 해보자. 다음과 같이 데이터셋 객체에서 시작하여 구현할 수 있다. 

```
val file = spark.textFile("hdfs://...")
val errs = file.filter(_.contains("ERROR"))
val ones = errs.map(_ => 1)
val count = ones.reduce(_+_)
We first create a distributed dataset called file that represents the HDFS file as a collection of lines. We transform this dataset to create the set of lines containing “ERROR” (errs), and then map each line to a 1 and add up these ones using reduce. The arguments to filter, map and reduce are Scala syntax for function literals. 
```

먼저 라인들의 집합으로 HDFS 파일을 나타내는 file이라는 분산 데이터셋을 생성한다. 그리고 문자열 “ERROR”를 담고있는 라인의 집합(errs)을 생성하기 위해 이 데이터셋을 변환한 후 각 라인을 1로 매핑하고 reduce를 이용하여 그것들을 합산한다. filter, map, reduce에 들어가는 인자는 함수 리터럴을 위한 스칼라 문법이다.

Note that errs and ones are lazy RDDs that are never materialized. Instead, when reduce is called, each worker node scans input blocks in a streaming manner to evaluate ones, adds these to perform a local reduce, and sends its local count to the driver. When used with lazy datasets in this manner, Spark closely emulates MapReduce. 

errs와 ones는 실체화된적이 없는 lazy RDD라는 점에 주의하라. 대신, reduce가 호출될 때 각 워커 노드는 ones를 평가하기 위해 스트리밍 방식으로 입력 블럭을 스캔하고, 로컬 리듀스를 수행하기 위해 이것들을 합산하고, 그것에 대한 로컬 카운트를 드라이버로 보낸다. 이런 방식으로 lazy 데이터셋을 사용해서 스파크는 맵리듀스를 비슷하게 모방한다. 

Where Spark differs from other frameworks is that it can make some of the intermediate datasets persist across operations. For example, if wanted to reuse the errs dataset, we could create a cached RDD from it as follows: 스파크가 다른 프레임워크와 다른 지점은 중간 데이터셋의 일부를 오퍼레이션에 걸쳐 persist로 만들수 있다는 부분이다. 예를 들어 errs 데이터셋을 재사용하고 싶다면 다음과 같이 errs로부터 캐쉬된 RDD를 생성할 수 있다. 

```
val cachedErrs = errs.cache()
We would now be able to invoke parallel operations on cachedErrs or on datasets derived from it as usual, but nodes would cache partitions of cachedErrs in memory after the first time they compute them, greatly speeding up subsequent operations on it. 
```
이제 cachedErrs 또는 그것에서 파생된 데이터셋에 대해 평상시처럼 병렬 오퍼레이션을 호출할 수 있게 된다. 노드들에서 처음으로 cachedErrs를 계산하고 나면 cachedErrs의 파티션을 메모리에 캐쉬하므로 그에 대한 다음 오퍼레이션은 엄청나게 빠른 속도로 수행된다. 

- 3.2 Logistic Regression

The following program implements logistic regression [3], an iterative classification algorithm that attempts to find a hyperplane w that best separates two sets of points. The algorithm performs gradient descent: it starts w at a random value, and on each iteration, it sums a function of w over the data to move w in a direction that improves it. It thus benefits greatly from caching the data in memory across iterations. We do not explain logistic regression in detail, but we use it to show a few new Spark features. 

아래 프로그램을 로지스틱 회귀를 구현한다. 이것은 점들을 두 집합으로 분리하는 가장 최적의 하이퍼플레인 w를 찾으려고 시도하는 반복적인 분류 알고리즘이다. 알고리즘은 gradient descent를 수행한다. GD는 랜덤값으로 w를 시작하고, 각 반복에서 개선하는 방향으로 w를 움직이기 위해 데이터셋 상에서 w의 함수를 합한다. 고로 각 반복에 걸쳐 데이터를 메모리에 캐쉬하면 커다란 이득이 된다. 로지스틱 회귀를 자세하게 설명하지 않지만 스파크의 새로운 몇 가지 기능을 보여주는데 그것을 사용한다. 

```
// Read points from a text file and cache them
val points = spark.textFile(...).map(parsePoint).cache()
// Initialize w to random D-dimensional vector
var w = Vector.random(D)
// Run multiple iterations to update w
for (i <- 1 to ITERATIONS) {
    val grad = spark.accumulator(new Vector(D))
    for (p <- points) { // Runs in parallel
        val s = (1/(1+exp(-p.y*(w dot p.x)))-1)*p.y
        grad += s * p.x
    }
    w -= grad.value
}
```
First, although we create an RDD called points, we process it by running a for loop over it. The for keyword in Scala is syntactic sugar for invoking the foreach method of a collection with the loop body as a closure. That is, the code for(p <- points){body} is equivalent to points.foreach(p => {body}). Therefore, we are invoking Spark’s parallel foreach operation.

 첫째로, points라는 RDD를 생성하고 for 루프를 수행하며 그것을 반복 처리한다. 스칼라에서 for 키워드는 클로져를 loop 몸체로 가지는 컬렉션의 foreach 메소드를 호출하기 위한 syntactic sugar이다. 즉, for(p <- points){body}라는 코드는 points.foreach(p => {body})와 같다. 그러므로 스파크의 병렬 foreach 오퍼레이션을 수행한 것이다.

Second, to sum up the gradient, we use an accumulator variable called gradient (with a value of type Vector). Note that the loop adds to gradient using an overloaded += operator. The combination of accumulators and for syntax allows Spark programs to look much like imperative serial programs. Indeed, this example differs from a serial version of logistic regression in only three lines. 

둘째로, gradient를 합산하기 위해 Vector 타입의 값을 가지는 gradient라는 accumulator 변수를 사용한다. loop에서 gradient를 더하는데 오버로딩한 += 연산자를 사용하는 것에 주의하라. accumulator와 for 문법의 조합은 스파크 프로그램을 좀 더 명령형 순차 프로그램처럼 보이게 해준다. 실제로 이 예제는 순차 버전의 로지스틱 회귀와 단 3줄만 다르다. 

- 3.3 Alternating Least Squares

Our final example is an algorithm called alternating least squares (ALS). ALS is used for collaborative filtering problems, such as predicting users’ ratings for movies that they have not seen based on their movie rating history (as in the Netflix Challenge). Unlike our previous examples, ALS is CPU-intensive rather than data-intensive. 마지막 예제는 ALS라 불리는 알고리즘이다. ALS는 사용자의 별점 이력에 기반하여 그들이 보지 않은 영화에 대한 별점을 예측하는 협업 필터링 문제에 사용된다. 이전까지의 예제와는 다르게 ALS는 데이터 집약적이기 보다는 계산 집약적이다.

We briefly sketch ALS and refer the reader to [27] for details. Suppose that we wanted to predict the ratings of u users for m movies, and that we had a partially filled matrix R containing the known ratings for some user-movie pairs. ALS models R as the product of two matrices M and U of dimensions m × k and k × u respectively; that is, each user and each movie has a k-dimensional “feature vector” describing its characteristics, and a user’s rating for a movie is the dot product of its feature vector and the movie’s. ALS solves for M and U using the known ratings and then computes M × U to predict the unknown ones. This is done using the following iterative process: 여기서는 ALS를 간단히 설명한다. 자세한 내용은 [27]을 참고하라. 우리는 u 사용자가 m 영화에 별점 몇점을 줄것인지 예측하기를 원하고, 사용자가 선호도를 표시한 몇 개의 영화에 대한 별점 정보가 부분적으로 담겨있는 메트릭스 R을 갖고 있다고 해보자. ALS는 R을 각각 m*k, k*u 차원을 가진 M과 U 두 메트릭스의 곱으로 모델링한다. 즉, 각 사용자와 영화는 특징을 설명하는 k 차원 특성 벡터를 가진다. 그리고 영화에 대한 사용자의 선호도는 해당 사용자와 영화의 특성벡터의 내적이다. ALS는 알려진 선호도값에서 M과 U를 풀고나서 알려지지 않은 값을 예측하기 위해 M*U를 계산한다. 이는 아래와 같은 반복적인 프로세스로 수행된다. 

1. Initialize M to a random value. M을 랜덤값으로 초기화한다.
2. Optimize U given M to minimize error on R. 주어진 M에 대해 R과의 오차를 최소화하도록 U를 최적화한다.
3. Optimize M given U to minimize error on R. 주어진 U에 대해 R과의 오차를 최소화하도록 M를 최적화한다.
4. Repeat steps 2 and 3 until convergence. 수렴할때까지 단계 2와 3을 반복한다.

ALS can be parallelized by updating different users / movies on each node in steps 2 and 3. However, because all of the steps use R, it is helpful to make R a broadcast variable so that it does not get re-sent to each node on each step. A Spark implementation of ALS that does is shown below. Note that we parallelize the collection 0 until u (a Scala range object) and collect it to update each array: ALS는 단계 2, 3에서 각 노드에 다른 사용자/영화를 업데이트하여 병렬화할 수 있다. 그러나 모든 스텝에서 R을 사용하기 때문에 매 단계에서 각 노드에 재전송하지 않도록 R을 broadcast 변수로 만드는 편이 유용하다. 스파크의 ALS 구현은 아래와 같다. 0부터 u까지 컬렉션(스칼라 range 객체)을 parallelize하고 각 배열을 업데이트하기 위해 그것을 collect하는 것에 유의하라. 

```
val Rb = spark.broadcast(R)
for (i <- 1 to ITERATIONS) {
  U = spark.parallelize(0 until u)
           .map(j => updateUser(j, Rb, M))
           .collect()
  M = spark.parallelize(0 until m)
           .map(j => updateUser(j, Rb, U))
           .collect()
}
```
4. Implementation 구현

Spark is built on top of Mesos [16, 15], a “cluster operating system” that lets multiple parallel applications share a cluster in a fine-grained manner and provides an API for applications to launch tasks on a cluster. This allows Spark to run alongside existing cluster computing frameworks, such as Mesos ports of Hadoop and MPI, and share data with them. In addition, building on Mesos greatly reduced the programming effort that had to go into Spark. 스파크는 Mesos 위에 구축된다. Mesos는 다수의 병렬 어플리케이션이 fine-grained 방법으로 클러스터를 공유하고 클러스터 상에서 태스크를 실행하기 위해 애플리케이션을 위한 API를 제공하는 클러스터 운영 체제이다. 이것은 스파크가 하둡, MPI같은 기존의 클러스터 프레임워크와 함께 수행되고 그들 간에 데이터를 공유할 수 있게 해준다.(?) 게다가 Mesos 상에 구축하는 것은 스파크에 들여야 하는 프로그래밍 노력을 엄청나게 감소시켜준다. 

The core of Spark is the implementation of resilient distributed datasets. As an example, suppose that we define a cached dataset called cachedErrs representing error messages in a log file, and that we count its elements using map and reduce, as in Section 3.1: 스파크 코어는 RDD의 구현체이다. 예를 들어, 3.1절에서처럼 로그 파일에서 에러 메시지를 나타내는 cachedErrs라는 캐쉬된 데이터셋을 정의하고, map과 reduce를 사용해 그것의 원소를 세고 있다고 해보자. 

val file = spark.textFile("hdfs://...")
val errs = file.filter(_.contains("ERROR"))
val cachedErrs = errs.cache()
val ones = cachedErrs.map(_ => 1)
val count = ones.reduce(_+_)
These datasets will be stored as a chain of objects capturing the lineage of each RDD, shown in Figure 1. Each dataset object contains a pointer to its parent and information about how the parent was transformed. 이 데이터셋은 그림 1에서 보는 것처럼 각 RDD의 리니지를 포착하는 객체의 연쇄로서 저장된다. 각 데이터셋 객체는 그것의 부모에 대한 포인터를 갖고 있으며 부모가 어떻게 변환되었는지에 대한 정보도 가지고 있다. 

Internally, each RDD object implements the same simple interface, which consists of three operations: 내부적으로 각 RDD 객체는 세 가지 오퍼레이션으로 구성된 동일한 간단한 인터페이스를 구현한다. 

getPartitions, which returns a list of partition IDs. 파티션 ID 리스트를 반환한다.
getIterator(partition), which iterates over a partition. 파티션 상에서 반복을 수행한다.
getPreferredLocations(partition), which is used for task scheduling to achieve data locality. 데이터 지역성을 달성하는데 필요한 태스크 스케줄링을 위해 사용된다. 
When a parallel operation is invoked on a dataset, Spark creates a task to process each partition of the dataset and sends these tasks to worker nodes. We try to send each task to one of its preferred locations using a technique called delay scheduling [26]. Once launched on a worker, each task calls getIterator to start reading its partition. 데이터셋에서 병렬 오퍼레이션이 수행될 때, 스파크는 데이터셋의 각 부분을 처리하기 위해 태스크를 생성하고 이것을 워커 노드에 보낸다. 우리는 지연 스케줄링이라는 기술을 사용해서 각 태스크를 적당한 위치 중 한군데로 보내려고 시도한다. 일단 워커에서 수행되면 각 태스크는 각 파티션을 읽기 시작하기 위해 getIterator를 호출한다. 

Figure 1: Lineage chain for the distributed dataset objects defined in the example in Section 4.

The different types of RDDs differ only in how they implement the RDD interface. For example, for a HdfsTextFile, the partitions are block IDs in HDFS, their preferred locations are the block locations, and getIterator opens a stream to read a block. In a MappedDataset, the partitions and preferred locations are the same as for the parent, but the iterator applies the map function to elements of the parent. Finally, in a CachedDataset, the getIterator method looks for a locally cached copy of a transformed partition, and each partition’s preferred locations start out equal to the parent’s preferred locations, but get updated after the partition is cached on some node to prefer reusing that node. This design makes faults easy to handle: if a node fails, its partitions are re-read from their parent datasets and eventually cached on other nodes. 

다른 종류의 RDD는 RDD 인터페이스를 어떻게 구현했는지만 다르다. 예들 들어, HdfsTextFile에서는 파티션은 블럭 ID이고, 적절한 위치는 블럭 위치이며, getIterator는 블럭을 읽기 위해 스트림을 연다. MappedDataset에서는 파티션과 적당한 위치가 부모와 동일하다. 그러나 반복자는 맵 함수를 부모의 원소에 적용한다. 마지막으로 CachedDataset에서는 getIterator 메소드가 변환된 파티션의 캐쉬된 지역 카피본을 찾고, 각 파티션의 선호 위치는 처음엔 부모의 선호 위치와 동일하게 시작하지만 파티션이 어떤 노드에 캐쉬되고나면 그 노드에서 재사용하기 편하게 하기위해 업데이트 된다. 이 디자인은 고장을 쉽게 처리할 수 있게 해준다. 만약 노드가 실패하면 그것의 파티션은 부모 데이터셋으로부터 다시 읽어들여지고 결국 다른 노드에 캐쉬된다. 
Finally, shipping tasks to workers requires shipping closures to them—both the closures used to define a distributed dataset, and closures passed to operations such as reduce. To achieve this, we rely on the fact that Scala closures are Java objects and can be serialized using Java serialization; this is a feature of Scala that makes it relatively straightforward to send a computation to another machine. Scala’s built-in closure implementation is not ideal, however, because we have found cases where a closure object references variables in the closure’s outer scope that are not actually used in its body. We have filed a bug report about this, but in the meantime, we have solved the issue by performing a static analysis of closure classes’ bytecode to detect these unused variables and set the corresponding fields in the closure object to null. We omit the details of this analysis due to lack of space. 

마지막으로, 태스크를 워커에 적재하는 것은 워커에 클로저를 적재하는것을 필요로 한다. 이는 분산 데이터셋을 정의하기 위해 사용되는 클로저와 reduce같이 오퍼레이션에 전달하기 위한 클로저 모두에 해당한다. 이를 위해 우리는 스칼라 클로저가 자바 객체이고 자바 serialization을 사용하여 직렬화될수 있다는 점에 의존한다. 이것은 계산을 다른 머신에 보내기 쉽게 만들어주는 스칼라의 특징이다. 그러나 클로저 오브젝트가 몸체에서 실제로 사용되지 않는 클로저의 스코프 바깥에서 변수를 참조하는 경우가 발견되었기 때문에 스칼라의 내장 클로저 구현은 이상적이지 않다. 우리는 이에 대한 버그 리포트를 많이 받았지만 동시에 미사용 변수를 검출하고 클로저 객체에서 해당 필드를 null로 세팅하기 위해 클로저 클래스의 바이트코드에 대한 정적 분석을 수행하여 이슈를 해결했다. 공간 부족으로 자세한 내용은 생략한다. 

Shared Variables: The two types of shared variables in Spark, broadcast variables and accumulators, are implemented using classes with custom serialization formats. When one creates a broadcast variable b with a value v, v is saved to a file in a shared file system. The serialized form of b is a path to this file. When b’s value is queried on a worker node, Spark first checks whether v is in a local cache, and reads it from the file system if it isn’t. We initially used HDFS to broadcast variables, but we are developing a more efficient streaming broadcast system. 

공유 변수: 스파크에는 브로드캐스트 변수와 accumulator 두 종류의 공유 변수가 커스텀 직렬화 포맷의 클래스를 사용하여 구현되었다. 사용자가 브로드캐스트 변수 b를 v라는 값으로 생성하면 v는 공유 파일 시스템에 파일로 저장된다. b의 직렬화된 형태는 이 파일에 대한 경로이다. 워커 노드에서 b의 값이 요청되면 스파크는 먼저 v가 로컬 캐쉬에 있는지 여부를 체크하고 만약 없다면 파일 시스템에서 읽어들인다. 처음에는 브로드캐스트 변수에 HDFS를 사용했으나 좀 더 효율적인 스트리밍 브로드캐스트 시스템을 개발중이다. 

Accumulators are implemented using a different “serialization trick.” Each accumulator is given a unique ID when it is created. When the accumulator is saved, its serialized form contains its ID and the “zero” value for its type. On the workers, a separate copy of the accumulator is created for each thread that runs a task using thread-local variables, and is reset to zero when a task begins. After each task runs, the worker sends a message to the driver program containing the updates it made to various accumulators. The driver applies updates from each partition of each operation only once to prevent doublecounting when tasks are re-executed due to failures. 

accumulator는 다른 직렬화 트릭을 사용해서 구현된다. 각 accumulator에는 생성 시점에 고유 ID가 주어진다. accumulator가 저장될 때 직렬화 형식은 ID와 해당 타입의 zero 값을 포함한다. 워커에서는 태스크를 수행하는 각 스레드를 위해 별도의 accumulator 복사본이 thread-local 변수를 사용하여 생성되고 태스크가 시작할 때 zero로 리셋된다. 각 태스크가 수행된 후 워커는 여러 accumulator에 가해진 업데이트를 담고 있는 메세지를 드라이버 프로그램에 보낸다. 드라이버는 실패로 인해 재실행된 태스크에서 중복 카운팅되는 것을 막기 위해 각 오퍼레이션의 각 파티션으로부터 단 한번만 업데이트한다. 

Interpreter Integration: Due to lack of space, we only sketch how we have integrated Spark into the Scala interpreter. The Scala interpreter normally operates by compiling a class for each line typed by the user. This class includes a singleton object that contains the variables or functions on that line and runs the line’s code in its constructor. For example, if the user types var x = 5 followed by println(x), the interpreter defines a class (say Line1) containing x and causes the second line to compile to println(Line1.getInstance().x). These classes are loaded into the JVM to run each line. To make the interpreter work with Spark, we made two changes: 인터프리터 통합: 공간 부족 때문에 스파크를 스칼라 인터프리터에 어떻게 통합했는지 간단하게만 언급하겠다. 스칼라 인터프리터는 보통 사용자가 형식화한 각 라인에 대한 클래스를 컴파일하여 작동한다. 이 클래스는 그 라인 상의 변수나 함수를 담고 있는 싱글톤 객체를 포함하며, 라인의 코드를 해당 생성자에서 수행한다. 예를 들어 사용자가 x = 5 다음에 println(x)를 쳤다면 인터프리터는 x를 담고 있는 Line1이라 불리는 클래스를 정의하며 두 번째 라인을 println(Line1.getInstance().x)로 컴파일하게 만든다. 이 클래스들은 각 라인을 실행하기 위해 JVM에 로드된다. 스파크에서 인터프리터가 작동하도록 하기 위해 두 가지를 수정하였다. 

We made the interpreter output the classes it defines to a shared filesystem, from which they can be loaded by the workers using a custom Java class loader. 우리는 인터프리터가 공유 파일시스템에 정의한 클래스를 출력하게 했고 워커가 커스텀 자바 클래스 로더를 사용해 로드할 수 있다. 
We changed the generated code so that the singleton object for each line references the singleton objects for previous lines directly, rather than going through the static getInstance methods. This allows closures to capture the current state of the singletons they reference whenever they are serialized to be sent to a worker. If we had not done this, then updates to the singleton objects (e.g., a line setting x = 7 in the example above) would not propagate to the workers. 정적 getInstance 메소드를 통하기 보다는 각 라인에 대한 싱글턴 객체가 직접 이전 라인의 싱글턴 객체를 참조하도록 생성 코드를 수정했다. 이는 클로저가 워커에 보내지기 위해 직렬화될 때 마다 싱글턴이 참조하는 현재 상태를 캡쳐할 수 있게 해준다. 만약 이렇게 하지 않았다면 싱글턴 객체에 대한 업데이트는 워커들로 전파되지 않을 것이다. 

5. Results

Although our implementation of Spark is still at an early stage, we relate the results of three experiments that show its promise as a cluster computing framework. 스파크 구현은 아직 초기 단계지만 클러스터 컴퓨팅 프레임워크로써의 가능성을 보여주는 3 가지 실험 결과를 소개한다. 

Logistic Regression: We compared the performance of the logistic regression job in Section 3.2 to an implementation of logistic regression for Hadoop, using a 29 GB dataset on 20 “m1.xlarge” EC2 nodes with 4 cores each. The results are shown in Figure 2. With Hadoop, each iteration takes 127s, because it runs as an independent MapReduce job. With Spark, the first iteration takes 174s (likely due to using Scala instead of Java), but subsequent iterations take only 6s, each because they reuse cached data. This allows the job to run up to 10x faster. 로지스틱 회귀: 3.2절에서 소개한 로지스틱 회귀의 성능과 하둡을 이용한 구현의 성능을 비교하였다. 4코어 m1.xlarge EC2 노드 20대에서 29 GB 데이터를 사용했을 때 결과는 그림 2와 같다. 하둡 구현에서는 각 반복이 독립적인 맵리듀스 잡으로 수행되기 때문에 127s 소요된다. 스파크에서는 첫 번째 반복만 174s 걸렸을(자바 대신 스칼라를 사용하기 때문인 것 같음) 뿐 이후부터는 캐쉬된 데이터를 재사용하기 때문에 각 반복에서 단 6s만 소요된다. 이는 잡을 10배 더 빠르게 수행하게 해준다. 



Figure 2: Logistic regression performance in Hadoop and Spark.

We have also tried crashing a node while the job was running. In the 10-iteration case, this slows the job down by 50s (21%) on average. The data partitions on the lost node are recomputed and cached in parallel on other nodes, but the recovery time was rather high in the current experiment because we used a high HDFS block size (128 MB), so there were only 12 blocks per node and the recovery process could not utilize all cores in the cluster. Smaller block sizes would yield faster recovery times. 잡 수행중에 노드를 정지시키는 실험도 수행했는데 10-이터레이션의 경우 평균적으로 50s(21%)까지 느려졌다. 고장난 노드의 데이터 파티션이 다른 노드들에서 병렬로 재계산되고 캐쉬되었지만 이 실험에서는 복구 시간이 다소 높았다. 이는 큰 HDFS 블럭 크기(128 MB)를 사용하여 노드 당 12 블럭만 존재했고 복구 프로세스가 클러스터의 모든 코어를 활용하지 못했기 때문이다. 작은 블럭 크기를 사용하면 복구 시간도 빨라질 것이다. 

Alternating Least Squares: We have implemented the alternating least squares job in Section 3.3 to measure the benefit of broadcast variables for iterative jobs that copy a shared dataset to multiple nodes. We found that without using broadcast variables, the time to resend the ratings matrix R on each iteration dominated the job’s running time. Furthermore, with a na ̈ıve implementation of broadcast (using HDFS or NFS), the broadcast time grew linearly with the number of nodes, limiting the scalability of the job. We implemented an application-level multicast system to mitigate this. However, even with fast broadcast, resending R on each iteration is costly. Caching R in memory on the workers using a broadcast variable improved performance by 2.8x in an experiment with 5000 movies and 15000 users on a 30-node EC2 cluster. ALS: 다수의 노드에 공유 데이터셋을 복사하는 반복적인 잡을 위한 브로드캐스트 변수의 이점을 측정하기 위해 3.3절에서 ALS를 구현했다. 브로드캐스트 변수를 사용하지 않을 경우 각 이터레이션에서 선호도 메트릭스 R을 다시 보내는 시간이 잡의 수행 시간을 결정한다는 것을 알았다. 게다가 브로드캐스트의 나이브한 구현(HDFS나 NFS 사용)에서 브로드캐스트 시간은 잡의 확장성에 제한을 두고(?) 노드의 개수에 대해 선형적으로 증가했다. 이를 완화시키려고 애플리케이션 레벨에서 멀티캐스트 시스템을 구현했으나 R을 재전송하는것은 빠른 브로드캐스트에서도 여전히 비용이 컸다. 브로드캐스트 변수를 사용해서 R을 워커의 메모리에 캐싱하는 것은 성능을 2.8배까지 개선시켰다.(5000 영화, 15000 사용자, 30 노드 EC2 클러스터에서 실험) 

Interactive Spark: We used the Spark interpreter to load a 39 GB dump of Wikipedia in memory across 15 “m1.xlarge” EC2 machines and query it interactively. The first time the dataset is queried, it takes roughly 35 seconds, comparable to running a Hadoop job on it. However, subsequent queries take only 0.5 to 1 seconds, even if they scan all the data. This provides a qualitatively different experience, comparable to working with local data. 인터랙티브 스파크: 39 GB 위키피디아 덤프를 15개의 m1.xlarge EC2 머신상의 메모리에 로드하는데 스파크 인터프리터를 사용했고 거기에 인터랙티브한 쿼리를 수행했다. 데이터셋이 처음 쿼리됐을 때 대략 35초 정도 소요되어 하둡 잡으로 수행했을 때와 비슷했다. 하지만 후속 쿼리들은 단지 0.5~1초만에 전체 데이터를 스캔할 수 있었다. 이것은 로컬 데이터로 작업하는것과 비견되는 차원이 다른 경험을 제공한다. 

6. Related Work

Distributed Shared Memory: Spark’s resilient distributed datasets can be viewed as an abstraction for distributed shared memory (DSM), which has been studied extensively [20]. RDDs differ from DSM interfaces in two ways. First, RDDs provide a much more restricted programming model, but one that lets datasets be rebuilt efficiently if cluster nodes fail. While some DSM systems achieve fault tolerance through checkpointing [18], Spark reconstructs lost partitions of RDDs using lineage information captured in the RDD objects. This means that only the lost partitions need to be recomputed, and that they can be recomputed in parallel on different nodes, without requiring the program to revert to a checkpoint. In addition, there is no overhead if no nodes fail. Second, RDDs push computation to the data as in MapReduce [11], rather than letting arbitrary nodes access a global address space.

 분산 공유 메모리: 스파크 RDD는 이미 광범위하게 연구되어온 분산 공유 메모리 (DSM)에 대한 추상화로 볼 수 있다. RDDs 는 두 가지 방법으로 DSM 인터페이스와 다르다. 첫째로, RDDs 는 훨씬 제한적 프로그래밍 모델을 제공한다, 그러나 그것은 만약 클러스터 노드가 실패했을 때 데이터셋을 효과적으로 재 구축할 수 있다. 일부 DSM 시스템은 내결함성을 체크 포인팅을 통해 달성하는 동안, 스파크는 RDD 객체안에 캡쳐된 계보 정보를 사용해서 잃어버린 RDDs 의 파티션을 재구축한다. 이것은 오직 잃어버린 파티션만 다시 계산해야 한다는 것을 의미하고, 그것은 프로그램의 체크포인트로 프로그램을 되돌릴 필요 없이, 다른 노드 위에서 병렬로 다시 계산할 수 있다는 의미이다. 추가로, 그들은 노드가 실패하지 않는 경우 오버헤드가 없다. 둘째, RDDs 는 임의의 노드가 글로벌 주소 공간에 접근하게 하는 것이 아니라 맵리듀스처럼 데이터에 계산을 전송한다. 

Other systems have also restricted the DSM programming model to improve performance, reliability and programmability. Munin [8] lets programmers annotate variables with the access pattern they will have so as to choose an optimal consistency protocol for them. Linda [13] provides a tuple space programming model that may be implemented in a fault-tolerant fashion. Thor [19] provides an interface to persistent shared objects. (Munin, Linda, Thor같은 다른 시스템 소개)

Cluster Computing Frameworks: Spark’s parallel operations fit into the MapReduce model [11]. However, they operate on RDDs that can persist across operations. 

클러스터 컴퓨팅 프레임워크: 스파크의 병렬 오퍼레이션은 맵리듀스 모델에 어울린다. 그러나 스파크는 오퍼레이션 간에서 영속적일 수 있는 RDD 상에서 동작한다. 

The need to extend MapReduce to support iterative jobs was also recognized by Twister [6, 12], a MapReduce framework that allows long-lived map tasks to keep static data in memory between jobs. However, Twister does not currently implement fault tolerance. Spark’s abstraction of resilient distributed datasets is both fault-tolerant and more general than iterative MapReduce. A Spark program can define multiple RDDs and alternate between running operations on them, whereas a Twister program has only one map function and one reduce function. This also makes Spark useful for interactive data analysis, where a user can define several datasets and then query them. 

반복적 잡 지원을 위한 맵리듀스 확장에 대한 요구는 Twister에서도 받아들여졌고, 오랜 시간 동작하는 맵 태스크가 정적 데이터를 잡들 사이에서 메모리에 유지할 수 있는 맵리듀스 프레임워크를 만들었다. 그러나 Twister는 현재 내고장성을 구현하지 않았다. 스파크의 TDD 추상화는 반복적인 맵리듀스보다 내고장성도 있고 더 일반화된 모델이다. 스파크 프로그램은 다수의 RDD를 정의할 수 있고 그 위에서 작동하는 오퍼레이션을 왔다 갔다 할 수 있는데 반해 Twister 프로그램은 오직 하나의 맵 함수와 하나의 리듀스 함수를 가진다. 이것은 스파크를 인터랙티브한 데이터 분석에 유용하게 만들어 주어 사용자가 여러 데이터셋을 정의하고 쿼리할 수 있게 해준다. 

Spark’s broadcast variables provide a similar facility to Hadoop’s distributed cache [2], which can disseminate a file to all nodes running a particular job. However, broadcast variables can be reused across parallel operations. 

스파크의 브로드캐스트 변수는 하둡의 분산 캐시와 비슷한 편의성을 제공한다. 그것은 모든 개개인의 잡이 실행중인 모든 노드에 파일을 퍼뜨린다. 그러나, 브로드캐스트 변수는 병렬 오퍼레이션 사이에서 재사용될 수 있다. 

Language Integration: Spark’s language integration is similar to that of DryadLINQ [25], which uses .NET’s support for language integrated queries to capture an expression tree defining a query and run it on a cluster. Unlike DryadLINQ, Spark allows RDDs to persist in memory across parallel operations. In addition, Spark enriches the language integration model by supporting shared variables (broadcast variables and accumulators), implemented using classes with custom serialized forms. 

언어 통합: 스파크의 언어 통합은 DryadLINQ와 비슷하다. DryadLINQ는 쿼리를 정의한 표현 트리를 캡쳐하고 클러스터 상에서 수행하기 위해서 언어 통합 쿼리를 위한 .NET의 지원을 사용한다. DryadLINQ와는 달리 스파크는 RDD가 병렬 오퍼레이션들에 걸쳐 메모리상에 영속되는 것을 허용한다. 게다가 스파크는 커스텀 직렬화 형식의 클래스를 사용해 구현된 공유 변수를 지원하여 언어 통합 모델의 내용을 풍부하게 한다. 

We were inspired to use Scala for language integration by SMR [14], a Scala interface for Hadoop that uses closures to define map and reduce tasks. Our contributions over SMR are shared variables and a more robust implementation of closure serialization (described in Section 4). 언

어 통합을 위해 스칼라를 사용하는것은 맵과 리듀스 태스크를 정의하는데 클로저를 사용하는 하둡을 위한 스칼라 인터페이스인 SMR에서 영감을 받았다. SMR를 위해 공유 변수와 클로저 직렬화의 더 강건한 구현을 기여했다. 

Finally, IPython [22] is a Python interpreter for scientists that lets users launch computations on a cluster using a fault-tolerant task queue interface or low-level message passing interface. Spark provides a similar interactive interface, but focuses on data-intensive computations. 

마지막으로 IPython은 과학자를 위한 파이썬 인터프리터이며, 사용자가 내고장성 태스크 큐 인터페이스나 저수준 메세지 패싱 인터페이스를 사용해 클러스터 상에서 계산을 실행하게 해준다. 

Lineage: Capturing lineage or provenance information for datasets has long been a research topic in the scientific computing an database fields, for applications such as explaining results, allowing them to be reproduced by others, and recomputing data if a bug is found in a workflow step or if a dataset is lost. We refer the reader to [7], [23] and [9] for surveys of this work. Spark provides a restricted parallel programming model where fine-grained lineage is inexpensive to capture, so that this information can be used to recompute lost dataset elements. 

계보: 데이터셋에 대한 계보 또는 출처 정보를 캡쳐하는 것은 과학적 컴퓨팅 데이터베이스 분야에서 오랜시간 연구해온 주제이다. 만약 워크플로우 단계에서 버그를 발견하거나, 데이터를 잃었을 경우, 결과를 설명하고, 다른것으로 부터 데이터를 재생산하게 해주고, 데이터를 다시 계산하는 그런 어플리케이션을 위해서이다. 이 연구에 대해서는 [7], [23], [9]를 참조하라. 스파크는 제한적 병렬 프로그래밍 모델을 제공한다. 잘 분절된 계보는 캡쳐하는데 비싸지 않아서 이 정보를 손실된 데이터셋 요소를 재계산하는데 사용할 수 있다. 

7. Discussion and Future Work

Spark provides three simple data abstractions for programming clusters: resilient distributed datasets (RDDs), and two restricted types of shared variables: broadcast variables and accumulators. While these abstractions are limited, we have found that they are powerful enough to express several applications that pose challenges for existing cluster computing frameworks, including iterative and interactive computations. Furthermore, we believe that the core idea behind RDDs, of a dataset handle that has enough information to (re)construct the dataset from data available in reliable storage, may prove useful in developing other abstractions for programming clusters. 

스파크는 클러스터 프로그래밍을 위해 세 가지 간단한 데이터 추상화를 제공한다. RDD와 두 개의 제한적 공유 변수 타입인 브로드캐스트 변수와 accumulator이다. 이 세 추상화는 제한적이지만 반복적이고 인터랙티브한 계산을 필요로 하는 기존의 클러스터 컴퓨팅 프레임워크에서는 어려움에 놓여있는 여러 애플리케이션을 표현하는데 충분히 강력하다는 것을 발견했다. 더불어, 신뢰성있는 스토리지의 사용 가능한 데이터로부터 데이터셋을 재구성하기 위한 충분한 정보를 가지는 데이터셋 기능이라는 RDD의 핵심 아이디어는 클러스터 프로그래밍을 위한 다른 추상화를 개발하는데 유용하다는 것을 입증한다고 생각한다. 

In future work, we plan to focus on four areas: 앞으로 네 영역에 집중할 계획이다.

Formally characterize the properties of RDDs and Spark’s other abstractions, and their suitability for various classes of applications and workloads. RDD의 속성과 스파크의 다른 추상화 그리고 다양한 분야의 애플리케이션이나 작업에 대한 적용성을 정식으로 특징짓기
Enhance the RDD abstraction to allow programmers to trade between storage cost and re-construction cost. 프로그래머가 스토리지 비용과 재구성 비용 간의 트레이드오프를 선택할 수 있도록 RDD 추상화를 개선하기
Define new operations to transform RDDs, including a “shuffle” operation that repartitions an RDD by a given key. Such an operation would allow us to implement group-bys and joins. 주어진 key로 RDD를 재분배하는 shuffle 오퍼레이션을 포함하여, RDD를 변환하는 새 오퍼레이션 정의하기. 이러한 오퍼레이션은 group-by나 join을 구현할 수 있게 해준다. 
Provide higher-level interactive interfaces on top of the Spark interpreter, such as SQL and R [4] shells. 스파크 인터프리터 위에 SQL이나 R shell 같은 더욱 고수준의 인터랙티브 인터페이스를 제공