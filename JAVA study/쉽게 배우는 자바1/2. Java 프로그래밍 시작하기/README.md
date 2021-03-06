
# -2주차 (1월 18일 ~ 1월 24일)
## Java 프로그래밍 시작하기

- **Windows10 환경, 이클립스, 인텔리제이, JAVA**로 실습하였습니다.

# 이번강의 / 자주 나오는 JAVA 면접 질문

## 1. 객제지향과 객체 지향의 특징 4가지를 말해보세요

- 객체 지향 프로그래밍(영어: Object-Oriented Programming, OOP)은 컴퓨터 프로그래밍의 패러다임의 하나 절차지향(C)언어에서는 각 명령어의 실행 순서를 기반으로 바라 보는 시선이었다.
- 하지만 OOP는 데이터와 이를 처리하는 루틴들을 하나의 **독립된 객체**로 바라 보는 시선이다.
- 이를 통해서 큰 프로젝트에 많이 사용된다. 그 이유는 **재사용성의 증가**이다. 
- 하지만 생성자, 소멸자, 접근제어[Public, Private, Protected] 와 같은 내용은 이러한 오류를 잡아준다. 

1. 추상화(Abstraction)
``` java
어떤 영역에서 필요로 하는 속성이나 행동을 추출하는 작업
사물들의 공통된 특징, 즉 추상적 특징을 파악해 인식의 대상으로 삼는 행위를 말한다.
구체적인 사물들의 공통적인 특징을 파악해서 이를 하나의 개념(집합)으로 다루는 수단을 말한다.
즉, 기본적으로 들어갈 정보들을 생각 할 수있을 것이다. 그리고 구체화 시켜 나가는 것이다.
추상화를 통해서 Class(틀)를 만들어 놓고 상세한 부분들을 채워 나가는 것이다.
```

2. 캡슐화(Encapsulation)
``` java
객체의 내용 중 숨기고 싶은 부분은 외부에서 접근 할 수 없다.
단지 해당 객체내의 함수에 의해서만 접근 가능 하도록 하는 것이다. 이를 통해서 정보 은닉이 가능해진다. 
앞서 말한 접근제어[public, private, protected]와 같은 내용에 의해서 구현 되어진다. 
```

3. 상속(Inheritance)

``` java
Class의 멤버(데이터)와 함수를 다른 Class에 물려주거나, 물려 받는 것을 말한다.

1.코드의 재사용을 증대 시킬 수있다. 같은 기능을 또 구현 할 필요가 없다.
2. 좀 더 폭넓게 사용 가능하다. 상속 받은 함수를 추가적으로 데이터와 함수 내용을 변경 가능.

```
4. 다형성(Polymorphism)
- **역할**과 **구현**으로 세상을 구분
- 역할 = 인터페이스
- 구현 = 인터페이스를 구현한 클래스, 구현 객체

``` java
다형성은 서로 다른 클래스의 객체가 같은 메시지를 받았을 때 각자의 방식으로 동작하는 능력이다.
다형성이 상속과 연계되어 동작하면 매우 강력한 힘을 발휘한다.
다형성과 일반화 관계는 코드를 간결하게 할 뿐 아니라 변화에도 유연하게 대처할 수 있게 한다.
다형성에는 오버로딩과 오버라이딩이 있다.
```

## 2. 오버로딩, 오버라이딩 차이점을 말씀해주세요.
- 자바에서 다형성을 지원하는 방법으로 메소드 오버로딩(Overloading) 오버라이딩(Overriding)이 있다.

- 오버로딩(Overloading) : 같은 이름의 메소드를 여러 개 가지면서 매개변수의 유형과 개수가 다르도록 하는 기술이다.

- 오버라이딩(Overriding) : 부모 클래스가 가지고 있는 메소드를 자식 클래스가 재정의 해서 사용한다.

