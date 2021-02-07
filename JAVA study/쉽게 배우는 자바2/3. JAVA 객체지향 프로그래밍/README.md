# 3.JAVA 객체지향 프로그래밍


## 1. 수업소개

### 핵심 단어
```
객체 지향 프로그래밍
```

- 메소드와 절차적 프로그래밍
우리는 지난 시간 메소드에 대해서 알아 보았습니다.
메소드는 언어마다
메소드(method), 함수(function), 서브루틴(subroutin), 프로시져(procedure)라는
여러 이름으로 불립니다.
이러한 메소드를 중심으로 프로그램을 만들어 나가는 프로그래밍을
절차적 프로그래밍(procedural programming)이라고 합니다.
많은 컴퓨터 언어들이 이러한 방식을 지원하고 있고, 대표적으로 C언어가 있습니다.



- 클래스와 객체 지향 프로그래밍
하지만 메소드로만 프로그램을 만드는 것에 부족함을 느낀 엔지니어들은
관련있는 변수와 메소드를 모은 수납상자와 같은 클래스라는 개념을 이용하여 
프로그램을 정리정돈하는데 이용하게 되었습니다.
이렇게 클래스를 이용해서 프로그램의 구조를 만들어 가는 방식을
객체 지향 프로그래밍(Object Oriented Programming)이라고 부릅니다.
그리고 이러한 방식을 언어 차원에서 지원하는 프로그래밍 언어를
객체 지향 언어(Object Oriented Language)라고 부릅니다.

### 생각해보기

####  1) 코드를 정리정돈 한다면 어떤 이점이 있을까요

- 책임과 구현 , 역할 등이 나눠서 코드가 정리 될것같습니다. 좀 더 알아보기 쉽고 역할 별로 정리 될 것같습니다. 

## 2. 남의 클래스 남의 인스턴스

- 핵심 단어
```
클래스
인스턴스
```

- 클래스와 인스턴스의 활용
``` java 
Math  클래스에서는 이름에 걸맞게 수학적 계산을 도와주는 여러 메소드를 포함하고 있습니다.
이전에 이용해 보았던 floor, ceil 메소드, 그리고 클래스의 필드(변수)로 PI 등이 있습니다.
이 외에도, 자연상수 E, 삼각함수, 제곱, 로그, 절대값, 난수, 반올림 등의 기능들을 할 수 있는 
여러 메소드와 변수를 포함하고 있습니다.
이러한 메소드와 변수는 인스턴스를 생성하지 않더라도 클래스에서 직접적으로 호출할 수 있습니다.



FileWriter 클래스는 파일을 열어서 원하는 내용을 입력할 수 있는 기능들을 제공합니다.
그래서 각각의 파일에 해당하는 인스턴스를 생성하여 write 메소드로 쓰기 작업을 수행하고
close 메소드로 파일을 닫습니다.
이러한 메소드와 변수는 인스턴스를 생성하여 사용하여야 하고 클래스에서 직접적으로 호출할 수 없습니다.


import java.io.FileWriter;
import java.io.IOException;
public class OthersOOP {
 
    public static void main(String[] args) throws IOException {
        // class : System, Math, FileWriter
        // instance : f1, f2
         
        System.out.println(Math.PI);
        System.out.println(Math.floor(1.8));
        System.out.println(Math.ceil(1.8));
         
        FileWriter f1 = new FileWriter("data.txt");
        f1.write("Hello");
        f1.write(" Java");
         
         
        FileWriter f2 = new FileWriter("data2.txt");
        f2.write("Hello");
        f2.write(" Java2");
        f2.close();    
        f1.write("!!!");
        f1.close();
    }
}
```


### 생각해보기

#### 1) 클래스와 인스턴스에 대해서 알게 된 것들이나 궁금한 것들을 공유해 보세요

- 클래스(Class) 란
```
- 개념
객체를 만들어 내기 위한 설계도 혹은 틀
연관되어 있는 변수와 메서드의 집합
```
- 객체(Object) 란
```
- 개념
소프트웨어 세계에 구현할 대상
클래스에 선언된 모양 그대로 생성된 실체

- 특징
‘클래스의 인스턴스(instance)’ 라고도 부른다.
객체는 모든 인스턴스를 대표하는 포괄적인 의미를 갖는다.
oop의 관점에서 클래스의 타입으로 선언되었을 때 ‘객체’라고 부른다.
```
- 인스턴스(Instance) 란

