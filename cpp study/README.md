
# C++ 면접 공부, 모던 공부

- 현재 C++ 모던 어디까지 나왔는지 한번 정리해보기
- 이펙티브 C++ 공부하기
- [More C++ Idioms](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms) 공부하기



## C/ C++ 실행 방식, 소스 파일, 컴파일, 링크 ,링커, 실행파일

1. 소스 파일(source file)의 작성

2. 선행처리기(preprocessor)에 의한 선행처리

3. 컴파일러(compiler)에 의한 컴파일

4. 링커(linker)에 의한 링크

5. 실행 파일(executable file)의 생성

# 업캐스팅, 다운캐스팅

```
자식클래스는 부모클래스의 모든 특성을 받습니다.
업캐스팅은 자식클래스의 객체가 부모클래스로 형변환하는걸 말하는데
부모형 클래스로 변환하면 그 이후에 자식클래스의 특성을 쓰면 컴파일 타임 오류납니다.

다운캐스팅은 자신의 고유 특성을 잃은 자식 클래스를 다시 원상태로 복구해주는겁니다.
업캐스팅된 것을 다시 돌려주는 겁니다.

즉, 다운캐스팅은 업캐스팅 된것을 다운캐스팅하여서 다시 자식클래스의 성질로 돌려주는겁니다.

1. 업캐스팅 먼저 선행
2.  다운캐스팅

* 바로 부모클래스의 객체를 자식클래스로 그냥 형변환할 경우는
 컴파일 시점에 오류가 발생하지않아도 런타임 오류를발생합니다. 
즉, 바로 다운캐스팅하는 경우는 오류를 발생하기때문에 쓰지않습니다.
```

##  C++ 캐스팅 4가지 설명

- 여기가 엄청 정리가 잘되있어서 [참고](https://ju3un.github.io/c++-type-casting/) 하였습니다.
- static_cast, reinterpret_cast, const_cast, dynamic_cast 캐스팅 4종류에 정리.

``` C++
int i = 0;
char ch1 = i;       // 묵시적 형 변환(Implicit Cast)
char ch2 = (char)i; // 명시적 형 변환(Explicit Cast)
```

1. static_cast

- 가장 보편적으로 사용되는, 논리적으로 변환 가능한 타입을 변환하는 연산자
- 컴파일(Compile) 시점에 발생
- 묵시적 형 변환(Implicit Cast)과 같은 맥락

- Q. 묵시적 형 변환은 문법적인 키워드가 존재하지 않는데, static_cast이 묵시적 형 변환과 같은 의미라니?
 * 컴파일러가 값을 변환하기 위해 기계어 코드를 만들어 내는 컴파일 시점에 형 변환이 일어나는 관점 에서 같은 맥락

- Q. 그렇다면 static_cast(정적 캐스팅)과 묵시적 형 변환과의 차이는?
```
"상속 관계에 있는 포인터끼리 변환이 가능하다"는 점이다.
그러나, 다운캐스트(Downcast)의 경우 Unsafe 하다. (Unsafe Downcasting)
```
- cf. new_type으로 void* 형이 올 수 있지만 return 값이 없다.


2. reinterpret_cast

- 임의의 포인터끼리 변환 허용 (연관성이 없는 포인터 타입의 형 변환 가능) (static_cast와의 차이점)
- 강제 형 변환으로 문법적으로 변환을 허용하는 것이지, 논리적으로 안전한 타입 연산자는 아님
- expression에 해당하는 것을 new_type으로 비트 단위로 강제 형 변환
- ex) 주로 정수형 -> 포인터 또는 포인터 -> 정수형 변환하는 작업에 주로 사용함

3. const_cast

- 포인터 타입, 참조형에 대해서만 사용되며 동일한 타입에 대해서만 허용함
- const 속성이나 volatile 속성을 잠깐 제거할 때 사용

4. dynamic_cast

- RTTI(Runtime Type Information)
```
C++ 컴파일러 내에 포함되어 있는 기능으로, 객체의 유형을 실행 시에 결정할 수 있도록 허용하는 것을 의미한다.
다른 말로는 실행 중에 타입의 정보를 가지고 온다는 의미로 표현할 수도 있다.

메모리 상주 객체에 유형 정보를 추가하여, 실행 시스템은 객체의 캐스트(=형 변환)가 유효한 지 여부를 확실히 하기 위해 특정 객체의 유형을 결정할 수 있다.

RTTI는 객체를 동적으로 변화시킬 수 있는 Polymorphism 능력이라고 이해하면 된다.
타입 캐스팅에서 이 용어를 다룬 이유는, 바로 dynamic_cast 연산자가 이 요소 중 하나이기 때문이다.
```

- 주로 다운 캐스팅으로 사용되는 연산자 (부모 클래스 포인터에서 -> 자식 클래스 포인터로 다운캐스팅)
- 다른 캐스트와 달리 런타임 시간에 다운 캐스팅이 가능한지 능동적으로 판단하기 때문에 런타임 비용이 높음.-
- 형 변환 성공 시 : 변환된 값 return
- 형 변환 실패 시 : 널 포인터(null pointer) 또는 예외(Exception) return


##  객체지향(OOP) 특징 말하고 가상함수에 대해서 설명해보아라. (소멸자와 관련되어서 설명)

- C++ OOP
1. Class 클래스
2. Object 객체
3. Abstraction 추상화
4. Encapsulation 캡슐화
5. Inheritance 상속
6. Polymorphism 다형성

- 가상함수

- 순수 가상 함수는 인터페이스(Interface)를 자식 클래스에게 전달하기 위해 사용하는 함수입니다.

- 일반(단순) 가상 함수는 인터페이스(Interface) + 함수의 선언(내부 구현) 까지 자식 클래스에게 전달하기 위해 사용하는 함수입니다.

- C++ 가상 함수 (virtual) - 가상 소멸자

- 가상 소멸자(중요)
```
클래스에 가상 함수를 정의할 때 주의할 점은 소멸자도 가상함수로 만들어야 한다는 점입니다.
동적으로 생성한 자식 클래스 객체를 부모 클래스 포인터로 가리키고 있을 때 동적으로 생성한 객체를 해제하려면 기본 클래스 포인터로부터 delete 해야 합니다.
```

## 스마트 포인터 3가지 종류와 왜 각각 쓰는지 설명