- JAVA에서 오버로딩과 오버라이딩 예제입니다.
``` java 
//오버로딩
public class Overloadingtest {

    // test() 호출
    void test(){
        System.out.println("매개변수 없음");
    }
   
    // test에 매개변수로 int형 2개 호출
    void test(int a, int b){
        System.out.println("매개변수 "+ a + "와 " + b);
    }
   
    // test에 매개변수 double형 1개 호출
    void test(double d){
        System.out.println("매개변수 " + d);
    }
}

//오버라이딩
public class Employee{
   
    public String name;
    public int age;
   
    // print() 메소드
    public void print(){
        System.out.println("사원의 이름은 "+this.name+ "이고, 나이는" + this.age+"입니다.");
    }   
}
// Employee 상속
public class Manager extends Employee{
   
    String jobOfManage;
   
    // print() 메소드 오버라이딩
    public void print(){
        System.out.println("사원의 이름은 "+this.name + "이고, 나이는" + this.age + "입니다.");
        System.out.println("관리자 "+this.name+"은 "+this.jobOfManage+" 담당입니다.");
    }
}

```

## 3. 객체지향 5법칙 SOILD 설명해주세요 (김영한님 강의 참조)
- 클린코드로 유명한 로버트 마틴이 좋은 객체 지향 설계의 5가지 원칙을 정리

* SRP: 단일 책임 원칙(single responsibility principle)
* OCP: 개방-폐쇄 원칙 (Open/closed principle)
* LSP: 리스코프 치환 원칙 (Liskov substitution principle)
* ISP: 인터페이스 분리 원칙 (Interface segregation principle)
* DIP: 의존관계 역전 원칙 (Dependency inversion principle)

1. **SRP: 단일 책임 원칙**(single responsibility principle)

- 한 클래스는 하나의 책임만 가져야 한다.
```
• 하나의 책임이라는 것은 모호하다.
• 클 수 있고, 작을 수 있다.
• 문맥과 상황에 따라 다르다.
• 중요한 기준은 변경이다. 변경이 있을 때 파급 효과가 적으면 단일 책임 원칙을 잘 따른 것
• 예) UI 변경, 객체의 생성과 사용을 분리
```
2. **OCP: 개방-폐쇄 원칙** (Open/closed principle)

- 소프트웨어 요소는 확장에는 열려 있으나 변경에는 닫혀 있어야 한다
```
• 이런 거짓말 같은 말이? 확장을 하려면, 당연히 기존 코드를 변경?
• 다형성을 활용해보자
• 인터페이스를 구현한 새로운 클래스를 하나 만들어서 새로운 기능을 구현
```
- 지금까지 배운 역할과 구현의 분리를 생각해보자
``` java 
public class MemberService {
 private MemberRepository memberRepository = new MemoryMemberRepository();
}

public class MemberService {
// private MemberRepository memberRepository = new MemoryMemberRepository();
 private MemberRepository memberRepository = new JdbcMemberRepository();

}
```
- 위 코드의 문제점
```
• MemberService 클라이언트가 구현 클래스를 직접 선택
• MemberRepository m = new MemoryMemberRepository(); //기존 코드
• MemberRepository m = new JdbcMemberRepository(); //변경 코드
• 구현 객체를 변경하려면 클라이언트 코드를 변경해야 한다.
• 분명 다형성을 사용했지만 OCP 원칙을 지킬 수 없다.
```
-  이 문제를 어떻게 해결해야 하나?
 * 객체를 생성하고, 연관관계를 맺어주는 별도의 조립, 설정자가 필요하다

3. **LSP: 리스코프 치환 원칙** (Liskov substitution principle)

- 프로그램의 객체는 프로그램의 정확성을 깨뜨리지 않으면서 하위 타입의 인스턴스로 바꿀수 있어야 한다
 ```
 • 다형성에서 하위 클래스는 인터페이스 규약을 다 지켜야 한다는 것,
  다형성을 지원하기 위한 원칙, 인터페이스를 구현한 구현체는 믿고 사용하려면, 이 원칙이 필요하다.
 단순히 컴파일에 성공하는 것을 넘어서는 이야기 
 예) 자동차 인터페이스의 엑셀은 앞으로 가라는 기능, 뒤로 가게 구현하면 LSP 위반, 느리더라도 앞으로 가야함
```
4. **ISP: 인터페이스 분리 원칙** (Interface segregation principle)

 - 특정 클라이언트를 위한 인터페이스 여러 개가 범용 인터페이스 하나보다 낫다

 ```
 • 자동차 인터페이스 -> 운전 인터페이스, 정비 인터페이스로 분리
 • 사용자 클라이언트 -> 운전자 클라이언트, 정비사 클라이언트로 분리
 • 분리하면 정비 인터페이스 자체가 변해도 운전자 클라이언트에 영향을 주지 않음
 • 인터페이스가 명확해지고, 대체 가능성이 높아진다.
```
5. **DIP: 의존관계 역전 원칙** (Dependency inversion principle)