```
- 개념
설계도를 바탕으로 소프트웨어 세계에 구현된 구체적인 실체
즉, 객체를 소프트웨어에 실체화 하면 그것을 ‘인스턴스’라고 부른다.
실체화된 인스턴스는 메모리에 할당된다.

- 특징
인스턴스는 객체에 포함된다고 볼 수 있다.
oop의 관점에서 객체가 메모리에 할당되어 실제 사용될 때 ‘인스턴스’라고 부른다.
추상적인 개념(또는 명세)과 구체적인 객체 사이의 관계 에 초점을 맞출 경우에 사용한다.
‘~의 인스턴스’ 의 형태로 사용된다.
객체는 클래스의 인스턴스다.
객체 간의 링크는 클래스 간의 연관 관계의 인스턴스다.
실행 프로세스는 프로그램의 인스턴스다.
```

#### 2) 왜 어떤 변수와 메소드들은 클래스에서 직접 호출하여 사용하고 어떤 것들은 인스턴스를 생성해서 사용할까요?

- 객체(Object) VS 인스턴스(Instance) 와 1)참조
```
클래스의 타입으로 선언되었을 때 객체라고 부르고, 그 객체가 메모리에 할당되어 실제 사용될 때 인스턴스라고 부른다.
객체는 현실 세계에 가깝고, 인스턴스는 소프트웨어 세계에 가깝다.
객체는 ‘실체’, 인스턴스는 ‘관계’에 초점을 맞춘다.
객체를 ‘클래스의 인스턴스’라고도 부른다.
‘방금 인스턴스화하여 레퍼런스를 할당한’ 객체를 인스턴스라고 말하지만, 이는 원본(추상적인 개념)으로부터 생성되었다는 것에 의미를 부여하는 것일 뿐 엄격하게 객체와 인스턴스를 나누긴 어렵다.
```
#### 3) 인스턴스를 생성할 수 없는 클래스도 있을까요

- static은 객체를 생성하지 않기 때문에 인스턴스 필드나 인스턴스 메소드 사용 불가, this키워드도 불가(this의 경우 this가 가리키는 객체를 알 수 없다.)

## 3. 변수와 메소드

- 핵심 단어
```
클래스
```

``` java
class Print {
	public static String delimiter = "";
	public static void printA() {
		System.out.println(delimiter);
		System.out.println("A");
		System.out.println("A");
	}
	public static void printB() {
		System.out.println(delimiter);
		System.out.println("B");
		System.out.println("B");
	}
	public static void printAll() {
		printA();
		printA();
		printB();
		printB();
	}
}
public class MyOOP {
	
	public static void main(String[] args) {
		Print.delimiter = "----";
		Print.printAll();
		
		Print.delimiter = "****";
		Print.printAll();
	}	
}
```
### 생각해보기

#### 1) 기존의 코드에서 클래스로 추출한 코드는 어떤 특징이 있나요

- 계산식이나 구현물에 따른 클래스 명으로 지정되었고 객체 형식으로 나눴습니다.

## 4-1. 클래스 (존재 이유와 기본형식)

- 핵심 단어
```
클래스
```

- 클래스의 장점
```
클래스는 관련있는 변수들과 메소드를 묶어서 정리정돈을 할 수 있게 합니다.

구분자로 분리된 A 문자열과 B 문자열을 출력하는 메소드를

Print라는 클래스로 따로 떼어내서 만들 수 있게 되었습니다.

그래서 굳이 메소드의 이름을 printA라고 적지 않고 A라고만 적어도

Print 객체의 A메소드이기 때문에 A를 출력한다는 의미를 쉽게 유추할 수 있게 됩니다.

프로그램을 작성하는 데에도 편의성을 증진시킬 수 있게 됩니다.

```

## 생각해보기

### 1) 여러분이 발견한 클래스가 주는 또다른 장점은 무엇이 있나요?

- 상속이나 추상화 다형성, 캡슐화를 통해서 객체지향적인 특징을 가졌습니다.
- 이 부분은 전강의 자바 1에서 기록하였습니다.

## 4-2. 클래스 (형식)
- 핵심 단어
```
클래스
```


- 클래스의 형식


<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/%EC%89%BD%EA%B2%8C%20%EB%B0%B0%EC%9A%B0%EB%8A%94%20%EC%9E%90%EB%B0%942/3.%20JAVA%20%EA%B0%9D%EC%B2%B4%EC%A7%80%ED%96%A5%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D/pc/1.PNG" width="50%"></img>
</div>

