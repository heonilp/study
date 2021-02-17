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


## 5. 메소드 레퍼런스

- 람다가 하는 일이 기존 메소드 또는 생성자를 호출하는 거라면, 메소드 레퍼런스를 사용해서 매우 간결하게 표현할 수 있다.

- 메소드 참조하는 방법
```
● 메소드 또는 생성자의 매개변수로 람다의 입력값을 받는다.
● 리턴값 또는 생성한 객체는 람다의 리턴값이다.
```

```
스태틱 메소드 참조 / 타입::스태틱 메소드
특정 객체의 인스턴스 메소드 참조 / 객체 레퍼런스::인스턴스 메소드
임의 객체의 인스턴스 메소드 참조 / 타입::인스턴스 메소드
생성자 참조  /타입::new
```


``` java
//1. 기존 방법
public class App {
    public static void main(String[] args){
        UnaryOperator <String> hi = {s} -> "hi" + s;
       
    }
}

//2. 스태틱 메소드 참조를 사용하는 방법
public class App {
    public static void main(String[] args){
        UnaryOperator <String> hi = {s} -> Greeting::hi; // 메소드 참조
       
    }
}

//3. 인스턴스를 참조하는 방식
public class App {
    public static void main(String[] args){
       Greeting greeting = new Greeting();
       UnaryOperator <String> hello = {s} -> Greeting::hello;     //hello를 가지고 apply를해야 만들어짐  
    }
}

public class App {
    public static void main(String[] args){
        Supplier <Greting> newGreeting = Greting::new;  //만들어지지않음 Get을 해야 만들어짐
        newGreeting.get();
    }
}


public class App {
    public static void main(String[] args){ //메소드만봐서 어떤 생성자를 쓰는지 모름
        Function <String, Greting> hiGreeting = Greting::new;  //만들어지지않음 Get을 해야 만들어짐
        
        Greting hi = hiGreeting.apply("hi");
        System.out.println(hi.getName());

        Supplier <Greting> newGreeting = Greting::new;  
    }
}

// 기본 sort
public class App {
    public static void main(String[] args){ 
        String [] names = {"a1" , "b2" , "c3"};
        Arrays.sort(names, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2){
                return 0;
            }
        });
    }
}

// 람다형
public class App {
    public static void main(String[] args){ 
        String [] names = {"a1" , "b2" , "c3"};
        Arrays.sort(names, String::compareToIgnoreCase); //메소드 레퍼런스/ 임의의 레퍼런스를 사용
        System.out.println(Arrays.toString(names));
    }
}

public class Greeting {
    private String name;

    public Greeting() { //생성자 입력값이 없음, 객체의 타입
    }

    public String getName() { //게터
         return name;
    }

    public Greeting(String name) { //생성자 입력값
        this.name = name;
    }

    public String hello(String name) {
        return "hello" + name;
    }

    public String hi(String name) {
        return "hi" + name;
    }
}

```

# 3부 인터페이스의 변화

## 6. 인터페이스 기본 메소드와 스태틱 메소드


- 기본 메소드 (Default Methods), 강력한 기능이기 때문에 주의해서 사용하자!!

```
● 인터페이스에 메소드 선언이 아니라 구현체를 제공하는 방법
● 해당 인터페이스를 구현한 클래스를 깨트리지 않고 새 기능을 추가할 수 있다.
● 기본 메소드는 구현체가 모르게 추가된 기능으로 그만큼 리스크가 있다.
    ○ 컴파일 에러는 아니지만 구현체에 따라 런타임 에러가 발생할 수 있다.
    ○ 반드시 문서화 할 것. (@implSpec 자바독 태그 사용)

● Object가 제공하는 기능 (equals, hasCode)는 기본 메소드로 제공할 수 없다.
    ○ 구현체가 재정의해야 한다.

● 본인이 수정할 수 있는 인터페이스에만 기본 메소드를 제공할 수 있다.
● 인터페이스를 상속받는 인터페이스에서 다시 추상 메소드로 변경할 수 있다.
● 인터페이스 구현체가 재정의 할 수도 있다.

- 스태틱 메소드
● 해당 타입 관련 헬퍼 또는 유틸리티 메소드를 제공할 때 인터페이스에 스태틱 메소드를
제공할 수 있다.

```

``` java
public interface Foo {

    void printName();

   // void printNameUpperclass();//구현체에서 구현을 안하면 오류가남


// 다음과 같은 것을 주석으로 써놓은다.
// @implSpec 이 구현체는 getName()으로 가져온 문자열을 대문자로 바꿔 출력한다.

   //하지만 앞에 default 키워드를 넣으면 오류가안남
   //동작이 100% 구현하는 게 보장되지 않음, null 오면 런타임 익섹션이 발생함
    default void printNameUpperCase(){
        System.out.println(getName().toUpperCase());
    }

    static void printAnything(){
        System.out.println("Foo");
    }

    String getName();
}


public class DefalutFoo implements Foo { // Foo, Bar 두개 쓰면 안됨 충돌하는 경우 오버라이딩해야함

    String name;

    public DefalutFoo(String name) {
        this.name = name;
    }

    //오버라이딩으로 재정의 할수 있다.
    default void printNameUpperCase(){
        System.out.println(getName().toUpperCase());
    }

    @Override
    public void printName() {
        System.out.println(this.name);
    }


    @Override
    public String getName() {
        return this.name;
    }
}


public class App {
    public static void main(String[] args){ 
       Foo foo = new DefalutFoo("hi");
       foo.printName();
       foo.printNameUpperCase();
       Foo.printAnything(); // 스태틱 메소드
       //해당 타입 관련 헬퍼 또는 유틸리티 메소드를 제공할 때 인터페이스에 스태틱 메소드를제공할 수 있다.
    }
}

```

``` java
public interface Bar extends Foo {

    void printNameUpperCase(); // 추상메소드 , 하지만 , Bar 받는 것이 재정의해야합니다.
}

```