프로그래머는 “추상화에 의존해야지, 구체화에 의존하면 안된다.” 의존성 주입은 이 원칙을 따르는 방법 중 하나다.
```
 • 쉽게 이야기해서 구현 클래스에 의존하지 말고, 인터페이스에 의존하라는 뜻
 • 앞에서 이야기한 역할(Role)에 의존하게 해야 한다는 것과 같다. 
   객체 세상도 클라이언트가 인터페이스에 의존해야 유연하게 구현체를 변경할 수 있다! 
   구현체에 의존하게되면 변경이 아주 어려워진다.
```
 - 그런데 OCP에서 설명한 MemberService는 인터페이스에 의존하지만, 구현 클래스도 동시에 의존한다.

 ```
 • MemberService 클라이언트가 구현 클래스를 직접 선택
 • MemberRepository m = new MemoryMemberRepository();
 • DIP 위반
```

- **정리**
```
• 객체 지향의 핵심은 다형성
• 다형성 만으로는 쉽게 부품을 갈아 끼우듯이 개발할 수 없다.
• 다형성 만으로는 구현 객체를 변경할 때 클라이언트 코드도 함께 변경된다.
• 다형성 만으로는 OCP, DIP를 지킬 수 없다.
• 뭔가 더 필요하다, 일단 역햘과 구현을 나누자, DI(Dependency Injection, 의존관계, 의존성 주입) 가 필요하다
```

## 4. 업캐스팅 , 다운 캐스팅 설명해주세요.

- 면접에서 잘나오는 상속 - 업캐스팅, 다운캐스팅 정리
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

## 5. 배열(array)과 리스트의 차이점을 말씀해주세요.
```
- 배열의 특징 : 같은 자료형을 가진 변수를 하나로 나타낸것
- 연속된 메모리 공간으로 이루어짐, 인덱스와 정적표현, 지역성을 가지고 있다.
- 배열의 장점 : 인덱스를 통해 검색이 용이, 연속적이므로 메모리

- 배열의 단점 : 데이터를 삭제하더라도 배열은 연속해야되므로 공간이 남음, 메모리 낭비
- 정적이므로 배열의 크기를 컴파일 이전에 정해주어야한다. 또한, 컴파일 이후 배열의 크기를 변동 할 수 없다. 
```
```
- 리스트의 특징 : 순서가 있는 데이터의 집합, 불연속적으로 메모리 공간 차지, 동적 표현, 포인터를 통한 접근

- 리스트의 장점 : 포인터를 통해서 다음 데이터의 위치를 가리키고 있어 삽입, 삭제가 용이하다.
- 동적이므로 크기가 정해져있지않다, 메모리 재사용 편리하다, 불연속적이므로 메모리 관리의 편리

- 리스트의 단점 : 검색성능이 좋지않다. 포인터를 통해 다음 데이터를 가리키므로 추가적인 메모리 공간 발생
``` 
- 즉, 자바 ArrayList와 배열 Array 차이점을 큰 차이점을 말하자면 다음과 같다.

1. 배열은 List와 다르게 크기를 지정해야한다.

2. 객체를 일반 배열에 넣을 때는 인덱스를 지정해야한다.

3. 배열의 내부값을 이용할 때는 index 문법을 이용해야한다.

- 정리
```
- 배열 : 데이터 크기가 정해져있고, 추가적인 삽입, 삭제가 일어나지않으며 검색을 필요할 때 유리
- 리스트: 데이터의 크기가 정해져있지않고, 삽입, 삭제가 많이 일어나며, 검색이 적은 경우 유리
```

# JAVA 프로그래밍 소개
## CHAPTER 11,12

### 11-1. 입력과 출력

#### 학습 목표

- 프로그램에 입력 값을 주는 방법을 알아봅니다.
- 핵심 단어
```
입력
JOptionPane
```

- 프로그램의 입력과 출력

