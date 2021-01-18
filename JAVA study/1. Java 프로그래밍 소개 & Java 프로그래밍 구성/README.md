
# - 1주차 (1월 11일 ~ 1월 17일)
## Java 프로그래밍 소개 & Java 프로그래밍 구성

### 강좌에서 제외할 부분
- Chapter 2-1. 온라인 실습 환경 장만하기 ~ Chapter 3. Java_개발환경_eclipse_설치
- Chapter 5-2. 사물을 자바로 제어하기

- **Windows10 환경, 이클립스, 인텔리제이, JAVA**로 실습하였습니다.


# 이번강의 / 자주 나오는 JAVA 면접 질문

## 1. C, JAVA 언어 차이, 절차지향과 객체지향 차이 설명해주세요.

## 2. JAVA의 실행 과정 설명해주세요.

<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/1.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%86%8C%EA%B0%9C%20%26%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EA%B5%AC%EC%84%B1/pc/javarun.jpg" width="30%"></img>
</div>

- java 파일의 형태로 소스 코드를 작성하면, 컴파일 과정을 거쳐 JVM(Java Virtual Machine, 자바 가상 머신)이 알아들을 수 있는 class 파일로 변환됩니다.
- 이클립스에서는 자바 파일을 저장할 때 컴파일을 하여 class 파일로 저장합니다.
- 이클립스에서 실행 버튼을 누르게 되면 JVM에서 class 파일을 읽어들입니다.
- JVM은 class 파일을 읽고서 그대로 컴퓨터를 동작시키게 됩니다.

## 3. JVM(JAVA Virtual Machine) 설명해주세요

## 4. GC(Garbage collection) 설명해주세요

## 5. String StringBuilder StringBuffer 차이 설명해주세요.


* String
    * 새로운 값을 할당할 때마다 새로 클래스에 대한 객체가 생성된다.
    * String에서 저장되는 문자열은 private final char[]의 형태이기 때문에 String 값은 바꿀수 없다.
        * private: 외부에서 접근 불가
        * final: 초기값 변경 불가
    * String + String + String...
        * 각각의 String 주솟값이 Stack에 쌓이고, Garbage Collector가 호출되기 전까지 생성된 String 객체들은 Heap에 쌓이기 때문에 메모리 관리에 치명적이다.
    * String을 직접 더하는 것보다는 StringBuffer나 StringBuilder를 사용하는 것이 좋다.
* StringBuilder, StringBuffer
    * memory에 append하는 방식으로, 클래스에 대한 객체를 직접 생성하지 않는다.
    * StringBuilder
        * 변경가능한 문자열
        * 비동기 처리
    * StringBuffer
        * 변경가능한 문자열
        * 동기 처리
        * multiple thread 환경에서 안전한 클래스(thread safe)
* Java 버전별 String Class 변경 사항
    * JDK 1.5 버전 이전에서는 문자열 연산(+, concat)을 할 때 조합된 문자열을 새로운 메모리에 할당하여 참조해 성능상의 이슈 존재
    * JDK 1.5 버전 이후에는 컴파일 단계에서 String 객체를 StringBuilder로 컴파일 되도록 변경됨
    * 그래서 JDK 1.5 이후 버전에서는 String 클래스를 사용해도 StringBuilder와 성능 차이가 없어짐
    * 하지만 반복 루프를 사용해서 문자열을 더할 때에는 객체를 계속 새로운 메모리에 할당함
    * String 클래스를 사용하는 것 보다는 스레드와 관련이 있으면 StringBuffer, 스레드 안전 여부와 상관이 없으면 StringBuilder를 사용하는 것을 권장

## 6. final 키워드에 대해서 설명해주세요.

## 7. public static void 선언 이유를 면접에서 많이 물어봅니다.

#### Java의 Main 
- Java는 Main에서 시작해서 Main에서 끝난다
- Main은 여러 클래스와 연결될 수 있는 중심부의 역할이다.
 
#### 매인의 public
- Main을 실행하는데 있어, Main에서는 다른 클래스의 메소드 등을 호출해야하는데, 막상 Main 자체가 다른 곳에서 접근을 허용하지 않는다면 문제가 생길 수 밖에 없어 Main의 접근제한자를 public으로 선언한 것입니다.
 