- 스마트 포인터(Smart Pointer)
1. RAII(Resource Acquisition Is Initialization) 원칙
```
안전하게 자원을 사용하기 위한, C++에서 자주 쓰는 패턴
객체가 사용되는 스코프(범위)를 벗어나면, 자원을 해제해주는 기법
ex. 함수 내의 지역변수(stack에 할당된 메모리)는 그 함수가 끝나는 시점에서 메모리가 해제되는 원리
```

2. 자원 관리 객체
```
자원을 획득한 후 자원 관리 객체, 즉 스마트 포인터(Smart Pointer)에 넘겨준다.
자원 관리 객체는 자신의 소멸자(스마트 포인터의 소멸자에 존재하는 delete 연산자)를 이용해서 자원을 해제한다.
포인터처럼 동작하는 클래스 템플릿으로, 사용이 끝난 메모리를 자동으로 해제해 준다.
기존 포인터 타입에서 자원 관리 기능(메모리 자원 관리, 경계 검사 등)이 추가된 추상 데이터 타입
원본 삭제 및 참조 카운트(Reference Count)를 이용해 댕글링 포인터(Dangling Pointer)가 되는 것을 막는다.
(cf. Dangling Pointer : 해제된 동적 메모리 영역을 가리키고 있는 포인터 / stack에서 사라진 메모리를 가리키는 포인터)
```

1. unique_ptr

- 복사X, 이동만 가능(복사 생성자, 복사 대입 연산자 구현되어 있지 않음)
- 소유권 독점 방식 사용(소유권 이전 시 std::move() 사용)
- 해당 객체의 소유권을 가지고 있을 때만, 소멸자가 해당 객체를 삭제할 수 있음
- C++14 이후 makeunique() 함수를 사용하여 uniqueptr 객체를 안전하게 생성할 수 있음

2.  shared_ptr
- 참조 카운팅 방식 스마트 포인터(Reference Counting Smart Pointer)
- 소유권이 아닌 공유 방식 사용
- 참조 카운트가 0이 될 때만, 해당 객체가 자동으로 삭제됨
- class 클래스명: public std::enable_shared_from_this<클래스명> 선언

3. weak_ptr ( 왜 쓰는 가 ?? )
- shared_ptr와 함께 사용할 수 있는 스마트 포인터
- shared_ptr의 문제점(상호 참조로 인해 객체가 삭제되지 않는 상황)을 보완하기 위해 사용되는 특수 포인터
- sharedptr을 weakptr로 참조 시, 참조 카운트에 포함되지 않음
- 포인터에 대한 직접적인 접근이 불가능함

4. weak_ptr 나온 이유 - 순환참조 방지!
``` C++
- 캐싱, 관찰자 목록, std::shared_ptr 순환 고리 방지.
 shared_ptr 를 구현하면서 참조 카운트에 영향을 받지 않는 스마트 포인터가 필요했는데
 weak_ptr 을 사용하면 shared_ptr 가 관리하는 자원(메모리)을 참조카운트에 영향을 미치지 않으면서 참조 타입으로
 가질 수 있습니다.
 할당 받은 자원을 사용하려면 lock이라는 멤버 함수를 통해서 사용할 수 있습니다. 
 (lock이 성공하면 shared_ptr 객체를 리턴해서 사용 할 수 있습니다.) 

_Construct_from_weak 함수의 구현을 확인해보면 weak_ptr의 control block를 존재하는지 검사 한 후

 lock을 통해서 리턴하는 shared_ptr을 위해서 참조 카운트를 증가 시킵니다.

 내부적으로 이렇게 설계되어 있기 때문에 lock으로 리턴 받은 shared_ptr을 사용 도중에 객체 자원이

 참조카운트가 0이 되는 것을 방지하여 객체가 무효화하는 것을 방지합니다.
 
 weak_ptr을 사용하는 이유
 shared_ptr을 우회적으로 사용하도록 구성되어 있다면 직접적으로 shared_ptr을 사용하지 않고
 왜 weak_ptr을 사용해야 할까요?
 그 이유는 shared_ptr만으로는 완전한 스마트 포인터의 기능을 제공하지 못하기 때문입니다. 
 대표적으로 circular reference(순환 참조) 문제가 있습니다. 

  이렇게 순환 참조를 방지하기 위해서 weak_ptr을 사용합니다.
  m_partner를 weak_ptr로 설계하면 참조 카운트에 영향을 미치지 않기 때문에 순환 참조의 문제가 해결 됩니다. 

 이렇게 shared_ptr의 참조 카운트에 영향을 미치지 않아야 하는 상황이 나온다면 weak_ptr을 고려해야 합니다.

 하지만 위에서도 설명 드렸듯이 꼭 필요한 경우가 아니라면 shared_ptr로 구현해야합니다.

 (weak_ptr 사용시 lock()함수 호출로 인한 비용 증가)

Concurrency Issues

레퍼런스 카운팅 방식이므로 멀티 쓰레드 코드에서도 shared_ptr 과 weak_ptr을 안전하게 사용할 수 있습니다. 안전하게 사용할 수 있는 경우란, 단, 각 쓰레드가 자기 내부적으로 각각 shared_ptr 이 있고 이 shared_ptr이 동일한 리소스(18번지) 에 접근하는 경우를 말하는 겁니다. 

하지만, 만약 각 쓰레드가 쓰레드 외부의 하나의 shared_ptr 객체에 접근하는 경우에는 C++11이 제공하는 다른 atomic function 들을 사용해야 합니다.

```

- 정리

shared_ptr, Memory leak

unique_ptr -> exclusive ownership 다른곳에서 참조를 못함, move으로는 가능
shared_ptr -> shared ownership

ref count -RAII

shared_ptr-> 개발자가 실수 할 수있다. 순환이 일어나면 메모리릭이 날수있다.
ex)자기자신을 넣어주면 메모리릭이 일어난다.
shared_ptr를 서로 넣어주면 메모리릭이 일어난다 -> 소멸자가 호출이안됨. 
GC- make and sweep 이 없음
valgrind -> 메모리릭 탐지 
use_count()로 ref count를 볼수 있음

weak_ptr -> 메모리릭 ,ref count에는 관련없음
lock 으로 확인 , use_count 0보다클떄 , exprired -> false 일때 확인
라이프 사이클- weak_ptr사용 - 메모리릭을 막아줌

##  오버로딩과 오버라이딩 차이

- 오버로딩(Overloading) - 함수 중복 정의

- 오버로딩은 같은 이름의 함수에 매개변수를 다르게 사용하여 매개 변수에 따라 다른 함수가 실행되는 것.

