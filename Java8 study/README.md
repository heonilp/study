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

## 3. 자바에서 제공하는 함수형 인터페이스

- Java가 기본으로 제공하는 함수형 인터페이스
● java.util.function 패키지
● 자바에서 미리 정의해둔 자주 사용할만한 함수 인터페이스
```
● Function<T, R>
● BiFunction<T, U, R>
● Consumer<T>
● Supplier<T>
● Predicate<T>
● UnaryOperator<T>
● BinaryOperator<T>
```

- Function<T, R>
```
● T 타입을 받아서 R 타입을 리턴하는 함수 인터페이스
    ○ R apply(T t)
● 함수 조합용 메소드
    ○ andThen
    ○ compose
```
``` java
public class Foo {
    public static void main(String[] args){
        Function <Integer, Integer> plus10 = {i} -> i + 10;
        Function <Integer, Integer> multiply2 = {i} -> i * 2;
        System.out.println(plus10.apply(1));

        plus10.compose(multiply2).apply(2); // 교차 함수 성질  x x2 + 10 = 결과값 14

        plus10.andThen(multiply2).apply(2); //x +10 x2 = 결과값 24
    }
}
```



- BiFunction<T, U, R>
```
● 두 개의 값(T, U)를 받아서 R 타입을 리턴하는 함수 인터페이스
    ○ R apply(T t, U u)
```

- Consumer<T>
```
● T 타입을 받아서 아무값도 리턴하지 않는 함수 인터페이스
    ○ void Accept(T t)
● 함수 조합용 메소드
    ○ andThen
```

``` java
public class Foo {
    public static void main(String[] args){
        Consumer <Integer> printT = {i} -> System.out.println(i);
        printT.accept(10); //10출력
}
```

-Supplier<T>
```
● T 타입의 값을 제공하는 함수 인터페이스
    ○ T get()
```

``` java
public class Foo {
    public static void main(String[] args){
        Supplier <Integer> get10 = {} -> 10;
        System.out.println(get10.get()); //10을 가져오는 함수
}
```

- Predicate<T>
```
● T 타입을 받아서 boolean을 리턴하는 함수 인터페이스
    ○ boolean test(T t)
● 함수 조합용 메소드
    ○ And
    ○ Or
    ○ Negate
```

``` java
public class Foo {
    public static void main(String[] args){
        Predicate <Integer> hi = {s} -> s.startWith("heonil");
       // 조합, And, Or 가능
}
```

- UnaryOperator<T>
```
● Function<T, R>의 특수한 형태로, 입력값 하나를 받아서 동일한 타입을 리턴하는 함수
인터페이스
```

``` java
public class Foo {
    public static void main(String[] args){
        UnaryOperator <Integer> plus10 = {i} -> i + 10;
        UnaryOperator <Integer> multiply2 = {i} -> i * 2;
    }
}
```

- BinaryOperator<T>
```
● BiFunction<T, U, R>의 특수한 형태로, 동일한 타입의 입렵값 두개를 받아 리턴하는 함수
인터페이스
```


# 4. 람다 표현식
- 람다
● (인자 리스트) -> {바디}


- 인자 리스트
```
● 인자가 없을 때: ()
● 인자가 한개일 때: (one) 또는 one
● 인자가 여러개 일 때: (one, two)
● 인자의 타입은 생략 가능, 컴파일러가 추론(infer)하지만 명시할 수도 있다. (Integer one,
Integer two)
```

- 바디
```
● 화상표 오른쪽에 함수 본문을 정의한다.
● 여러 줄인 경우에 { }를 사용해서 묶는다.
● 한 줄인 경우에 생략 가능, return도 생략 가능.
```

- 변수 캡처 (Variable Capture)
```
● 로컬 변수 캡처
    ○ final이거나 effective final 인 경우에만 참조할 수 있다.
    ○ 그렇지 않을 경우 concurrency 문제가 생길 수 있어서 컴파일가 방지한다.
● effective final
    ○ 이것도 역시 자바 8부터 지원하는 기능으로 “사실상" final인 변수.
    ○ final 키워드 사용하지 않은 변수를 익명 클래스 구현체 또는 람다에서 참조할 수
있다.
● 익명 클래스 구현체와 달리 ‘쉐도윙’하지 않는다.
    ○ 익명 클래스는 새로 스콥을 만들지만, 람다는 람다를 감싸고 있는 스콥과 같다.
```

- 예제
``` java
   public class Foo {
    public static void main(String[] args){
        Foo foo = new Foo();
        foo.run();
    }

    private void run() {
        int baseNumber =10; //final (이펙티브 final)
        //baseNumber++//final이기 때문에안됨

        //로컬 클래스
        class LocalClass {
            void printBaseNumber() {
                //int baseNumber =11;
                System.out.println(baseNumber); //11
            }
        }

        //익명클래스
        Cousumer <Integer> IntegerConsumer = new Cousumer<Integer>() {
            @Override
            public void accept(Integer integer){
                System.out.println(baseNumber);
            }
        };

        //람다 run이랑 같은 스코프, 동일 이름의 변수를 쓸수없음
        IntConsumer printInt = (i) -> {
            System.out.println(i + baseNumber);
        };

        printInt.accept(10);
    }
}
```