#### 메인의 static
- static은 프로그램이 시작하면 따로 인스턴스화 하지 않아도 method 영역 메모리에 호출되어 진다. 이렇게 호출되어진 것들은 프로그램이 종료되기 까지 유지된다.
- 즉, 프로그램의 시작과 끝을 함께하는 Main 메소드는 프로그램이 종료되는 시점까지 유지해야하기 때문에 static으로 선언된 것이다.
 
#### 메인의 void
- Main 메소드는 프로그램이 종료되는 시점까지 유지가 된다. 즉, 만약 반환 타입이 선언되어 있다면 프로그램이 종료될 때 어떤 값을 반환하겠다라는 것인데, 이는 우리가 추구하는 목적과는 상관없는 로직이다.
- 우리는 프로그램을 사용할 때 프로그램이 구동되는 그 시점에서만 메시지를 주고 받으므로, 프로그램이 종료되는 시점에서 반환되는 값은 전혀 의미가 없는 값이다.

# JAVA 프로그램밍 소개

## CHAPTER 1. JAVA1 수업소개

**이번강의의 목표는 자립성, 강의에 대한 완주, 자신감 찾기**

1. 컴퓨터 프로그래밍 언어 중 하나, **자바**
2. 1991년 **제임스 고슬링**(James Gosling) 에 대해서 만들어짐
3. 자바가 설치된 컴퓨터라면 **어디서든 실행**이 가능하다는 특징
4. 2019년 기준 티오베 www.tiobe.com 의 프로그래밍 언어 인기 순위에서 자바는 1위를 차지
5. 인기있는 언어인 자바는 웹 및 안드로이드의 애플리케이션 소프트웨어 개발에 활용

## 생각해보기 
### 1) '한번 작성하면 어디서든 실행된다'는 특성은 어떤 의미일까요? 그리고 그것이 주는 이점은 무엇일까요?
- JAVA는 자바가상머신 즉, JVM(JAVA Virtual Machine)에 의해서 JAVA와 OS사이에서 중개자 역할을 수행하여 JAVA가 OS에 구해 받지않고 어디서든 실행됩니다.
- JVM(JAVA Virtual Machine)는 그 밖에도 중요한 메모리관리 GC(Garbage collection)을 수행하며, 스택기반의 가상머신입니다.
- C, C++는 디바이스, 컴퓨터 등 컴파일러에 따라서 컴파일이되면 실행파일이 나오는데, 하드웨어, OS 종속성이 있어 다른곳에서 실행되지 않습니다.
- **JVM, GC, JAVA의 실행과정**은 중요한 개념이니 따로 정리하도록 하겠습니다. 

## CHAPTER 4

#### 4-1 실행_HellowWord

1. HelloWorldApp **자바프로젝트**로 이클립스에서 컴파일후 실행, 

``` java
public class HelloWorldApp {
    public static void main(String args[]) {
        System.out.println("Hello World!!");
    }
}
```

## 생각해보기  
### 1) 클래스 파일은 왜 필요할까요?

- .java 파일과 .class 파일 사이에 관계는 다음과 같습니다.
- .java - 컴파일러 - .class파일 - JVM -Hello
- 즉, .class파일은 .java파일을 컴파일하여 생성됩니다.
- .java파일은 규칙에 맞게 작성한 모든 소스코드 파일을 말하며 특징은 사람이 읽을수 있는 TEXT로 되있습니다.
- .class파일는 java bytecode로 구성된 파일입니다.
- bytecode란 자바의 실행환경에서 실행되기 위한 최적화된 코드의 집합입니다.
- JVM을 위한 코드이며 자바를 실행할수 있는 모든 장치에서 실행을 가능하게합니다.


### 2) 이번 강의와 같은 과정을 이클립스 없이 하려면 어떻게 해야 할까요?

**자바의 컴파일 명령어는 javac , 실행명령어는 java** 입니다.
1. 윈도우면 cmd, 리눅스면 해당 경로 프로젝트 디렉토리에 감
2. 패키지 시작부분으로 이동
3. javac 이름.java, 이름.class 파일이 만들어지면 컴파일에 성공한거임 
4. 실행방법 java 이름
5. 자바 내 한글이 있을경우 java -encoding utf-8 이름.java하면 됨