<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/%EC%89%BD%EA%B2%8C%20%EB%B0%B0%EC%9A%B0%EB%8A%94%20%EC%9E%90%EB%B0%941/2.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0/pc/1.png" width="50%"></img>
</div>


- 프로그램의 입력과 출력 : 아래 도식과 같이 프로그램은 입력정보를 받아서 출력을 하는 것이라고 할 수 있습니다.


- 예제 보기 OkJavaGoInHomeInput.java

``` java
import javax.swing.JOptionPane;
import org.opentutorials.iot.DimmingLights;
import org.opentutorials.iot.Elevator;
import org.opentutorials.iot.Lighting;
import org.opentutorials.iot.Security;
 
public class OkJavaGoInHomeInput {
    public static void main(String[] args) {
         
        String id = JOptionPane.showInputDialog("Enter a ID");
        String bright = JOptionPane.showInputDialog("Enter a Bright level");
         
        // Elevator call 
        Elevator myElevator = new Elevator(id);
        myElevator.callForUp(1);
         
        // Security off 
        Security mySecurity = new Security(id);
        mySecurity.off();
         
        // Light on
        Lighting hallLamp = new Lighting(id+" / Hall Lamp");
        hallLamp.on();
         
        Lighting floorLamp = new Lighting(id+" / floorLamp");
        floorLamp.on();
         
        DimmingLights moodLamp = new DimmingLights(id+" moodLamp");
        moodLamp.setBright(Double.parseDouble(bright));
        moodLamp.on();
    
}
```


## 생각해보기 

### 1) 입력값을 사용했을 때의 장점과 어떤 입력값이 존재할 수 있을지 댓글로 토론해 보세요
- 입력값을 사용했을 때 입력값에 따라 출력 값이 다르므로 동적인 프로그램이 될수 있을 것입니다.
- 입력값은 숫자, 문자부터, 파일, 소리, 사진, json, xml 등등 다양 할 것 같습니다.