클래스는 한 파일에 여러 개를 넣을 수 있지만, 
접근제어자 public은 java 파일과 같은 이름의 클래스에 하나만 붙일 수 있습니다.
우리가 public 클래스를 실행하고자 할 때, 
자바의 소스코드를 실행하고자 할 때, 소스코드 파일명과 동일한 public 클래스를 컴파일해서
그 클래스의 main 메소드를 실행하도록 약속되어 있습니다.
소스 코드를 컴파일을 할 때 그 안에 들어 있는 클래스는
아래와 같이 따로따로 하나씩 class 파일로 만들어집니다.

<div>
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/%EC%89%BD%EA%B2%8C%20%EB%B0%B0%EC%9A%B0%EB%8A%94%20%EC%9E%90%EB%B0%942/3.%20JAVA%20%EA%B0%9D%EC%B2%B4%EC%A7%80%ED%96%A5%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D/pc/2.PNG" width="30%"></img>
</div>


그러므로, 한 파일 안에 여러 클래스가 등장할 수도 있지만
여러 클래스를 각각 하나의 java 파일로 만들게 되면, 
프로그램의 기능별로 쪼개어서 소스 코드를 별도로 저장할 수 있게 됩니다.
실행을 담당하는 main 메소드가 들어 있는 MyOOP.java 파일,
프로그램의 실질적인 액션을 담당하는 Print.java 파일로 분리해서 
코드를 정리정돈 할 수 있게 됩니다.

### 생각해보기

#### 1) 여러 개의 클래스를 하나의 파일에 쓰는 것과, 각각 하나의 파일에 쓰는 것은 어떤 장단점이 있을까요

- 클래스명이나 패키지명으로 파일을 여러개 쓰면 해당 클래스를 보기가 쉽다.
- 툴이 없는 경우 하나에 쓰면 그냥 찾아보기가 쉽다.

## 6. static

핵심 단어
``` java
static
```
- static 변수와 메소드

static 변수와 메소드는 클래스에서 생성된 모든 인스턴스가 공유하는 자원입니다.
그리고 인스턴스를 만들지 않고도 클래스에서 직접 호출할 수 있습니다.

``` java 
인스턴스를 생성하지 않고 클래스에서 바로 인스턴스의 변수와 메소드에 접근할 수 없습니다.
즉 static이 아닌 변수와 메소드는 인스턴스를 생성해야 비로소 접근할 수 있게 됩니다.
 
static 변수와 메소드는 해당 클래스로 생성된 모든 인스턴스가 공유하는 자원이기 때문에
인스턴스 모두는 같은 static 변수와 메소드를 사용할 수 있습니다.
반면 static이 아닌 변수와 메소드는 인스턴스마다 고유의 값을 가지기 때문에 
인스턴스에서 변경한다고 해도 다른 인스턴스에 어떠한 영향도 끼치지 않습니다.
class Foo{
    public static String classVar = "I class var";
    public String instanceVar = "I instance var";
    public static void classMethod() {
        System.out.println(classVar); // Ok
//      System.out.println(instanceVar); // Error
    }
    public void instanceMethod() {
        System.out.println(classVar); // Ok
        System.out.println(instanceVar); // Ok
    }
}
public class StaticApp {
 
    public static void main(String[] args) {
        System.out.println(Foo.classVar); // OK
//      System.out.println(Foo.instanceVar); // Error
        Foo.classMethod();
//      Foo.instanceMethod();
         
        Foo f1 = new Foo();
        Foo f2 = new Foo();
//      
        System.out.println(f1.classVar); // I class var
        System.out.println(f1.instanceVar); // I instance var
//      
        f1.classVar = "changed by f1";
        System.out.println(Foo.classVar); // changed by f1
        System.out.println(f2.classVar);  // changed by f1
//      
        f1.instanceVar = "changed by f1";
        System.out.println(f1.instanceVar); // changed by f1
        System.out.println(f2.instanceVar); // I instance var
    }
}
```

 ### 생각해보기

#### 1) 구체적으로 어떤 경우에 static 변수와 메소드를 사용하고 어떤 경우에 static이 아닌 변수와 메소드를 이용해야 할까요?