#### 4-2. AS 강의 Editor dose not contain a main type

##### 오류의 원인
- Editor dose not contain a main type이라는 오류가 나타났다면 이클립스가 소스코드가 컴파일된 class 파일을 찾지 못하였기 때문입니다. 그렇다면 왜 찾지 못한 것일까요?
- 왜냐하면, 작성한 MyApp.java 파일이 기본 소스코드 폴더인 src 안에 있지 않기 때문에 이클립스는 MyApp 파일을 소스코드로 인식하지 않기 때문입니다.
- 이클립스에서 자바 애플리케이션을 실행할 때 src 폴더의 소스 파일은 없기 때문에 오류가 발생하게 됩니다.

- 오류를 해결하는 방법
- 오류를 해결하는 방법은 세 가지가 있습니다.
1.  우선 첫 번째는 작성한 MyApp.java 파일을 src 폴더로 옮기는 것입니다.
2. 두 번째는 Project layout 부분의 첫 번째 옵션을 선택하여 다시 새로운 프로젝트를 생성하는 것입니다.
3. 마지막으로는 프로젝트의 속성을 변경하는 것입니다.

 
#### 4-3. 실행_Java의 동작원리

1. 소스는 소프트웨어가 구현되는 원인이라는 의미에서 "소스(Source)"로 불리기도 하며,
2. 기호, 부호라는 의미에서 "코드(Code)"로도 불립니다.
3. 마찬가지로 의미를 전달하는 약속이라는 측면에서 "언어(Language)"로 불리기도 합니다.

## 생각해보기  
### 1) 자바의 동작 원리를 설명하시오.

<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/1.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%86%8C%EA%B0%9C%20%26%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EA%B5%AC%EC%84%B1/pc/javarun.jpg" width="30%"></img>
</div>

- java 파일의 형태로 소스 코드를 작성하면, 컴파일 과정을 거쳐 JVM(Java Virtual Machine, 자바 가상 머신)이 알아들을 수 있는 class 파일로 변환됩니다.
- 이클립스에서는 자바 파일을 저장할 때 컴파일을 하여 class 파일로 저장합니다.
- 이클립스에서 실행 버튼을 누르게 되면 JVM에서 class 파일을 읽어들입니다.
- JVM은 class 파일을 읽고서 그대로 컴퓨터를 동작시키게 됩니다.
 
