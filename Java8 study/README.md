# 백기선님 더자바 JAVA8, 강의 필기

- 강의 수강 2021.2.16~
- [강의 링크](https://www.inflearn.com/course/the-java-java8)

## 1. 자바 8 소개
- 현재 자바 개발자 중 약 83%가 사용중.

- 주요 기능
```
● 람다 표현식
● 메소드 레퍼런스
● 스트림 API
● Optional<T>
● ...
```
- JAVA 11 JDK 설치

## 2. 함수형 인터페이스와 람다 표현식 소개

- 함수형 인터페이스 (Functional Interface)
- 추상 메소드를 딱 하나만 가지고 있는 인터페이스, 조금더 견고하게 씀
- SAM (Single Abstract Method) 인터페이스
``` java
@FuncationInterface// 애노테이션을 가지고 있는 인터페이스 -> 위반을 하면 컴파일 에러나게함
public interface RunSomething {
	void doit();
}
```
JAVA8 - public static -> static 으로


- 람다 표현식 (Lambda Expressions)
- 함수형 인터페이스의 인스턴스를 만드는 방법으로 쓰일 수 있다.
- 코드를 줄일 수 있다.
- 메소드 매개변수, 리턴 타입, 변수로 만들어 사용할 수도 있다
- 인텔리제이가 람다로 바꿔줌


``` java
//일반
    public static void main(String[] args){
        RunSometing runSomething = new RunSometing() { // 연한 회색부분을 갖다대면 람다로 바꿔주는게 뜸
            @Override
            public void doIt() {
                system.out.println("Hello");
            }
        }
    }
//람다 표현식
    public static void main(String[] args){
        RunSometing runSomething = {} {
            ->system.out.println("Hello");
            runSomething.doIt();
        };
    }

```


- 자바에서 함수형 프로그래밍
 ```
-  함수를 First class object로 사용할 수 있다.

-  순수 함수 (Pure function)
 사이드 이팩트가 없다. (함수 밖에 있는 값을 변경하지 않는다.)
 상태가 없다. (함수 밖에 있는 값을 사용하지 않는다.)

-  고차 함수 (Higher-Order Function)
 함수가 함수를 매개변수로 받을 수 있고 함수를 리턴할 수도 있다.
-  불변성
```

- 함수형 프로그래밍은 순수함수를 고려해야한다. 하지만 문법에서 허용하는 만큼 하면 됩니다.
``` java
public class Foo {
    public static void main(String[] args){
        RunSometing runSomething = {number} {
            return number + 10; // 보장을 해줄수 없는 상황은 함수형 프로그래밍으로 보기힘들다.
        };
    }
}
```

``` java
public class Foo {
    public static void main(String[] args){
        int baseNumber =10; // 함수의밖
        RunSometing runSomething = new RunSometing() {
            //함수의 밖, 상태값에 의존->순수함수가 아니다. 외부에서 변경하는 것도 순수함수가 아니다.
            @Override
            public void doIt() {
                 return number + baseNumber;
            }
        }
    }
}
```