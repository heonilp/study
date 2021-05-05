## 11. 프로세스 동기화: Chapter 6. Synchronization Tools (Part 1)

- Cooperating processes : 공유하는 메모리, 논리적 주소공간(스레드)을 세어할수 있다

- concurrent access to shared data , 동시에 실행 순서 대로 보장해줘야 데이터 동시성이 유지 될수있다.

- count 값이 동기화를 안하면 문제가 일어날수 있다.

- Race Condtition : 레이스 컨디션  경쟁상황(중요)

- 두개 이상의 프로세스(스레드)가 데이터를 공유하고 있을때 동시적으로 접근할떄

- 결과는 어떤 순서대로 일어나는지에 따라 달라질수가있음

- 프로세스(스레드) 동기화는 억세스하는 부분을 순차적으로 접근하게 만들어보자.

- 크리티컬 섹션 문제 

- 하나의 프로세스가 크리티컬 섹션에 접근할때 다른쪽에서 접근못하게하자.

1. 상호배제(Mutual exclusion) : 프로세스들이 필요로 하는 자원에 대해 배타적인 통제권을 요구한다.

2. 점유대기(Hold and wait) : 프로세스가 할당된 자원을 가진 상태에서 다른 자원을 기다린다.

3. 비선점(No preemption) : 프로세스가 어떤 자원의 사용을 끝낼 때까지 그 자원을 뺏을 수 없다.

4. 순환대기(Circular wait) : 각 프로세스는 순환적으로 다음 프로세스가 요구하는 자원을 가지고 있다.


## 12. 동기화 문제의 해결책: Chapter 6. Synchronization Tools (Part 2)

- Bakery 알고리즘(베이커리 알아서 찾아보기)

- Peterson's 알고리즘 / 임계구역 해결 , 제대로 동작할 겔런티가없음, load and store에서 발생한문제, 기계어 구조로 생각하면 해결할수가 없음. 상호배제, 데드락이 걸리지않는다. 기아도 발생하지않는다.

- 원자성, Atomicity

- and atomic operation is one uninterruptible unit of operation.

- lock , 글로벌변수 0 bool

- Atomic variable : count++ <->count-- single variable with race condition

- 동기화 : 1.상호배제, 2.progress(데드락) 3. bounded waiting (기아, 한정적 대기)

## 13. 뮤텍스와 세마포어: Chapter 6. Synchronization Tools (Part 3)

- higher-level software tools to solve the CSP

- 뮤텍스락 : the simplest tools for 동기화, pthread에 포함

- 세마포어 : more robust, convenient and effective tool

- 모니터 : overcoms the demerts of 뮤텍스 or 세마포어 / wait , notify

- Liveness :ensures for processes to make progress

- 뮤텍스락 : mutex mutal exclustion , race confition 예방, Lock(열쇠)를 들어갈때 획득 , 나올때 반납, acquire(), release(), atomically 하게 실행

- 뮤텍스의 단점 :Busy waiting acquire를 하기위해서 무한루프를 돌아야함

- 스핀락 : the type of mutex lock using the method of busy waiting

- 하지만 계속 도는 스핀락도 장점이 있음, cpu 코어가 많으면 장점이됨, context switch하는 것에 대한 장점

- 세마포어 : 신호장치, 신호기, n개짜리 프로세스, two standard atomic operations.

- wait(), signal() or P() and V() , atomic 하게 구현해야함

- 바이러니 세마포어 : 0, 1로 바꿈 - 뮤텍스렉이랑 똑같음

- 카운팅 세마포어 : a finite number of instances.

- wait() : 감소 count, signal, 증가 cnout , 0인상태는 모든 프로세스가 사용되기 때문에 블락, waiting queue, ready queue , wakeup ? - busy wating 극복?


## 14. 모니터와 자바 동기화: Chapter 6. Synchronization Tools (Part 4)

- 모니터 : as high-level language constructs

- 세마포어나 뮤텍스는 timing error, 프로그래밍에러 발생, wait, signal 문제

- 모니터 타입 : synchronized , ADT 클래스?, condition 타입을 넣음

- sysnchroized keyword : 임계영역 해당하는 코드블록을 선언을 할때 사용하는 자바 키워드, 해당 코드 블록에는 모니터락을 획득해야 진입가능, 모니터락을 가진 객체 인스턴스를 지정할 수 있음

- wait()-> P() notify ->V() 스레드가 어떤객체 wait() 메소드를 호출하면 해당 객체의 모니터락을 호기득하기 위해서 대기상태로 진입함, 스레드가 어떤 객체의 notify() 메소를 호출하면 해당객체 모니터에 대기중인 스레드 하나를 깨움, notify() 대신에 notifyAll() 호출하면 모니터에 대기중인 스레드를 모두깨움.

- Liveness - progress, bounded waiting 고칠려고함

- 데드락 : 두개이상의 프로세스가 기다려야할때 

- priority Inversion : priority-ingeritance protocol.