- [참고](https://wikidocs.net/228)

- static은 보통 변수나 메소드 앞에 static 키워드를 붙여서 사용하게 된다.
``` java 
public class HousePark  {
    String lastname = "박";

    public static void main(String[] args) {
        HousePark pey = new HousePark();
        HousePark pes = new HousePark();
    }
}
박씨 집안을 나타내는 HousePark이라는 클래스이다. 위와 같은 클래스를 만들고 객체를 생성하면 객체마다 객체변수 lastname을 저장하기 위한 메모리를 별도로 할당해야 한다. 하지만 가만히 생각해 보면 HousePark 클래스의 lastname은 어떤 객체이던지 동일한 값인 "박"이어야 할 것 같지 않은가? 이렇게 항상 값이 변하지 않는 경우라면 static 사용 시 메모리의 이점을 얻을 수 있다.

```

static을 사용하는 또 한가지 이유로 공유의 개념을 들 수 있다. static 으로 설정하면 같은 곳의 메모리 주소만을 바라보기 때문에 static 변수의 값을 공유하게 되는 것이다. 다음의 예를 보면 더욱 명확하게 파악할 수 있을 것이다.


- 싱글톤 패턴 (singleton pattern)
디자인 패턴중 하나인 싱글톤에 대해서 알아보자. 여러분은 static 에 대한 개념이 생겼기 때문에 싱글톤을 이해하는것이 어렵지 않을 것이다.

싱글톤은 단 하나의 객체만을 생성하게 강제하는 패턴이다. 즉 클래스를 통해 생성할 수 있는 객체는 Only One, 즉 한 개만 되도록 만드는 것이 싱글톤이다

## 7. 생성자와 this

- 핵심 단어
```
생성자
this
```
- 생성자

지난 시간에 Print 객체를 생성할 때(인스턴스화) new Print()를 사용했었습니다.
우리는 구분자를 따로 두기 위해서 구분자마다 Print 인스턴스를 사용했던 것인데
구분자를 지정하기 위해서는 Print 인스턴스의 delimiter 필드를 직접 수정해야 했습니다.

클래스는 인스턴스를 생성할 때 클래스의 이름과 같은 이름인 생성자로 인스턴스를 만듭니다.
클래스는 따로 만들어 주지 않아도 기본 생성자를 포함하고 있습니다.
Print()와 같이 아무것도 지정하지 않는 생성자를 기본 생성자라고 합니다.
기본적으로 public 권한으로 설정되어 있어서 따로 명시하지 않아도 클래스를 만들게 되면
새로운 인스턴스를 생성할 수 있도록 만듭니다.

 
만약 처음에 인스턴스를 생성할 때부터 필드를 초기화하고 싶다면,
필드를 초기화할 수 있게 만드는 생성자를 구성할 수 있습니다.
생성자는 접근 권한을 설정할 수 있고, 리턴 타입은 명시하지 않으며,
초기화할 필드에 따라 파라미터를 설정합니다.

- this 키워드

생성자도 클래스 내부의 메소드이고, 보통 초기화할 필드를 파라미터로 넣기 때문에
생성자 내부에서 필드에 접근할 때 파라미터의 이름과 같게 되어 접근하기 어렵게 됩니다.
이 때 사용하는 예약어가 this인데, this는 인스턴스를 가리키는 예약어입니다.
this를 통해 필드를 손쉽게 사용할 수 있습니다.


### 생각해보기


#### 1) this는 무엇일까요? 인스턴스와 같은 것이라면 역시 또다른 인스턴스라는 것일까요?
- [정리 잘되었네요. 참조](https://library1008.tistory.com/4)

자바에는 this와 this() 키워드가 있는데 이 키워드는 전혀 다른 키워드이다.
짧게 설명하자면 this는 인스턴스 자신을 가르키는 참조 변수이고 this()는 생성자를 뜻한다.
this 는 위 코드처럼 생성자의 매개변수로 선언된 변수의 이름이 인스턴스 변수와 같을 때 인스턴스 변수와 지역변수를 구분하기 위해서 사용한다.
Car() 생성자 안에서의 this.color는 인스턴스 변수이고, color는 매개변수로 정의된 지역변수이다.
static 메서드에서는 this를 사용하지 못한다.

#### 2) 생성자를 만드는 방법 말고 다른 방식으로 인스턴스의 초기화를 할 수 있을까요?

- 직접 호출해서 직접 초기화하거나 직접 멤버 메소드를 만들어서 인스턴스를 불러서 초기화합니다. 

## 8-1. 활용 (클래스화), 8-2. 활용 (인스턴스화)

- 핵심 단어
```
클래스
인스턴스
```

``` java
class Accounting{
    public double valueOfSupply;
    public static double vatRate = 0.1;
    public Accounting(double valueOfSupply) {
        this.valueOfSupply = valueOfSupply;
    }
    public double getVAT() {
        return valueOfSupply * vatRate;
    }
    public double getTotal() {
        return valueOfSupply + getVAT();
    }
}
public class AccountingApp {
    public static void main(String[] args) {
        Accounting a1 = new Accounting(10000.0);      
        Accounting a2 = new Accounting(20000.0);
         
        System.out.println("Value of supply : " + a1.valueOfSupply);
        System.out.println("Value of supply : " + a2.valueOfSupply);
         
        System.out.println("VAT : " + a1.getVAT());
        System.out.println("VAT : " + a2.getVAT());
         
        System.out.println("Total : " + a1.getTotal());
        System.out.println("Total : " + a2.getTotal());
    }
}
```

## 9. 수업을 마치며

- 핵심 단어
```
상속
인터페이스
```

상속과 인터페이스


만약 여러분이 어떤 클래스와 비슷한 다른 것을 만들고 싶다면 어떻게 해야 할까요?

이 때 가능한 방법은 두 가지입니다.
우선 그 어떤 클래스의 변수와 메소드들을 모두 복사해서 만드는 방법,
그리고 상속이라는 개념을 이용하는 방법입니다.
어떤 클래스를 상속해서 새로운 클래스를 만들게 되면, 
어떤 클래스의 모든 변수와 메소드들이 기본적으로 새로운 클래스에 포함되게 되고,
만약 부족하다면 기존의 변수와 메소드를 덮어쓰거나(overiding),
아예 새로운 변수와 메소드를 추가할 수도 있습니다.

 

그리고 인터페이스는 일종의 규격과도 같은 것입니다.
우리 나라에서 사용하는 모든 전자 제품들이 220V를 이용하는 것과 마찬가지로
어떤 전자 제품들을 새로 만들지는 구체적으로 전혀 모르지만 220V를 사용한다는 규격을 정할 수 있습니다.
인터페이스도 마찬가지로, 앞으로 어떤 클래스를 만들지는 전혀 모르지만, 
그 클래스에 대한 규격을 선언하는 것입니다.


## Quiz 3

1. 다음 중 서로 연관된 메서드와 변수들을 합쳐서 그루핑을 하기 위해 만들어진 개념은 무엇일까요? 답 : 클래스

2. 다음 코드가 있습니다. Class 가 아닌 항목은 무엇일까요? 답 : main
 
``` java 
public static void main(String[] args) throws IOException {
    System.out.println(Math.PI);
    FileWriter f1 = new FileWriter("test.txt");
    f1.write("File");
    f1.close();
}
```

3. 다음 중 Class 에 변수 delimiter 를 선언하기 위한 올바른 방법은 무엇일까요? 답 : 클래스 내에 변수를 포함시켜 멤버 변수를 만듭니다

```java
class Print {
    public static void A() {
        System.out.println(delimiter);
    }
}
```

4. 여러분은 코드를 받았고, 팀원이 여러분이 필요한 코드를 MyOOP 클래스에 정의해두었다는 걸 알았습니다! 다음 중 해당 Class 를 찾을 때, 어떤 파일에 있다고 생각할 수 있을까요? 답 : MyOOP.java

5. 다음 중 Class를 원형으로, 여러 상태의 클래스가 동시에 필요할 때 만들 수 있는 일종의 복제본을 무엇이라고 할까요? 답 : 인스턴스

6. 다음 중 Print Class 의 인스턴스를 p 라는 이름으로 선언하는 올바른 방법은 무엇일까요?
- 답 : Print p = new Print();
``` java
class Print {
}
```
7. 다음 코드의 결과 값은 무엇이 나올까요? 답 : 10

``` java 
class Test {
    public static int no = 0;
}

public class Main
{
    public static void main(String[] args) {
        Test a = new Test();
        Test b = new Test();
        a.no = 10;
        System.out.println(b.no);
    }
}
```

8. 인스턴스를 생성할 때, 초기화 작업을 정의할 수 있는 방법은 다음 중 무엇일까요? 답 : 생성자

9. 다음 코드 출력 결과는 어떻게 될까요? 답: 0
``` java
class Test {
    public int no = 0;

    public void print(int no) {
        System.out.println(this.no);  // this.no 가 우선 이므로 0
    }
}

public class Main
{
    public static void main(String[] args) {

        Test a = new Test();
        a.print(10);
    }
}
```