### 2) 왜 자바의 실행 과정 중에 JVM이 끼어있는 것일까요? 컴파일을 거쳐 바로 컴퓨터를 실행시키는 것은 안될까요?
- [자바 메모리 구조 뿌시기  JVM이란? 강의 추천](https://www.youtube.com/watch?v=AWXPnMDZ9I0)
- [🐥엘리의 GC - 가비지 컬렉션 강의 추천](https://www.youtube.com/watch?v=Fe3TVCEJhzo&t=3s)
#### 참고
- [본강의의 추천 사이트](https://asfirstalways.tistory.com/158)

## CHAPTER 5 Hello Java World

#### 5-1. 데스크톱 애플리케이션 만들기

- swing 패키지로 GUI 창에 Hello World!! 띄우기 실습

- 다음과 같이 실습 하였습니다.
<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/1.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%86%8C%EA%B0%9C%20%26%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EA%B5%AC%EC%84%B1/pc/swing.JPG" width="50%"></img>
</div>

#### 5-3. 안드로이드 애플리케이션 만들기

- 실습이 아니므로 강의보고 넘어갔습니다.

### QUiZ 1 정리

#### Quiz 1 10문항

<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/1.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%86%8C%EA%B0%9C%20%26%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EA%B5%AC%EC%84%B1/pc/quiz1.JPG" width="30%"></img>
</div>

1. 다음 중 Java 프로그램 개발을 위한 개발 환경을 제공해주는 프로그램은 어떤 것일까요? Eclipse
2. 다음 중 HelloWorldApp.java 파일 안에 있는 Class 이름은 어떻게 생성되어야 할까요? HelloWorldApp
3. 다음 중 Java 프로그램이 맨먼저 실행하는 메서드는 무엇일까요? main
4. 다음 코드는 어떤 결과를 출력하게 될까요? System.out.println("Java with me!"); Java with me!
5. 다음 중 Java 라는 언어 문법에 만들어진 소스 코드 파일은 어떤 것일까요? main.java
6. Java 파일을 기계가 이해할 수 있도록 .class 파일로 바꾸는 과정을 무엇이라 할까요? 컴파일
7. 다음 중 Java 프로그램을 동작시키도록 실행환경을 만들어주는 프로그램은 무엇일까요? Java Virtual Machine (JVM)
8. 다음 중 Java 로 만들 수 있는 것은 무엇이 있을까요? 항목전부 (데스크탑 프로그램, 모바일 어플, IoT제어 프로그램)
9. 사물을 프로그램으로 제어할 수 있는 기술을 뭐라고 할까요? Internet of Things
10. 다음 중 안드로이드 어플리케이션을 기본으로 개발할 수 있는 툴은 무엇일까요? Android Studio


# JAVA 프로그래밍 구성

## CHAPTER 6, 7

#### 6-1. 데이터와 연산

- 컴퓨터는 데이터를 가지고 연산을 하는 기계라고 할 수 있습니다.
- 자바와 같은 컴퓨터 프로그래밍 언어를 배워서 사용하는 것은 컴퓨터에게 데이터를 가지고 우리가 원하는 대로 연산을 시킬 수 있게 하는 것이라고 할 수 있습니다.

#### 예를 들면 다음과 같은 데이터 종류가 있습니다.

1. 숫자(Numbers)
2. 문자열(String)
3. 영상/소리/기타 등등
 
## 생각해보기 (개인적인 생각입니다.)

### 1) 이번에 언급된 데이터 타입 이외에 어떤 데이터 타입이 필요하다고 생각하나요?
- 앞서 강의해서 말한 것처럼 숫자에 대한 데이터 타입이 필요하며
- 문자열을 담을 수 있는 공간, 파일을 관리할수 있는 타입, 통신을 관리할 수 있게 소켓을 관리 할수 있는 데이터타입 등등 이 필요할 것같습니다.

### 2) 앞서 생각한 데이터 타입에 어떤 연산작업이 필요하다고 생각하나요?
- 숫자 같은 경우는 사칙연산이 필요하며, 문자열 같은 것은 짤라주거나 합쳐주고, 파싱같은 것이 필요해보입니다.
- 소리나 영상같은 것은 필터링할 수 있는 연산이 필요해보입니다.

#### 6-2. 데이터 타입

#### 숫자와 문자 데이터 타입과 연산

#### 숫자
- 자바에서 숫자는 다른 기호와 함께 입력하지 않고 그대로 입력합니다.
- +연산자는 덧셈의 연산을 수행합니다.
 
#### 문자
- 자바에서 문자열은 쌍따옴표("") 안에 적습니다.
- +연산자는 결합의 연산을 수행합니다.
- 문자열 간에는 * 연산자를 사용할 수 없습니다.
- length 연산은 문자열의 길이를 반환합니다.

1. Data_and_operation **자바프로젝트**로 이클립스에서 컴파일후 실행
- Datatype.java

``` java
public class Datatype{
    public static void main(String[] args) {
        System.out.println(6); // Number
        System.out.println("six"); // String
         
        System.out.println("6"); // String 6
         
        System.out.println(6+6); // 12
        System.out.println("6"+"6"); // 66
         
        System.out.println(6*6); // 36
//      System.out.println("6"*"6");
         
        System.out.println("1111".length()); // 4
//      System.out.println(1111.length());
    }
}
```

## 생각해보기 

### 1) 숫자에서는 +와 *와 같은 연산자를 사용했는데 문자열에서는 연산은 수행하기 위해 .length()와 같은 형식을 사용했습니다. 숫자에도 연산자 이외의 형식을 가지는 연산 종류가 있을까요?
- 위에서 말하지 않은 절대값, 제곱, -(빼기) /(나누기) %(몫), 버림, 반올림, 올림 등 여러가지 있습니다.
- 자바는 ^라는 기호를 제곱을 구할 때 쓰지 않기 때문에 Math.pow를 사용합니다.

### 2) 문자열에서 쓸 수 있는 다른 연산은 어떤 것들이 있을까요?
- String을 쓸때, a + b 묶으면 문자열이 두개가 묶여진다.

#### 6-3. 숫자와 연산

- 핵심 단어 : Math 클래스
- 전에 생성했던 Data_and_operation 프로젝트에서 진행
``` java
public class Number {
    public static void main(String[] args) {
        // Operator
        System.out.println(6 + 2); // 8
        System.out.println(6 - 2); // 4
        System.out.println(6 * 2); // 12
        System.out.println(6 / 2); // 3
 
        System.out.println(Math.PI); // 3.141592653589793
        System.out.println(Math.floor(Math.PI));
        System.out.println(Math.ceil(Math.PI));
    }
}
```

## 생각해보기 

### 1) PI, floor, ceil이외에 Math에서 제공하는 기능이 어떤 것들이 있는지 찾아보고 댓글로 공유해 보세요
```
- max, min pow, sqrt, sin cos, tan random, abs 등 제공하는 기능 들 이 많습니다.
```
[Math 클래스 기능들 참고](http://www.tcpschool.com/java/java_api_math)

#### 6-4. 문자열의 표현

##### 핵심 단어
- 문자(character) 자료형
- 문자열 리터럴
- 이스케이프 

> 문자열(String)과 문자(Character)
```
문자열은 문자의 나열입니다. 문자는 따옴표('') 안에 입력하여 표현하는데, 한 개의 문자만 포함할 수 있습니다.
문자는 오직 한 개의 문자만 포함될 수 있지만, 문자열은 1개 이상의 문자들도 포함할 수 있습니다.
```
 
> 이스케이프 기호
``` 
이스케이프 기호는 줄바꿈 기호나 쌍따옴표와 같은 특수한 기호를 문자열에 넣기 위해 사용합니다.
이스케이프 기호는 역슬래시(\)로 입력할 때는 키보드 상의 원화 기호(\)로 입력하면 됩니다.
이스케이프 기호는 특정 문자와 결합하여 제어문자로 기능하기도 하고, 쌍따옴표와 같은 특수한 문자와 결합하여 특수한 문자가 일반 문자라고 나타내 주는 역할을 합니다.
문자열에서 줄바꿈을 하고 싶을 때 문자열 사이에서 바로 줄바꿈을 하면 문법상의 오류가 생기게 됩니다.
그렇다면 줄바꿈을 하기 위해서는 어떻게 해야 할까요? \n을 줄을 바꾸고 싶은 위치에 삽입하면 됩니다.
쌍따옴표를 문자열에 입력하고자 할 때에도 쌍따옴표 앞에 역슬래시를 삽입합니다.
```

``` java
public class StringApp {
    public static void main(String[] args) {
         
        // Character VS String 
        System.out.println("Hello World"); // String
        System.out.println('H'); // Character
        System.out.println("H"); 
     
        System.out.println("Hello "+ "World");
         
        // new line
        System.out.println("Hello \nWorld");
         
        // escape
        System.out.println("Hello \"World\"");// Hello "World"
    }
}
```

## 생각해보기 

### 1) \n과 같은 제어문자들은 왜 생겨나게 된 것일까요?
```
CR, LF는 타자기에서 나온 용어입니다. 타자기에서 줄바꿈을 하려면 종이를 오른쪽으로 쭉 밀고, 다시 종이를 한 줄 만큼 위로 올립니다. 
이렇게 종이를 오른쪽으로 밀어서 처음으로 오게 하는 행동을 복귀(Carriage Return)라고 하고, 종이를 위로 올리는 행동을 개행(Line Feed)이라고 합니다.

이제 타자기는 사라지고 컴퓨터와 키보드로 대체되었지만 타자기의 흔적이 완전히 사라지지 않고 남은 것이 CR(\r)과 LF(\n)입니다.
컴퓨터에서 CR, LF는 둘 다 새 줄, 줄바꿈으로 사용되고 있으며 운영체제 별로 조금씩 차이가 있습니다.
```
### 2) \n 이외의 다른 제어문자들은 어떤 것이 있을까요?
```
\n	개행 ( 줄바꿈 )
\t	탭 ( 8 공백 )
\'	작은 따옴표 ( 싱글쿼테이션 ) 표시
\"	큰 따옴표 ( 더블쿼테이션 ) 표시 
\\	역슬래쉬 표시
```

#### 6-5. 문자열 다루기

##### 핵심 단어
- String
- length 메소드
- replace 메소드


> length와 replace
```
length는 지난 시간에서도 잠깐 보았듯이 문자열의 길이를 산출합니다. 
replace는 두 개의 인자 oldChar, newChar를 받습니다.
oldChar에는 기존의 문자열에서 바꾸고 싶은 부분을 입력하고 newChar에는 바꾸고자 하는 문자열을 입력합니다.
```
 

- Data_and_operation 프로젝트에서 StringOperation 클래스를 생성합니다.

``` java
public class StringOperation {
    public static void main(String[] args) {
         
        System.out.println("Hello World".length()); // 11
        System.out.println("Hello, [[[name]]] ... bye. ".replace("[[[name]]]", "duru"));
        //즉 이 경우 기존의 "Hello, [[[name]]] ... bye" 문자열에서 "[[[name]]]" 부분을 "duru" 문자열로 치환합니다.
        //이렇게 문자열에서는 문자열의 길이를 알아내거나, 문자열의 일부를 조작하는 등의 연산을 수행할 수 있습니다.
    }
}
```

## 생각해보기  

### 1) length와 replace외에 String 데이터에서 처리할 수 있는 명령들을 댓글로 공유해 보세요.
### 2) 이러한 명령들로 어떤 일을 할 수 있을까요?
char charAt(int index), int compareTo(String str), String trim(), isEmpty(), String toUpperCase() 등 많습니다.
자세한 설명은 아래 사이트에서 참조해서 알아봅시자.
[참고하기](http://www.tcpschool.com/java/java_api_string)


## CHAPTER 8

#### 8-1. 변수의 정의

##### 핵심 단어
- **변수**(variable)
- 데이터 타입

- Data_and_operation 프로젝트에서 Variable 클래스를 생성합니다.

``` java
public class Variable {
    public static void main(String[] args) {    
        int a = 1; // Number -> integer  ... -2, -1 , 0, 1, 2 ...
        System.out.println(a);
         
        double b = 1.1; // real number -> double ... -2.0, -1.0, 0, 1.0, 2.0 ...
        System.out.println(b);
         
        String c = "Hello World";
        System.out.println(c);
    } 
}
```

## 생각해보기 

### 1) 컴퓨터 프로그래밍 언어에서 변수는 수학에서의 변수와 어떻게 다른가요?
```
- 수학에서 변수는 x라고 x^2 -2x+1 = 0; 이라고 가정하면 x의 값을 구하는 값이라고 생각하면됩니다. (x-1)^2여서 x=1값이라는 것을 구하는 것이지요.
- 컴퓨터에서 변수란 변수(variable) 란 데이터(data)를 저장하기 위해 프로그램에 의해 이름을 할당받은 메모리 공간을 의미합니다.
즉, 변수란 데이터(data)를 저장할 수 있는 메모리 공간을 의미하며, 이렇게 저장된 값은 변경될 수 있습니다.
```
### 2) 자바에서는 왜 변수의 데이터 타입을 지정하는지 댓글로 설명해 보세요.
- 컴퓨터의 판단에서, 변수에 타입에 따라서 값이 정해지고 값이 버려지고 어떤 문자인지 숫자인지, 참인지, 거짓인지 판단을 할 수 있습니다.

### 3) 자바에서 숫자 데이터의 세부적인 분류에 대해 더 알아보세요.
``` java
자바에서는 다음과 같이 8가지 종류의 기본형 변수를 제공하고 있습니다. 

- 정수형 : byte, short, int, long
- 실수형 : float, double
- 문자형 : char
- 논리형 : boolean
```
[각각의 정수형 타입 범위와 메모리 크기값 참고](http://www.tcpschool.com/java/java_datatype_basic)

### 4) 자바에서 변수의 데이터 타입을 바로바로 판단할 수 있다는 것은 어떤 편의성을 가질 수 있을까요?
- 2번과 동일한 답이라고 생각합니다.

#### 8-2. 변수의 효용

- 코드의 가독성과 재사용을 위해서 여러 방법이 쓰일 수 있지만 변수를 이용하는 것이 그 중에서도 중요한 수단 중 하나입니다.

##### 핵심 단어
- 코드의 재사용성 :어떤 데이터는 한 두 번 사용되지만, 수백 번 이상 훨씬 많이 사용될 수 있습니다. 이럴 경우 변수로 만들어서 만들면 편리하게 사용할 수 있습니다.
- 코드의 가독성 : 변수의 이름을 잘 지으면 코드의 의미를 파악할 때 도움이 됩니다.

``` java
public class Letter {
    public static void main(String[] args) {
        String name = "leezche";
        System.out.println("Hello, "+name+" ... "+name+" ... egoing ... bye");
         
        double VAT = 10.0;
        System.out.println(VAT);
    }
```

## 생각해보기 

### 1) 변수의 효용과 변수를 어떻게 사용하면 좋을지 댓글로 공유해 주세요.
```
- 변수는 클린코드 같은 책에서 변수를 왜썼는지 이름이 매우 중요하다고 생각합니다. 변수만 보고 왜 썼는지 가독성(명시성)이 있어야합니다.
- 변수를 재사용성도 좋지만 딱 쓸것만 선언하여서 다른쪽에 사용못하게 priavte이나 final을 써주어 명시적으로 막는게 좋을것 같습니다.

상수(constant)
상수는 변수와 마찬가지로 이름을 가지고 있는 메모리 공간으로, 이러한 상수는 선언과 동시에 반드시 초기화해야 합니다.
C++에서는 const 키워드를 사용하여 상수를 선언하지만, 자바에서는 final 키워드를 사용하여 선언합니다.

변수의 이름 생성 규칙

자바에서는 변수뿐만 아니라 클래스, 메소드 등의 이름을 짓는데 반드시 지켜야 하는 공통된 규칙이 있습니다.
자바에서 이름을 생성할 때에 반드시 지켜야 하는 규칙은 다음과 같습니다.
1. 변수의 이름은 영문자(대소문자), 숫자, 언더스코어(_), 달러($)로만 구성할 수 있습니다.
2. 변수의 이름은 숫자로 시작할 수 없습니다.
3. 변수의 이름 사이에는 공백을 포함할 수 없습니다.
4. 변수의 이름으로 자바에서 미리 정의된 키워드(keyword)는 사용할 수 없습니다.
```
#### 8-3. 데이터 타입의 변환 - casting

- 자바에서 변수를 만들 경우에는 데이터 타입을 명시적으로 알려주어야 합니다.

##### 핵심 단어

- 데이터 타입 변환(Casting) : 다른 데이터 타입으로 컨버팅 해주는 것이다.

- Data_and_operation 프로젝트에서 Casting 클래스를 생성합니다.

``` java
public class Casting {
    public static void main(String[] args) {       
        double a = 1.1;
        double b = 1; //1.0으로 담김
        double b2 = (double) 1; 

        System.out.println(b);
         
        // int c = 1.1; // 정수값이므로 실수값은 버린다.
        double d = 1.1;
        int e = (int) 1.1;
        //실수 1.1을 정수로 변환하기 위해서는 데이터 타입을 명시적으로 변경해 주어야 합니다.
        System.out.println(e);
         
        // 1 to String 
        String f = Integer.toString(1);
        //이렇게 Integer 객체의 toString 메소드를 이용하면 숫자를 문자열로 변환할 수 있습니다.
        System.out.println(f.getClass());
    }
}
```

## 생각해보기 

### 1) Casting에 대해서 알게 된 것을 댓글로 정리해 보세요.
- 캐스팅은 하나의 변수타입을 다른 변수 타입으로 변화게 해주는 것입니다.

### 2) 실수를 문자열로 변환하려면 어떻게 해야 할까요?

-  문자 -> 숫자 
``` java
1. String to Int
String s_num = "10";
int i_num = Integer.parseInt(s_num); //String -> Int 1번방식
int i_num2 = Integer.valueOf(s_num); //String -> Int 2번방식


2. String to Double, Float
String s_num = "10";
double d_num = Double.valueOf(s_num); //String -> Double
float f_num = Float.valueOf(s_num); //String -> Float

3. String to Long, Short 
String s_num = "10";
long l_num = Long.parseLong(s_num); //String -> Long
short sh_num = Short.parseShort(s_num); //String -> Short
```

- 숫자 -> 문자 
``` java
1. Int to String
int i_num = 10;
String s_num;
		
s_num = String.valueOf(i_num); //문자 -> 숫자 1번방식
s_num = Integer.toString(i_num); //문자 -> 숫자 2번방식
s_num = ""+i_num; //문자 -> 숫자 3번방식

2. Double Float to String
float f_num = 10.10;
double d_num = 10.10;
		
String s_num;

s_num = String.valueOf(f_num); //Float -> String 1번방식
s_num = Float.toString(f_num); //Float -> String 2번방식
		
s_num = String.valueOf(d_num); //Double -> String 1번방식
s_num = Double.toString(d_num); //Double -> String 2번방식
```

### 3) 정수 1과 정수 2를 나누었을 때 우리가 원하는 값이 나오게 하려면 어떻게 해야 할까요?
- 아마 0.5가 나와야합니다. 따라서 실수형인 double을 써주어야합니다.
``` java
double num= 0;
double a = 1.0;
double b = 2.0;
num = a/b;
```
## CHAPTER 9, 10

#### 9-1. 프로그래밍이란 무엇인가

- 해당 프로그램은 1, 2 ,3 순차적으로 실행
``` java
public class Program {
    public static void main(String[] args) {
        System.out.println(1);
        System.out.println(2);
        System.out.println(3);
    }
}
```
## 생각해보기 

### 1) Progamming의 의미를 댓글로 공유해 보세요.
```
컴퓨터에서 프로그램도 마찬가지로 시간에 따라 실행할 작업들의 순서를 의미합니다.
이렇게 시간에 따라 컴퓨터가 정해진 순서에 작업을 실행하게 된다면 우리는 업무를 자동적으로 처리할 수 있게 됩니다.
컴퓨터 언어를 이용해서 프로그램을 만드는 것은 업무의 자동화된 처리를 위해서라고 할 수 있습니다.
```

#### 10. 디버거

- 이클립스에서 디버거를 사용하는 법을 알아봅니다.

## 생각해보기 

### 1) 디버거와 관련된 아이콘들의 역할을 댓글로 정리해 보세요
- 툴이 다다르고 강의에서 설명이 되어있으므로 제외하겠습니다.

### QUiZ 2 정리

1. 다음 Java 메서드는 어떤 결과값을 출력할까요? System.out.println("10" + "0") -> 답 : 100
2. 다음 중 Java 에서 사칙 연산자가 아닌 것은 무엇일까요? 답 : x
3. Java 에서 사용하는 문자열을 관리하기 위한 타입은 무엇일까요? 답 : Sring
4. 다음 코드는 어떤 결과를 출력하게 될까요? System.out.println("Hello" + "Nice\n" + "To meet you"); 답 : Hello Nice (줄바꿈) To meet you
5. 다음 코드는 어떤 결과를 출력하게 될까요? System.out.println("Hello! [name]. Do you know \"Java\"?".replace("[name]", "John")); 답: Hello! John. Do you know "Java"?
6. 다음 중 Java 가 정수를 다루기 위해 사용하는 타입은 무엇일까요? 답 : int
7. 다음 코드의 출력 결과는 어떻게 될까요? 답 : boostcourse (줄바꿈) hello, 메모 ) System.out.println은 줄바꿈 출력이다.
``` java 
String name = "boostcourse";
System.out.println(name);
name = "hello";
System.out.println(name);
```
8. 다음 중 Java 가 실수를 다루기 위해 사용하는 타입은 무엇일까요? 답: double
9. 프로그래밍에서 버그는 수정하기 위한 행위를 뭐라고 할까요? 답: 디버그
10. 디버그에서 중요한 기능으로 중간에서 흐름을 멈추기 위한 기능은 무엇일까요? 답: breakpoint