### 2) 다른 방법으로도 자바에서 입력값을 받을 수 있을까요?
- Scanner, read, [I/O 입출력 클래스의 종류](https://hyeonstorage.tistory.com/250) 등 여러가지 방법으로 입력값을 받을 수 있다.
- Stream으로 끝나는 클래스 : 바이트 단위로 입출력을 수행하는 클래스
- Reader / Writer로 끝나는 클래스 : 캐릭터 단위로 입출력을 수행하는 클래스
- File로 시작하는 클래스 : 하드디스크의 파일을 사용하는 클래스
- Data로 시작하는 클래스 : 자바의 원시 자료형을 출력하기 위한 클래스
- Buffered로 시작하는 클래스 : 시스템의 버퍼를 사용하는 클래스


- 예제 보기 - Scanner 사용

``` java
import java.util.Scanner;
public class HelloWorldApp{
    public static void main(String[] args){
    	  String message;
          Scanner scan = new Scanner(System.in);      // 문자 입력을 인자로 Scanner 생
          System.out.println("메시지를 입력하세요:");        
          message = scan.nextLine();            // 키보드 문자 입력
          System.out.println("입력 메시지: \""+ message + "\"");
          int kilometer;
          System.out.println("거리(km) 값 정수를 입력하세요 : ");
          
          kilometer = scan.nextInt();        // 키보드 숫자 정수 입력
          System.out.println("km: \""+ kilometer + "\"km");
    }
}
```


- 예제보기 - char를 입력 받을 때는 (char)System.in.read 메서드를 이용

``` java
import java.io.IOException; // read는 throws IOException를 써주지않으면 에러가 난다.
public class HelloWorldApp {
    public static void main(String[] args) throws IOException {
         
        //char를 입력 받을 때는 (char)System.in.read 메서드를 이용한다.
        char ch; //int형 으로 해서 아스키코드 같은 것 받으면 좋다.
        ch = (char)System.in.read();
        System.out.println(ch);        
    }
}
```


### 11-2. 입력과 출력 - arguments & parameter

- 핵심 단어
```
아규먼트(argument)
파라미터(parameter)
배열(array)
```

- Run 버튼의 팝업 버튼을 클릭하여 Run Configurations 메뉴를 클릭합니다.
- Argument 탭에서 Program arguments에 위와 같이 입력합니다.
- 만약 작은따옴표로 동작하지 않는다면 큰따옴표로 시도합니다.

- 아규먼트를 입력하게 되면 main 메소드의 args 파라미터는 아규먼트 값을 받아서 동작하게 됩니다.
- args는 문자열 배열(array)로 여러 개의 String 데이터가 들어있을 수 있습니다.
- 인덱스를 통해 배열의 데이터를 꺼내 쓸 수 있고, 인덱스는 0번부터 시작합니다.

## 생각해보기 

### 1) argument와 parameter에 대해서 댓글로 토론해 보세요

- 매개변수(parameter, 파라미터)
``` java 
int sum(int a, int b){ // 파라미터

    return a+b;
}
```

- 전달인자(argument, 아규먼트)
``` java
void sum
{
    sum(10 ,20); //전달인자 : 매개변수에 대입하는 값
}
```

### 2) 배열은 무엇일까요?

- 동일한 자료형(Data Type)의 데이터를 연속된 공간에 저장하기 위한 자료구조이다. 즉, 연관된 데이터를 그룹화하여 묶어준다고 생각하면 된다. 
- 배열의 장점
  * 연관된 데이터를 저장하기 위한 변수의 선언을 줄여주며, 반복문 등을 이용하여 계산과 같은 과정을 쉽게 처리할 수 있다.

- 선언
``` java 
int[] i= new int[8]; //초기값 0
String[] s = new String[8]; //초기값 ""
```

- 배열의 초기화
``` java
//배열에 특정값 대입하며 선언
int[] i = {1,2,3,4,5};
String[] s = {"a","b","c","d"};
		
//배열의 주소를 모두 같은값으로 초기화
Arrays.fill(i,1);//i의 모든 index값을 1로 초기화
	
//for문을 통해 값을 대입
for(int m=0;i<i.length;m++) {
    i[m]=m;
}

//foreach문을 통한 배열출력
for(int m:i) {
    System.out.print(m);
}	
```

[Array 배열 참고 사이트- 점프 투 자바](https://wikidocs.net/206)


### 12-1. 직접 컴파일-실행 - 소개
### 12-2. 직접 컴파일-실행 - 실행환경 살펴보기
### 12-3. 직접 컴파일-실행 - 컴파일과 실행하기


- 지난주에 실습

```
윈도우면 cmd, 리눅스면 해당 경로 프로젝트 디렉토리에 감
패키지 시작부분으로 이동
javac 이름.java, 이름.class 파일이 만들어지면 컴파일에 성공한거임
실행방법 java 이름
자바 내 한글이 있을경우 java -encoding utf-8 이름.java하면 됨
```

### 12-4. 직접 컴파일-실행 - 라이브러리이용
### 12-5. 직접 컴파일-실행 - 입력과 출력


- 핵심 단어
```
라이브러리(library)
아규먼트(argument)
```

- 외부 라이브러리도 포함해서 컴파일하기
```
외부 라이브러리를 포함해서 컴파일하기 위해서는 javac 명령어의 옵션 중
 --class-path(-cp) 옵션을 이용해서 외부 라이브러리도 함께 지정해야 합니다.
다음과 같이 명령어를 입력합니다.
javac -cp ".;lib" 이름.java

macOS나 Linux의 경우에는 ".;lib" 부분의 세미콜론(;)을 콜론(:)으로 바꿔서 입력합니다.
javac -cp ".:lib" 이름.java

```

-외부 라이브러리도 포함해서 실행하기

```
외부 라이브러리의 클래스들도 함께 사용하는 프로그램을 실행하기 위해서는
컴파일했을 때와 마찬가지로 --class-path 옵션에 외부 라이브러리도 포함해서 실행해야 합니다.
윈도우에서는 아래와 같이 입력합니다.
java -cp ".;lib" 이름

macOS와 Linux에서는 세미콜론이 아닌 콜론으로 바꿔서 입력합니다.
java -cp ".:lib" 이름
```

- 실행할 때 아규먼트 입력하기
```
실행할 클래스 파일 이름 다음에 연달아서 입력합니다.
java 이름 "JAVA APT 507" 15.0
```

## 생각해보기 

### 1) 라이브러리가 무엇인지 댓글로 토론해 보세요
- 한개이상의 패키지를 배포의 용이성을 위해 압축한형태
- 다른 프로그램에서 라이브러리 안에 포함된 기능을 활용할 수있다.


### 2) 라이브러리와 패키지는 무슨 차이점이 있을까요?

``` java 
패키지를 사용하는 이유 : 소스파일이 많아짐에 따라 폴더로 분류하고 싶을 때 패키지를 이용하여 기능별로 그룹화한다.
(이름이 동일한 클래스가 서로 다른 패키지에 속해있다면 충돌이 발생하지 않는다.)

package study.java.program; // 이 클래스가 어떤 패키지에 소속되어 있는지 명시.
import study.java.Ex.Article; // 다른 package에 있는 클래스를 가져온다.

classPath
작성한 코드를 주는 것이 아닌 컴파일이 완료된 .class파일을 주는 것이다.
즉, 객체를 생성할 때 대상 클래스의 소스 없이도 컴파일된 결과만 참조하여 객체 생성 및 메서드 호출이 가능해진다.

Library
전달해야할 패키지와 클래스 수가 많아질 때 Library를 이용하여 편리하게 해준다.(.jar파일을 참조)
```
## CHAPTER 13

### 13-1. 자바 문서 보는 법 - API vs UI

- 우리는 자바를 사용하여 프로그램을 만들기 위해서 자바 기본 라이브러리의 API를 이용합니다.

- 그렇게 만들어진 자바 프로그램을 사용자가 사용하기 위해서 UI를 구성합니다.

- 핵심 단어
```
API(Application Programming Interface)
UI(User Interface)
```
- API와 UI
* 우리가 자바 프로그램을 만들고 사용할 때의 단계는 아래 도식과 같습니다.

<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/%EC%89%BD%EA%B2%8C%20%EB%B0%B0%EC%9A%B0%EB%8A%94%20%EC%9E%90%EB%B0%941/2.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0/pc/2.png" width="50%"></img>
</div>

## 생각해보기 

### 1) 자바 API는 무엇인가요?
- 프로그램을 응용해서 사용할 수 있도록 제공되는 조작 방법 
- 사용자와 사용하는 인터페이스와 구분하기 위해 api라고 부른다.
### 2) API와 UI의 차이점은 무엇인가요?
- UI: User Interface
- API: Application Programming Interface

- 이 둘의 공통점은 인터페이스
- API :  **프로그래머**가 프로그램을 응용해서 사용할 수 있도록 제공되는 조작 방법
- UI : **사용자**가 어플리케이션에 대해 사람이 조작할 수 있는 조작 방법
#### 강의내용

```
우선 컴퓨터와 운영체제 위에 우리는 자바를 설치했습니다.
자바의 라이브러리에는 다양한 도구들이 있는데, 모니터에 출력했을 때 사용했던 System 객체를 비롯하여
Date, Math, PrintWriter 등 다양한 도구들이 있습니다.

우리는 자바 프로그램을 만들 때 자바의 도구들을 응용해서 우리가 원하는 작업을 시간적 순서에 따라 동작하도록 만들었습니다.
작업들의 시간적 순서에 주목해서 우리는 프로그램(Program)이라고 부르고,
도구의 응용에 주목해서 우리는 애플리케이션(Application)이라고 부릅니다.


이 때 자바는 자바의 도구들을 응용해서 사용하기 위해서 일정한 조작 장치를 구성하였는데,
이것을 자바 API(Application Programming Interface)라고 합니다.

자바 프로그램은 또 다른 자바 프로그램에서 사용될 수도 있고,
다른 프로그램에서 사용할 수 있도록 만들어둔 장치 역시 API입니다.
이렇게 만들어진 자바 프로그램은 사용자가 사용할 수 있습니다.
이 때 사용자가 자바 프로그램을 사용할 수 있도록 만들어둔 장치들을 UI(User Interface)라고 합니다.
예를 들면, 커맨드 라인 시스템의 아규먼트, 데스크톱 앱의 버튼, 웹 페이지의 링크 등이 있습니다.
```

### 13-2. 자바 문서 보는 법 - 패키지, 클래스, 변수, 메소드

- 핵심 단어
```
패키지(Package)
클래스(Class)
변수(Variable)
메소드(Method)
```
- JAVA 7문서 보는 방법을 위주로 강의하고 있습니다. 이 부분은 듣기만했습니다.
- 그리고 패키지, 클래스, 변수 메소드는 중요한 개념이기 때문에 정리하겠습니다.

## 생각해보기 

### 1) 패키지, 클래스, 변수, 메소드에 대해서 댓글로 토론해 보세요

- [패키지](https://wikidocs.net/231) : 폴더를 이용하여 파일을 정리해 본 경험이 있을것이다. 파일 여러개가 한 폴더에 뒤죽박죽 섞여 있을 때 파일들을 성격에 맞게 분류한 다음 새 폴더에 저장시키는 식으로 말이다. 자바의 패키지도 이것과 완전히 동일한 개념이다. 패키지는 비슷한 성격의 자바 클래스들을 모아 넣는 자바의 디렉토리이다.

- [클래스](https://wikidocs.net/214) : 서로 연관된 변수와 메소드로 구성되고 연관된 클래스를 묶어서 정리한 것을 패키지

- [객체 변수](https://wikidocs.net/214) : Animal 클래스에 name 이라는 String 변수를 추가했다. 이렇게 클래스에 선언된 변수를 객체 변수 라고 부른다. 또는 인스턴스 변수, 멤버 변수, 속성이라고도 말한다.

- [메소드](https://wikidocs.net/225) : 보통 다른언어에는 함수라는 것이 별도로 존재한다. 하지만 자바는 클래스를 떠나 존재하는 것은 있을 수 없기 때문에 자바의 함수는 따로 존재하지 않고 클래스 내에 존재한다. 자바는 이 클래스 내의 함수를 메소드라고 부른다.

### 13-3. 자바 문서 보는 법 - 클래스

- 학습 목표

* 클래스의 개념에 대해서 알아봅니다.

- 핵심 단어
```
클래스(Class)
변수(Variable/Field)
메소드(Method)
```

- 클래스: 서로 연관된 변수와 메소드로 구성되고 연관된 클래스를 묶어서 정리한 것을 패키지
- 자바에서는 수학과 관련된 Math 클래스를 제공합니다.
- ClassApp 클래스

``` java 
public class ClassApp {
 
    public static void main(String[] args) {
         //Math 클래스에는 수학과 관련된 여러 변수들과 메소드들이 있습니다
        System.out.println(Math.PI); //우선 PI 변수는 원주율이 적절한 정밀도로 저장되어 있는 변수입니다.
        System.out.println(Math.floor(1.6)); //floor 메소드는 특정 소수점 이하에 대해서 버림한 값을 산출합니다.
        System.out.println(Math.ceil(1.6)); //ceil 메소드는 특정 소수점 이하에 대해서 올림한 값을 산출합니다
    } 
}
```
## 생각해보기 
### 1) 클래스가 무엇인지 댓글로 토론해 보세요

- [클래스](https://wikidocs.net/214) : 서로 연관된 변수와 메소드로 구성되고 연관된 클래스를 묶어서 정리한 것을 패키지

### 13-4. 자바 문서 보는 법 - 인스턴스

-핵심 단어
```
인스턴스(Instance)
```

- 인스턴스란: 인스턴스는 클래스를 컴퓨터 상에서 실체화한 것입니다. 

- Math 클래스와 달리 PrintWriter 객체는 new 키워드를 통해 인스턴스를 생성하여 사용합니다.
``` java
PrintWriter p1 = new PrintWriter("result1.txt");
```

``` java
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
public class InstanceApp {
 
    public static void main(String[] args) throws IOException{
         
        PrintWriter p1 = new PrintWriter("result1.txt");
        p1.write("Hello 1");
        p1.close();
         
        PrintWriter p2 = new PrintWriter("result2.txt");
        p2.write("Hello 2");
        p2.close();

    }
 
}
```

## 생각해보기 

### 1) 인스턴스와 클래스는 무슨 관계인가요?

``` java
public class Animal {

}
Animal cat = new Animal();
```
- new 는 객체를 생성할 때 사용하는 키워드이다. 이렇게 하면 Animal 클래스의 인스턴스(instance)인 cat, 즉 Animal의 객체가 만들어진다.

- ※ 객체와 인스턴스
```
클래스에 의해서 만들어진 객체를 인스턴스라고도 한다. 그렇다면 객체와 인스턴스의 차이는 무엇일까? 
이렇게 생각 해 보자. Animal cat = new Animal() 이렇게 만들어진 cat은 객체이다. 그리고 cat이라는 객체는 Animal의 인스턴스(instance)이다.
즉 인스턴스라는 말은 특정 객체(cat)가 어떤 클래스(Animal)의 객체인지를 관계위주로 설명할 때 사용된다. 
즉, "cat은 인스턴스" 보다는 "cat은 객체"라는 표현이 "cat은 Animal의 객체" 보다는 "cat은 Animal의 인스턴스" 라는 표현이 훨씬 잘 어울린다.
```


### 13-5. 자바 문서 보는 법 - 상속

- 클래스 사이에도 계층적인 관계가 존재합니다.

- 핵심 단어
```
상속(Inheritance)
```

- 클래스의 상속관계
```
클래스 간에는 서로 계층적인 관계를 갖고 있을 수 있습니다.
```
- 클래스 간의 상속관계의 특성
```
자식에 해당하는 클래스는 부모에 해당하는 클래스의 모든 변수와 메소드를 사용할 수 있습니다.
```

- PrintWriter는 Writer를 확장해서 만들어진 클래스이고, Writer는 Object를 확장해서 만들어진 클래스입니다.
 
<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/%EC%89%BD%EA%B2%8C%20%EB%B0%B0%EC%9A%B0%EB%8A%94%20%EC%9E%90%EB%B0%941/2.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0/pc/3.PNG" width="50%"></img>
</div>

- 그래서 PrintWriter 클래스는 Writer의 write 메소드를 사용할 수 있고, Object의 toString 메소드를 사용할 수 있습니다.
- Object 클래스는 모든 클래스의 부모로 모든 클래스는 Object의 변수와 메소드를 상속받습니다.

- 면접에서 잘나오는 상속 - 업캐스팅, 다운캐스팅 정리
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


## 생각해보기 

### 1) 상속이란 무엇인지 댓글로 적어 보세요

- 자바 객체지향의 특성 중에 하나로서 상속은 자식 클래스가 부모 클래스의 성질을 물려받는 것입니다.
- 자식에 해당하는 클래스는 부모에 해당하는 클래스의 모든 변수와 메소드를 사용할 수 있습니다. 자세한것 위에 설명되어 있습니다.

## 퀴즈 3

<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/%EC%89%BD%EA%B2%8C%20%EB%B0%B0%EC%9A%B0%EB%8A%94%20%EC%9E%90%EB%B0%941/2.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0/pc/4.PNG" width="50%"></img>
</div>

1. 프로그램의 입력값으로 전달되어질 수 있는 Input 값은 일반적으로 뭐라고 표현할 수 있을까요? 답: 매개변수
2. 다음 중 Java 컴파일을 위해 사용되는 프로그램은 무엇일까요? 답: javac
3. java 파일을 컴파일하면 어떤 결과물이 산출될까요? 답: .class
4. 외부에서 만들어진 정리정돈된 소스 코드를 사용하고자 합니다. 어떤 개념을 찾아보면 좋을까요? 답: 라이브러리
5. 다음과 같은 Java 프로그램이 있습니다. 주어진 Input 에 대해 어떤 결과가 출력될까요? 답: Name
``` java 
> 코드 public static void main(String[] args) {
System.out.println(args[2]);
}
> 실행 java Main "Hello Java" "My " "Name" "is" "World"

```
6. 프로그램을 응용해서 사용할 수 있도록 제공되는 조작 방법을 뭐라고 할까요? 답: API 
7. 어플리케이션에 대해 사람이 조작할 수 있는 조작 방법을 뭐라고 할까요? 답: UI
8. 다음 중 Class 를 정의한 가장 가까운 설명은 무엇일까요? 답: 서로 연관된 변수와 메서드를 그루핑한 개념
9. 다음 중 인스턴스를 생성하고 할당해주는 Java 의 키워드는 무엇이 될까요?: 답: new
10. 다음 중 클래스 간에 속성을 계층적으로 재사용하고 물려주기 원할 때 사용할 수 있는 기능은 무엇일까요? 답: 상속