- 오버라이딩(Overriding) - 함수 재정의

- 오버라이딩은 상속받았을때 부모클래스의 함수를 사용하지 않고 다른 기능을 실행할때 함수를 자식클래스에 같은 이름, 매개변수로 재정의 해서 사용하는 것.


## call by value call by reference 차이
- 함수의 호출은 두 가지 있다.

- Call by value(값에 의한 호출)
- Call by reference(참조에 의한 호출)


- Call by value(값에 의한 호출)
```
장점 : 복사하여 처리하기 때문에 안전하다. 원래의 값이 보존이 된다.
단점 : 복사를 하기 때문에 메모리가 사용량이 늘어난다.
```
``` C++
#include <stdio.h>
 
void swap(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void main()
{
    int a = 20, b = 60;
    swap(a, b);
    printf("a: %d, b: %d", a, b); // 20 ,60이 나온다.
}
```


- Call by reference(참조에 의한 호출)
```
장점 : 복사하지 않고 직접 참조를 하기에 빠르다.
단점 : 직접 참조를 하기에 원래 값이 영향을 받는다.(리스크)
```


``` C++
#include <stdio.h>
 
void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void main()
{
    int a = 20, b = 60;
    swap(a, b);
    printf("a: %d, b: %d", a, b); //60, 20바뀐다.
}
```

##  스택과 힙의 차이

- [참조](https://boycoding.tistory.com/235) 하였습니다.

- 스택과 힙 (Stack and Heap) :프로그램이 사용하는 메모리는 일반적으로 세그먼트(segment)라고 하는 몇 가지 다른 영역으로 나뉜다.

- 코드 세그먼트 : 컴파일된 프로그램이 저장되는 영역, 일반적으로 read-only 속성이다.

- 데이터 세그먼트 : 전역 변수 및 정적 변수가 저장되는 영역

- 힙 세그먼트 : 동적으로 할당된 변수가 할당되는 영역

- 스택 세그먼트 : 함수 매개 변수, 지역 변수 및 기타 함수 관련 정보가 저장되는 영역


-힙 세그먼트 (Heap segment)
```
힙 세그먼트는 동적 메모리 할당에 사용되는 메모리를 추적한다.
C++에서 new 연산자를 사용해서 메모리를 할당하면 이 메모리는 응용 프로그램의 힙 세그먼트에 할당된다.
```

- 힙의 특징
```
힙에 메모리를 할당하는 것은 비교적 느리다.
할당된 메모리는 명시적으로 할당 해제하거나 응용 프로그램이 종료될 때까지 유지된다. (메모리 릭 주의)
동적으로 할당된 메모리는 포인터를 통해 접근한다: 포인터를 역참조하는 것은 변수에 직접 접근하는 것보다 느리다.
힙은 큰 메모리 풀이므로 큰 배열, 구조체 또는 클래스를 할당할 수 있다
```

- 스택 세그먼트 (Stack segment)
```
스택 세그먼트(=콜 스택)는 메인() 함수부터 현재 실행 지점까지의 모든 활성 함수를 추적하고 모든 함수 매개 변수와 지역 변수의 할당을 처리한다.

스택은 후입선출(LIFO) 자료구조다. 즉, 가장 늦게 들어간 자료를 가장 먼저 꺼내게 된다.
 함수 호출이 끝나고, 이전 함수로 돌아갈 때 이 함수의 바로 이전 함수로 돌아가야 한다. 
 그래서 컴퓨터는 내부적으로 스택 세그먼트를 스택 자료구조로 구현한다.
```

-스택의 특징
```
스택에 메모리를 할당하는 것은 비교적 빠르다.
스택에 할당된 메모리는 스택 범위에 있을 때만 접근할 수 있다.
스택에 할당된 모든 메모리는 컴파일 타임에 알려진다. 메모리는 변수를 통해 직접 접근할 수 있다.
스택은 비교적 크기가 작으므로 스택 공간을 많이 차지하는 지역 변수를 만드는 것은 좋지 않다.
```


출처: https://boycoding.tistory.com/235 [소년코딩]


## 벡터(배열)과 리스트 차이

 - ( 중요 왜 쓸까? )

- 벡터(배열)의 특징 : 같은 자료형을 가진 변수를 하나로 나타낸것
- 연속된 메모리 공간으로 이루어짐, 인덱스와 정적표현, 지역성을 가지고 있다.
- 배열의 장점 : 인덱스를 통해 검색이 용이, 연속적이므로 메모리(캐싱이 된다.)

- 배열의 단점 : 데이터를 삭제하더라도 배열은 연속해야되므로 공간이 남음, 메모리 낭비,
- 정적이므로 배열의 크기를 컴파일 이전에 정해주어야한다. 또한, 컴파일 이후 배열의 크기를 변동 할 수 없다. 
- 리스트의 특징 : 순서가 있는 데이터의 집합, 불연속적으로 메모리 공간 차지, 동적 표현, 포인터를 통한 접근

- 리스트의 장점 : 포인터를 통해서 다음 데이터의 위치를 가리키고 있어 삽입, 삭제가 용이하다. 
- 동적이므로 크기가 정해져있지않다, 메모리 재사용 편리하다, 불연속적이므로 메모리 관리의 편리

- 리스트의 단점 : 검색성능이 좋지않다. 포인터를 통해 다음 데이터를 가리키므로 추가적인 메모리 공간 발생, 캐싱미스가 난다.

```
즉, 리스트 와 배열 차이점을 큰 차이점을 말하자면 다음과 같다.
배열은 List와 다르게 크기를 지정해야한다.
객체를 일반 배열에 넣을 때는 인덱스를 지정해야한다.
배열의 내부값을 이용할 때는 index 문법을 이용해야한다.
```

-정리
- 배열 : 데이터 크기가 정해져있고, 추가적인 삽입, 삭제가 일어나지않으며 검색을 필요할 때 유리
- 리스트: 데이터의 크기가 정해져있지않고, 삽입, 삭제가 많이 일어나며, 검색이 적은 경우 유리


## new 와 malloc 차이

- 역시 가장 큰 차이점은 new연산자는 생성자/소멸자가 호출된다는 점

-차이점은 읽어보고 이해하고 외울 것!
``` c++
 1. malloc/free 는 라이브러리가 제공하는 함수인데 비해 new/delete 는 언어가 제공하는 연산자이다. 
 그래서 별도의 헤더 파일을 포함할 필요없이 언제든지 사용할 수 있으며 이 연산자를 쓴다고 해서 프로그램이 커지는 것도 아니다.
연산자이기 때문에 사용자 정의 타입에 대해 오버로딩할 수도 있다.
 
2. malloc 함수는 필요한 메모리양을 바이트 단위로 지정하고 void *를 리턴하므로 sizeof 연산자와 캐스트 연산자의 도움을 받아야 한다. 
이에 비해 new는 할당할 타입을 지정하고 해당 타입의 포인터를 리턴하므로 sizeof 연산자와 캐스트 연산자를 쓸 필요가 없다.
할당한 타입과 같은 타입의 포인터 변수로 대입만 받으면 된다.
 

3. malloc은 메모리를 할당하는 것만이 목적이므로 초기값을 줄 수 없지만
 new 연산자는 동적으로 생성한 변수의 초기값을 지정할 수 있다
 즉 할당과 동시에 초기화를 할 수 있는데 할당 타입 다음의 괄호에 초기값을 적어 주면 된다.
 int *pi=new int; *pi=123; 두 문장은 int *pi=new int(123); 하나로 합칠 수 있다.
 

4. new 연산자로 객체를 할당할 때 생성자가 자동으로 호출된다. 
생성자란 객체를 자동으로 초기화하는 특별한 함수인데 다음 장에서 배우게 될 것이다.
생성자는 생성과 동시에 객체를 초기화할 수 있도록 함으로써 클래스가 기존 타입과 동등한 자격을 가지도록 하는 중요한 역할을 한다
생성자를 호출한다는 점이 malloc 과 new 의 가장 큰 차이점이며 C++에서 별도의 할당 연산자가 추가된 이유이다.
마찬가지로 delete 로 객체를 삭제할 때는 파괴자라는 특별한 함수가 자동으로 호출된다. 

5. malloc/free 함수로 할당한 메모리는 realloc 으로 크기를 바꿔 재할당 할수 있지만 
new에는 이에 대응하는 기능이 없어 새로 할당하여 복사하고 원래 메모리를 해제하는 과정을 직접 해야 한다.
그래서 재할당할 때마다 매번 번지가 바뀌며 심지어 축소할 때도 번지가 바뀐다. 
또한 실행중에 할당 블록의 크기를 조사하는 _msize에 해당하는 기능도 없다. 
할당 대상이 객체가 아니고 재할당을 빈번하게 한다면 malloc/free 를 사용할 수도 있고 객체를 할당할 때는 
반드시 new/delete 를 써야 한다. 단, 할당, 해제 함수는 반드시 짝을 맞추어야 하며 섞어서 쓸 수는 없다. 
new로 할당한 메모리는 반드시 delete로 해제해야 하고 malloc 으로 할당한 메모리는 free로 해제한다.

```

## STL의 맵과 일반 해쉬 맵의 차이가 뭔가요?

 - C++ STL 자료구조 특징
 - map, set : 삽입, 삭제, 탐색 모두 O(log n) 보장
 - list : 삽입, 삭제 O(1), 탐색, 임의 원소 접근 O(n) 보장
 - vector : 삽입, 삭제, 탐색 O(n), 임의 원소 접근 O(1) 보장

- Hash Map
- 자료 탐색에 Hashing 사용
- 탐색 속도 O(1) 이상 : Key값 분포에 따라 다름
- 저장된 내부 자료 정렬하지 않음

- Map 
- 자료 탐색에 이진 탐색 트리 사용 (최근엔 Red-Black Tree)
- 저장된 내부 자료 정렬, O(logN)


알고리즘의 차이로 데이터가 N 개일 때 map 은 O(logN)의 탐색 속도를, unordered_map은 O(1)의 탐색 속도를 각각 갖음. 

## C++ template 관련 질문 (중요)

- 언제 써봤는지??

- 함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료 형으로 사용할 수 있도록 하게 만들어 놓은 틀.
- 함수 템플릿(Function Template)와 클래스 템플릿(Class Template) 로 나누어집니다.

- 템플릿 특수화 (template specialization)
- template <typename T> / template <class T> 로 쓴다. ,template를 선언할 때 <typename T>,<class T> 둘다 사용 가능합니다.
- 템플릿(template)을 사용할때, 특수한 자료형에 대해서는 다른 처리를 하고 싶을때 사용합니다.


- 함수 템플릿(Function Template), 오버로딩 예시
- 클래스 내부의 멤버 변수의 타입에 대해서 template 로 선언 할 때 사용한다.
- 선언시에 유의할 점 : 멤버 함수를 클래스 외부에서 선언 할때, 꼭 template 선언을 다시 해주어야한다.
- 클래스 템플릿은 객체를 생성할때 타입을 정해준다.

``` C++
#include<iostream>
#include<string>
 
using namespace std;
 
template <typename T> //템플릿 스타일
T sum(T a, T b){
    return a + b;
}
 
int main(void) {
    int a=1, b =2;
    
    double d1 = 2.2;
    double d2 = 3.3;
 
    string s1 = "Show me ";
    string s2 = "The Money 6";
    
    cout << "int 합 : " << sum<int>(a, b) << endl;
    cout << "double 합 : " << sum<double>(d1, d2) << endl;
    cout << "string 합 : " << sum<string>(s1, s2) << endl;
    
    return 0;
}

```

-  클래스 템플릿 (class template)


``` C++
#include <iostream>
#include <string>
 
using namespace std;
 
template <class T>
class Person{
private:
    string name;
    T height;
public:
    Person(string name, T height):name(name), height(height){}
 
    void printAll(){
        cout << "name : " << name << endl;
        cout << "number : " << height << endl;
    };
 
    void setName(string name){
        this->name = name;
    }
    void setNumber(T height){
        this->height = height;
    }
};
 
 
int main() {
//객체를 선언할때 <> 안에 template 의 타입을 넣는다.
    Person<int> p1("Mr. Dev C++", 173);
    Person<string> p2("Ms. Unix", "155cm");
 
    p1.printAll();
    p2.printAll();
    cout << endl;
    p1.setNumber(188);
    p2.setNumber("2m 10cm");
    cout << endl;
    p1.printAll();
    p2.printAll();
    return 0;
}


```
##  move ,forward 그리고 R-value vs L-value 차이

- rvalue reference vs universal reference(보편 참조)
```
 c++에서 참조는 &와 &&으로 표현됩니다. &는 lvalue 참조를 의미합니다.

 &&은 문맥에 따라서 rvalue 참조 또는 universal(보편) 참조를 의미합니다. (마치 한글의 동음이의어와 같습니다.)

 rvalue 참조는 쉽게 이해가 되지만 universal(보편) 참조가 의미하는 내용은 무엇일까요?

 universal(보편) 참조는 rvalue 참조 또는 lvalue 참조 둘 다 될 수 있다는 것을 의미합니다. 
```

-  일반적으로 rvalue 참조에는 std::move를 사용하고 universal(보편) 참조는 std::forward를 통해서 전달합니다.
``` C++
// rvalue 참조
void f(Person&& obj) 

// rvalue 참조
Person&& p1 = Person("ahn", 1985); 

// universal 참조
// var1는 auto로 명시적이지 않습니다.
auto && var1 = var2		

// rvalue 참조
// param은 std::vector로 명시적이고 vector 내부 객체가 T만 연역
template<typename T>
void tf(std::vector<T>&& param);

// universal 참조
// param은 T로 명시적이지 않습니다.
template<typename T>
void tf2(T&& param)
```

- std::move
``` C++
 std::move는 전달된 파라미터를 강제로 rvalue 참조로 캐스팅하여 리턴하는 함수입니다. 

 내부를 살펴보면 간단히 구현되어 있습니다. 캐스팅만 수행하고 어떠한 작업도 하지 않습니다. 

예제 코드를 보면 p1이라는 lvalue를 std::move를 통해서 rvalue로 변환 후 이동 생성자를 통해서 p2를 생성합니다. 

 std::move를 보면 모든 값을 rvalue로 캐스팅 할 수 있을 것 같지만 rvalue로 변환될 수 없는 대상도 있습니다. 

 const Person p1("ahn", 1985);
    
// const Person인 p1을 std::move를 통해서 캐스팅합니다. 
// 하지만 const Person&&으로 변환되고 const가 붙어서 이동 생성자가 채택되지 못하고
// p2는 복사 생성자로 생성됩니다.
 Person p2= std::move(p1);

p1의 데이터형을 const Person으로 변환해서 std::move를 실행하면 다른 결과를 확인 할 수 있습니다. 

 p1은 std::move를 통해서 const Person &&로 캐스팅 됩니다. Person 내부에서 생성자를 선택할 때 const 때문에

 이동 생성자가 채택되지 못하고 복사 생성자를 채택되고 p2는 복사생성자를 통해서 생성됩니다.

 이것은 코드를 작성자의 의도와는 다르게 동작할 가능성이 높습니다.(std::move를 사용한다는건 이동 연산 선호)

 이동을 수행 할 객체는 const로 선언하지 말아야 합니다.

```

- std::forward

``` C++
 이 함수도 std::move처럼 캐스팅만 수행합니다. std::move와는 다르게 조건에 따라서 다른 값을 리턴합니다. 

 입력 값이  lvalue 참조가 아니라면 rvalue 참조(이동연산지원)를 리턴하고

 lvalue 참조라면 수정하지 않고 그대로 리턴합니다. 


 // lvalue를 캐치하는 함수
void Catch(Person& p, const char* name)
{
    cout << name << "lvalue catch" << endl;
}

// rvalue를 캐치하는 함수
void Catch(Person&& p, const char * name)
{
    cout << name << "rvalue catch" << endl;
}

// 전달받은 obj를 std::forward를 통해서 catch 함수로 전달합니다.
template<typename T>
void ForwardingObj(T&& obj, const char* name)
{
    Catch(std::forward<T>(obj), name);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Person p1("ahn", 1985);
    ForwardingObj(p1, "p1\t\t=\t");
    ForwardingObj(std::move(p1), "std::move(p1)\t=\t");

    return 0;
}
 
 ```

 

## 모던 C++ 람다함수, SFINAE, constexpr

- SFINAE: Substitution Failure Is Not An Error (치환 실패는 에러가 아님)

- 한마디로, 여기에서의 치환은 C++ 컴파일 과정에서의 타입 치환을 뜻한다.
- 컴파일 과정에서의 타입 치환이 이루어지는 부분은 바로 템플릿이다!

``` C++
template <bool,typename T =void>
struct enable_if
{};
 
template <typename T>
struct enable_if<true, T>
{
  typedef T type;
};

```
- 의도적으로 enable_if를 true인 경우에 대해서만 템플릿 특수화를 하고 있다.
- 즉, 타입 T를 치환 실패하면 컴파일이 진행되지 않도록 하는 장치로서의 역할을 할 수 있는 것이다.


- constexpr

1. 변수에서의 사용
- const와 constexpr의 주요 차이점은 const 변수의 초기화를 런타임까지 지연시킬 수 있는 반면, constexpr 변수는 반드시 컴파일 타임에 초기화가 되어 있어야 한다.

2. 함수에서 사용

- constexpr 함수는 컴파일러에게 가능하다면, 상수시간에 컴파일해 달라고 요청하는 것이지만 상황에 따라 컴파일 타임에 미리 실행될 수도 있고, 그렇지 못하고 런타임에 실행될 수도 있다.

3. 생성자 함수에서 사용
- 어떤 클래스로부터 상속받지 않아야 한다/


- 람다함수 (※Lambda는 기본적으로 캡쳐 블록'[]', 전달인자 '()', return type을 생략할 수 있습니다.)

1. [] 캡쳐 블록 (사용시 외부 변수를 캡쳐해 람다 몸통에서 사용 가능)
2. () 전달 인자
3. -> 반환 타입
4. {} 함수 몸통


##  최신 모던 C++ 알고 있는가?

( 매우 중요 추가 할 것 )
- N사에서 질문을 받은 것이므로 추가 예정입니다.
- [ISOCPP](https://isocpp.org/)
- [마이크로소프트 모던 C++ 시작하기](https://docs.microsoft.com/ko-kr/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-160)
- [C++ 나무위키](https://namu.wiki/w/C%2B%2B) 참조


- std::any

- std::std::variant

- std::string_view

- std::optional

## 퀵소트 설명, 코드 짜보기 O(nlogn), 최악 O(n^2)

- 해당 사이트 [참조](https://blockdmask.tistory.com/177) 하였습니다.

- 퀵 정렬은 기준점(pivot)을 정하고 앞(left)와 뒤(right)를 비교하면서 정렬을 하는 알고리즘입니다.

* 과정
 * 리스트에서 임의의 원소를 고릅니다. 그것을 pivot이라 합니다. (일반적으로 가운데 원소를 고릅니다.)
 * pivot의 앞에는 pivot 보다 작은 원소들로, pivot의 뒤에는 pivot 보다 큰 원소들이 오도록 교환해 줍니다. (divided)
 * divided 된 두 개의 작은 리스트에 대해 Recursive 하게 위의 과정을 반복합니다.
 * Recursive의 종료조건은 리스트의 크기가 0 입니다.


- 장점: 수행속도가 빠른 정렬 알고리즘이다.

- 단점: 중심값이 같을 경우에는 배열의 순서가 파괴 될 수도 있으며 안정성이 없다는 점이다. 


``` c++

//퀵소트 
 
#include<iostream>
using namespace std;
 
void swap(int *arr,int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
 
void QuickSort(int *arr, int start, int end)
{
    int pivot = arr[start];
    int left = start+1;
    int right = end;
 
    while(left <= right)
    {
 
        while(arr[left] < pivot){ left++; } //pivot보다 작은 경우는 건너뛰고 크거나 같은경우 멈춤
        while(arr[right] > pivot) { right--; } //pivot보다 큰 경우는 건너뛰고 작거나 같은경우 멈춤
 
        if(left <= right){ swap(arr, left, right); }
    }
 
 
    if(start < end) 
    {  //1개로 쪼개질때 까지
        swap(arr, start, right);   //pivot값과 arr[right] 값 swap
 
        QuickSort(arr, start, right-1);  //앞 부분
        QuickSort(arr, right+1, end);    //뒷 부분
    }
 
    return;
}
 
void Printout(int *arr, int len)
{

    //출력
    for(int i=0; i<len ; i++)
    {
        cout << "[" << arr[i] << "]";
    }
    cout << endl;
}
 
 
int main(void){
    int arr[7] = {5,3,6,7,1,2,4};

    //범위 넣기 0~6
    QuickSort(arr, 0, 6);
    Printout(arr, 7);
 
    return 0;
}

```
## 깊은 복사, 얕은 복사 그리고 복사생성자...


- 기본 생성되는 4가지 : 생성자, 소멸자, 복사생성자, 대입연산자

- 복사 생성자를 꼭 만들어야 하는 경우
1. 값 상태 객체, 참조 상태 객체
2. 얕은 복사와 깊은 복사

- 값 상태 객체- 얕은복사문제x
- 참조 상태 객체- 얕은복사문제 o
- 따라서 값 상태 객체만 있으면 얕은복사도 상관없겠죠.. 그냥 멤버변수에 대입

``` c++
그래서 대부분 실수하지않게, 복사를 막거나 안되게
private 이나 delete 키워드로 다른사람이 못쓰게 막거나 깊은 복사를 함
```

- [rule_of_three 사이트](https://en.cppreference.com/w/cpp/language/rule_of_three)

- Rule of Three
소멸자, 이동 생성자, 이동 복사 연산자를 정의해두자.

- Rule of Five
소멸자, 이동 생성자, 복사 생성자, 이동 대입 연산자, 복사 대입 연산자 다섯 가지 특수 멤버 함수들을 구현해놓자.

- Rule of Zero
소멸자, 이동 생성자, 복사 생성자, 이동 대입 연산자, 복사 대입 연산자 다섯 가지 특수 멤버 함수들을 필요로 하지 않도록 디자인 하는 것이다.
기본적인 방법으로는 구식 스타일의 메모리 할당을 피하는 것이다.
A클래스를 2차원 배열로 동적할당 하기 위해 A**으로 선언하지 말고 vector<vector<A>> 이런식으로 사용하자. 
vector는 메모리 할당을 알아서 해주기 때문에 위에 상기된 5가지 멤버함수을 사용할 일이 없다.


## 구조체 직렬화, 그리고 패딩...

-[참조](https://pangate.com/19)
- 구조체와 패딩비트 (면접 문제... 이전도 받은거 같은데 까먹었습니다.ㅠ)

``` C++
아래와 같은 구조체를 선언했다고 하자.
struct test_s
{
  char a;
  int b;
} test;

``

char가 1바이트이고 int가 4바이트인 시스템에서 위의 구조체를 선언하고 sizeof()로
구조체의 사이즈를 찍어보면 얼마가 나올까? 생각대로라면 5(1 + 4 = 5 )바이트가 나와야 한다. 

그런데 대부분의 컴파일러에서 실제로는 8바이트가 나온다. 이유는 패딩비트가 추가되어서 그렇다.
 몇몇 컴파일러는 구조체의 필드를 메모리에 위치시킬때 중간에 빈 공간없이 쭉 이어서 할당하는 경우도 있지만, 
대부분의 컴파일러는 성능향상을 위해 CPU가 접근하기 쉬운 위치에 필드를 배치한다.
그러다보니 중간에 빈 공간이 들어가게 되는것이다. 이 빈 공간이 바로 패딩비트이다

``` C++
char a: 1byte
padding bit: 3bytes
int b: 4bytes
```

위와 같이 패딩비트가 들어가서 총 8바이트가 되면 CPU가 각 멤버에 접근할때 한번씩만 메모리를 읽으면 각 멤버의 값을 구할 수 있다. 쓸모없는 메모리를 3바이트나 낭비하는 꼴이 되어버리지만 CPU가 각 멤버에 접근할때 한번씩만 메모리를 읽으면 되기 때문에 성능저하가 발생하지 않는다.

- 알고가야되는점, 문제점
 네트워크을 통해서 구조체 자체를 전송하려고 하면 패팅비트가 굉장히 중요한 변수가 된다. 왜냐하면 구조체가 메모리에 정의되는 형태는 OS와 컴파일러에 따라 달라지기 때문이다. 동일한 구조체를 서로 다르게 메모리에 정의하고 있는 시스템끼리 메모리에 있는 구조체 내용을 그대로 주고 받는다면 구조체의 각 멤버는 서로 다른값을 가지게 된다.


## 가상함수 

-생성자, 소멸자에서 가상함수 문제 (중요)
[참고](https://lunchballer.com/archives/831)
``` C++
//정리하면, 생성자와 소멸자에서 가상 함수를 호출할 수는 있지만, 
//가상 함수의 역할은 하지 않게 되고, 멤버 함수로서의 기능으로만 작동된다. 
class Base
{
public:
	Base()
	{
		cout << "Base 생성자 호출" << "\n";
		//call(); //객체 소멸 , 객체생성 중에는 절대로 가상함수 호출하지말자, 할당 소멸중에 먼저 실행되면 안됨 
       // 실행을 해보면, 아래와 같이 Base::casll()가 호출되었다는 것을 알 수 있다.  즉, 생성자에서 가상 함수를 호출할 수는 있지만, 하위 클래스의 가상 함수가 호출되지는 않는다.  생성자에서는 virtual의 의미가 없어지는 것이고 이는 Item 오브젝트가 아직 생성되지 않았기 때문이다. 
	}

	virtual ~Base()
	{
        //virtual를 써주지않으면 자식클래스의 소멸자가 호출되지않음
        //Base* d = new Item("t");
		cout << "Base 소멸자 호출" <<"\n";
        //call(); 소멸된후에 실행
	}
    //virtual void call() { }

	//virtual void call() = 0; // 순수 가상함수로 실행하면 링크오류가 발생
};


class Item : public Base
{
private:
	const char* m;
public:
	Item(const char *_m):m(_m)
	{
		cout << "Item 생성자 호출 " << "\n";
	}

	~Item() 
	{
		cout << "Item 소멸자호출" << "\n";
	}
	/*
	void call()
	{
		cout << "call" << "\n";
	}
	*/

};

int main() 
{
	Item* d = new Item("t");
	//Base* b = d;

	delete d;

	return 0;
}

```
## 가상함수, 순수가상함수 

- 순수 가상 함수는 인터페이스(Interface)를 자식 클래스에게 전달하기 위해 사용하는 함수입니다.

- 일반(단순) 가상 함수는 인터페이스(Interface) + 함수의 선언(내부 구현) 까지 자식 클래스에게 전달하기 위해 사용하는 함수입니다


## const

- 상수화, 멤버함수 내 멤버변수 변경x

## r-value 레퍼런스, 퍼펙트포워딩


## 맵과 언오더 맵, 벡터 데이터 사용

### HashTable(언오더 맵)

* HashTable 개념
  * Key와 Value를 1:1로 연관지어 저장하는 자료구조 (연관배열 구조)
  * Key를 이용하여 Value 도출

* HashTable 기능
  * 연관배열 구조와 동일한 기능 지원
  * Key, Value가 주어졌을 때, 두 값을 저장
  * Key가 주어졌을 때, 해당 Key에 연관된 Value 조회
  * 기존 Key에 새로운 Value가 주어졌을 때, 기존 Value를 새로운 Value로 대체
  * Key가 주어졌을 때, 해당 Key에 연관된 Value 제거

* HashTable 구조

  * Key, Hash Function, Hash, Value, 저장소(Bucket, Slot)로 구성
  * Key
    * 고유한 값
    * 저장 공간의 효율성을 위해 Hash Function에 입력하여 Hash로 변경 후 저장
      * Key는 길이가 다양하기 때문에 그대로 저장하면 다양한 길이만큼 저장소 구성이 필요
  * Hash Function
    * Key를 Hash로 바꿔주는 역할
    * 해시 충돌(서로 다른 Key가 같은 Hash가 되는 경우)이 발생할 확률을 최대한 줄이는 함수를 만드는 것이 중요
  * Hash
    * Hash Function의 결과
    * 저장소에서 Value와 매칭되어 저장
  * Value
    * 저장소에 최종적으로 저장되는 값
    * 키와 매칭되어 저장, 삭제, 검색, 접근 가능

* HashTable 동작 과정
  1. Key -> Hash Function -> Hash Function 결과 = Hash
  2. Hash를 배열의 Index로 사용
  3. 해당 Index에 Value 저장
  * HashTable 크기가 10이라면 A라는 Key의 Value를 찾을 때 hashFunction("A") % 10 연산을 통해 인덱스 값 계산하여 Value 조회

* Hash 충돌
  * 서로 다른 Key가 Hash Function에서 중복 Hash로 나오는 경우
  * 충돌이 많아질수록 탐색의 시간 복잡도가 O(1)에서 O(n)으로 증가

* Hash 충돌 해결 방법
  1. Separating Chaining
      * JDK 내부에서 사용하는 충돌 처리 방식
      * Linked List(데이터 6개 이하) 또는 Red-Black Tree(데이터 8개 이상) 사용
       
      * Linked List 사용 시 충돌이 발생하면 충돌 발생한 인덱스가 가리키고 있는 Linked List에 노드 추가하여 Value 삽입
      * Key에 대한 Value 탐색 시에는 인덱스가 가리키고 있는 Linked List를 선형 검색하여 Value 반환 (삭제도 마찬가지)
      * Linked List 구조를 사용하기 때문에 추가 데이터 수 제약이 적은편
  2. Open addressing
      * 추가 메모리 공간을 사용하지 않고, HashTable 배열의 빈 공간을 사용하는 방법
      * Separating Chaining 방식에 비해 적은 메모리 사용
      * 방법은 Linear Probing, Quadratic Probing, Double Hashing
  3. Resizing
      * 저장 공간이 일정 수준 채워지면 Separating Chaining의 경우 성능 향을 위해, Open addressing의 경우 배열 크기 확장을 위해 Resizing
      * 보통 두배로 확장
      * 확장 임계점은 현재 데이터 개수가 Hash Bucket 개수의 75%가 될 때

* HashTable 장점
  * 적은 리소스로 많은 데이터를 효율적으로 관리 가능
    * ex. HDD. Cloud에 있는 많은 데이터를 Hash로 매핑하여 작은 크기의 시 메모리로 프로세스 관리 가능
  * 배열의 인덱스를 사용하기 때문에 빠른 검색, 삽입, 삭제 (O(1))
    * HashTable의 경우 인덱스는 데이터의 고유 위치이기 때문에 삽입 삭제 시 다른 데이터를 이동할 필요가 없어 삽입, 삭제도 빠른 속도 가능
  * Key와 Hash에 연관성이 없어 보안 유리
  * 데이터 캐싱에 많이 사용
    * get, put 기능에 캐시 로직 추가 시 자주 hit하는 데이터 바로 검색 가능
  * 중복 제거 유용

* HashTable 단점
  * 충돌 발생 가능성
  * 공간 복잡도 증가
  * 순서 무시
  * 해시 함수에 의존

* HashTable vs HashMap
  * Key-Value 구조 및 Key에 대한 Hash로 Value 관리하는 것은 동일
  * HashTable
    * 동기
    * null값 허용
    * 보조 Hash Function과 separating Chaining을 사용해서 비교적 충돌 덜 발생 (Key의 Hash 변형)
  * HashMap
    * 비동기 (멀티 스레드 환경에서 주의)
    * null값 미허용(Key가 hashcode(), equals()를 사용하기 때문)

* HashTable 성능

    | |평균|최악|
    |----|----|----|
    |탐색|O(1)|O(N)|
    |삽입|O(1)|O(N)|
    |삭제|O(1)|O(N)|


## BST, 레드블랙트리에 대한 설명과 시간복잡도


[참고](https://zeddios.tistory.com/237)

- 레드블랙트리의 높이는 logn에 바운드 된다 => 레드블랙트리에서 search연산은 O(logn)의 시간복잡도를 가지게 된다. 

- Restructuring, Recoloring 연산

1. Root Property : 루트노드의 색깔은 검정(Black)이다.

2. External Property : 모든 external node들은 검정(Black)이다.

3. Internal Property : 빨강(Red)노드의 자식은 검정(Black)이다. 

== No Double Red(빨간색 노드가 연속으로 나올 수 없다.) 

4. Depth Property : 모든 리프노드에서 Black Depth는 같다. 

== 리프노드에서 루트노드까지 가는 경로에서 만나는 블랙노드의 개수는 같다.

## 템플릿 메타프로그래밍 (Template Metaprogramming)

- 템플릿을 이용해 메타 프로그래밍을 하는 것을 뜻한다. 쉽게 말하면, 언어에서 제공해주는 기능인 템플릿(틀)을 이용해, 프로그램을 작성하는 부분을 프로그래밍하는 하는 것인데, 템플릿 기능이 있는 가장 대표적인 언어가 C++라 C++에 관련된 토픽으로 분류되는 경우가 많다.

- 보통 말하는 C++에서의 템플릿 메타 프로그래밍이란, 템플릿을 이용하여 컴파일 타임에 코드를 생성하는 것을 말한다. 보통 함수형 프로그래밍 방식으로 개발하며, 일반화 프로그래밍이 가능하다는 장점이 있다.

``` C++
int Fibo(int n)// 재귀 함수
{
    if(n <= 1) return 1;
    return Fibo(n-1) + Fibo(n-2);
}

// 템플릿 메타 프로그래밍
template <int N>
struct Fibo
{
    enum{
        value = Fibo<N-1>::value + Fibo<N-2>::value
    }
}

template <>
struct Fibo<0>
{
    enum{
        value = 1
    }
}

template <>
struct Fibo<1>
{
    enum{
        value = 1
    }
}
```

3. 방법
주로 재귀적 성질을 이용한 함수형 프로그래밍을 사용한다. 템플릿의 비 타입 인자에는 컴파일 타임에 값을 알 수 있는 값만 넣을 수 있다. 주의할 점 중 하나는, 상수 포인터는 비타입 인자가 될 수 있지만 const char*는 예외적인 경우가 있다. 비타입 인자가 const char*형일 때, 같은 문자열을 넣어도 주소값이 다를 수 있기 때문에, extern 키워드를 사용하거나 일종의 꼼수를 써야 한다.

위의 예제와 같이, 좀 더 일반적인 템플릿 인자(위에서는 template <int N> ~~)를 가진 형태와 경계 조건일 때의 인자(template<>~~)를 가진 형태로 나누어서 프로그래밍하게 되는데, 위쪽에 일반적인 형태를 선언한다.

4. 원리
템플릿의 확장은 컴파일 타임에 이루어진다. 컴파일러 최적화가 더디던 시절에는, 컴파일을 하는 도중 템플릿을 만나면 현재까지 알고 있는 심볼 등을 확인하면서 알 수 있는 내용을 가지고 익명 함수 등을 만들며 원시 C++ 코드를 작성해나갔다. 이런 과정이 끝나고 템플릿이 모두 전개되었다면 그때부터 원래 코드를 컴파일하기 시작했다. 지금은 이 과정에서 최적화 등을 사용하는 경우가 많은 편.

5. 장점
원래 언어에 있는 기능이다. 메타 프로그래밍이 보통 스크립트 언어 등으로 다른 언어를 붙여서 써야하는 경우가 많은데 반해서, C++ 언어에 원래 정의된 것을 가지고 구현하기 때문에, C++ 규격의 변화에만 대응하면 된다.
런타임의 시간 복잡도를 줄일 수 있다. 컴파일 타임에 모든 것이 이루어지기 때문에 런타임 복잡도가 줄어들어 실행시간 등이 감소할 여지가 많다.
무결성. 소스 코드의 재활용 등으로 복붙 등의 과정을 줄일 수 있어 무결성 및 관리성이 높아진다.

6. 단점
템플릿을 떡칠하면 알아보기 힘들다. 일반적으로 인간의 두뇌는 이러한 확장 과정에 익숙하지 않은 편이다. 특히 디버그하는 과정에서 템플릿을 떡칠하다보면 환장하는 경우가 꼭 한 번씩은 있을 것이다.
컴파일 복잡도가 늘어난다. 이게 문제가 되는 건 소규모 프로그램보다는 주로 대형 프로젝트 쪽. 그잖아도 컴파일에 수 시간 걸리는 프로젝트에 템플릿 메타프로그래밍을 쓴다면?
프로그램이 커진다. 지금이야 용량이 문제가 되는 시대가 아니긴 하지만, 컴파일 시간에 코드를 확장하면서 길이가 늘어나기 때문에 프로그램이 쉽게 커질 수 있다. 다행히 용량에 민감한 임베디드 쪽은 C++을 많이 쓰지 않는다고는 하지만. 또한 길이가 길어지면서 자연스럽게 프로그램 로딩 속도도 길어진다는 점도 나름의 문제점이다.


- Template Argument Type Deduction 정리 (타입추론)

``` C++
template<typename T>
void A(typename T);
A(expr); 이럴때 타입에 대해서 추론해봐라.

```

- 템플릿 인자가 값 타입(T a)

```
함수 인자가 가진 const, volatile, reference 속성 제거 후 T 타입 결정
인자의 const 속성만 제거됨
```

- 템플릿 인자가 참조 타입(T& a)

```
함수 인자가 가진 reference 속성만 제거 후 T 타입 결정
const, volatile 속성 유지
인자가 (const T& a)경우 const를 제거하고 T 타입 결정
```

- 템플릿 인자가 forwarding 레퍼런스 타입(T&& a)

```
lvalue, rvalue 모두 전달 받음
템플릿 인자가 배열
argument decay 발생
```