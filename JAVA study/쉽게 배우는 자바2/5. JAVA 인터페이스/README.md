# 5. JAVA 인터페이스 강좌

##  1. 수업소개

- 핵심 단어
```
인터페이스
```

``` java

interface Calculable {
	int sum(int v1, int v2);
}
class RealCal implements Calculable {

	public int sum(int v1, int v2) {
		return v1 + v2;
	}	
}
//인터페이스(Interface)를 이용하면 앞으로 만들 클래스의 메소드 규격을 선언할 수 있습니다.
```

인터페이스에서 이를 이용해서 만들 클래스의 메소드의 형식을 미리 선언하고, 
인터페이스를 이용해서(implements 키워드) 만드는 클래스는 인터페이스의 메소드를 정의합니다.



### 생각해보기
#### 1) 인터페이스는 어떻게 활용하면 좋을까요?

## 면접 질문 인터페이스, 추상클래스 정의

- 인터페이스는 무엇인가?

인터페이스는 쉽게 말하면 껍데기라고 말할 수 있고, 설계도 또는 명세라고 생각하면 된다.
모든 메소드가 추상 메소드이고, 일반 변수를 가질 수 없다. (추상 클래스와 비교해보자)
그 의미는 인터페이스를 구현한 클래스는 모든 메소드를 강제적으로 구현해야한다.
선언 시 interface 키워드를 사용한다.

- 추상 클래스는 무엇인가?

일반적으로 Java 에서 클래스는 2가지로 구분된다.
일반 클래스와 추상 클래스로 구분되어진다. (여기서 인터페이스는 클래스가 아니라는 것을 기억하고 넘어가자)
추상 클래스는 0개 이상의 추상 메소드(아직 구현되지 않은 메소드) 를 가지고, 일반 메소드, 일반 변수 또한 가질 수 있다.
그렇기에 인터페이스 역할도 하면서, 구현체도 가지고 있는 돌연변이 같은 클래스이다.
선언 시 키워드는 abstract 키워드를 사용한다.

## 차이점

- 인터페이스를 사용하는 이유는 무엇인가?

설계도라고 생각하면 된다.
하나의 규약, 즉 구체적인 약속 같은 것으로 인해 협업에 필수적이라고 볼 수 있다.
큰 프로젝트일수록 또는 개발 인원이 많을 경우 인터페이스를 통해 많은 이점을 얻게 된다.



- 추상 클래스를 사용하는 이유는 무엇인가?

상속을 강제하기 위함이다.
부모 클래스에서 정의만 해놓고, 실제 동작은 자식 클래스에서 하게 된다.
이러한 추상 클래스의 성격이 잘 반영되어진 것이 팩토리 메소드 패턴(Factory Method Pattern) 이다.



## java8에서 추상클래스, 인터페이스의 적절한 사용 케이스

- 추상클래스
관련성이 높은 클래스 간에 코드를 공유하고 싶은 경우
추상클래스를 상속받은 클래스들이 공통으로 가지는 메소드와 필드가 많거나, public 이외의 접근제어자(protected, private) 사용이 필요한 경우
non-static, non-final 필드 선언이 필요한 경우. 즉, 각 인스턴스에서 state 변경을 위한 메소드를 선언할 수 있다.

- 인터페이스
서로 관련성이 없는 클래스들이 인터페이스를 구현하게 되는 경우에 사용한다. 예를 들어, Comparable, Cloneable 인터페이스는 여러 클래스들에서 구현되는데, 구현클래스들 간에 관련성이 없는 경우가 대부분이다.
특정 데이터 타입의 행동을 명시하고 싶은데, 어디서 그 행동이 구현되는지는 신경쓰지 않는 경우.
다중상속을 허용하고 싶은 경우


## 2. 인터페이스의 형식

- 핵심 단어

```
인터페이스 : 인터페이스의 이름은 클래스와 마찬가지로 보통 첫 글자를 대문자로 만들고, 
"~을 할 수 있는" 것들의 규격이라는 의미에서 형용사의 이름을 붙이기도 합니다.
```

``` java
인터페이스에는 변수를 정의할 수도 있습니다.
다만 변수는 반드시 초기화되어야 합니다.
인터페이스를 적용한 클래스는 변수를 다시 대입할 수 없습니다.

interface Calculable {
	double PI = 3.14;
	int sum(int v1, int v2);
}
interface Printable {
	void print();
}
class RealCal implements Calculable, Printable {

	public int sum(int v1, int v2) {
		return v1 + v2;
	}

	public void print() {
		System.out.println("this is RealCal!!!");
	}	
	
}

public class InterfaceApp {

	public static void main(String[] args) {
		RealCal c = new RealCal();
		System.out.println(c.sum(2, 1));
		c.print();
		System.out.println(c.PI);
	}
}
```

## 생각해보기

### 1) 여러 인터페이스를 한꺼번에 적용받는다면 어떤 점이 좋을까요?

- 자바에서 다중 상속이 되지 않는 것이 있는 데 여러개의 인터페이스 설계를 적용할 수 있다. 하지만 객체지향 단일책임원칙에 위배될수도 있다.


## 3. 다형성

- 핵심 단어
```
다형성(polymorphism)
```

- 다형성

클래스의 인스턴스를 변수로 선언할 때, 해당 클래스의 데이터 타입으로 선언하지 않고
부모 클래스나 인터페이스를 데이터 타입으로 선언할 수도 있습니다.
이렇게 객체의 타입이 부모 클래스, 인터페이스, 자식 클래스 등 여러 형태인데도
인스턴스로 만든 객체(자식 클래스의 인스턴스)와 같이 행동하는 것을 다형성(polymorphism)이라고 합니다.


``` java

interface Calculable {
	double PI = 3.14;
	int sum(int v1, int v2);
}
interface Printable {
	void print();
}
class RealCal implements Calculable, Printable {

	public int sum(int v1, int v2) {
		return v1 + v2;
	}

	public void print() {
		System.out.println("this is RealCal!!!");
	}		
}

public class InterfaceApp {
	public static void main(String[] args) {
		Calculable c = new RealCal(); //호환성을 보장할 수 있다.
		System.out.println(c.sum(2, 1));
		c.print(); // Compile Error
		System.out.println(c.PI);
	}
}
```

## 생각해보기

### 1) 인터페이스로 변수를 선언했으면 메소드는 내용이 없는 껍데기에 불과할텐데 어떻게 작업을 수행할 수 있는 것일까요?

- 인터페이스의 구현체 클래스가 다형성으로 메소드를 구현해서 불러서 작업을 수행됩니다.


## 4. 사용설명서 속의 인터페이스

- 핵심 단어
```
인터페이스
Java API
```

- 다른 Java API속의 클래스들이 인터페이스를 어떻게 활용하고 있는지 알아봅니다.


##  생각해보기

### 1) Closeable과 AutoCloseable 인터페이스 사이의 관계는 무엇인가요?

``` java

import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class FileWriterApp {
	public static void main(String[] args) throws IOException {
		Writer fileWriter = new FileWriter("filewriter.txt");
		fileWriter.write("data 1");
		fileWriter.write("data 2");
		fileWriter.write("data 3");

		fileWriter.close();
	}
}

FileWriter 인스턴스는 초기화를 할 때 파일에 접근해서 현재 파일을 점유하고 있다는 표시를 합니다. 
다 끝낸 후에는 close 메소드를 이용해서 현재 파일에 대한 점유를 끝낸다는 표시를 합니다.
이 close 메소드는 AutoCloseable 인터페이스에 선언되어 있는 메소드입니다.
https://docs.oracle.com/javase/8/docs/api/java/lang/AutoCloseable.html
AutoCloseable에는 close 메소드 하나만 선언되어 있는데, 
FileWriter와 같이 작업에 있어서 복수의 접근을 막을 필요가 있는 경우에 해당 인터페이스를 적용합니다.
```


##  5. 수업을 마치며

- 핵심 단어
```
인터페이스
```

여러분의 클래스의 기능이 너무 많고 구획화를 할 필요가 있다면 
그 때 인터페이스를 이용해서 프로그램을 만들면 됩니다.
그리고 다른 사람과 협업을 할 때, 서로 공통적으로 적용해야 할 규격이 있을 때도 
인터페이스를 이용한다면 좋을 것입니다.

## Quiz 5

### 1. 규격을 엄격하게 준수할 수 있도록 해주는 Java 의 기능은 무엇일까요? 답: 인터페이스

### 2. 다음 코드에서 발생하는 에러를 해결하는 올바른 방법은 무엇일까요?

- 답 : CalcA 와 CalcB 클래스에 public int sum(int a, int b) 형식의 메서드를 구현합니다
 ``` java
 interface Calc {
    int sum(int a, int b);
}
class CalcA implements Calc {
    public void foo() {
        System.out.println("Foo");
    }
}
class CalcB implements Calc {

}
public class Main
{
    public static void main(String[] args) {
        CalcA calcA = new CalcA();
        calcA.foo();
    }
}
```
### 3. 다음 중 인터페이스와 상속에 대해 틀린 것은 무엇일까요? 답 : 클래스는 여러 클래스로부터 상속받을 수 있습니다

### 4. 다음 인터페이스에서 잘못된 점은 무엇일까요?

- 답 : 인터페이스의 메서드는 구현을 가질 수 없습니다
``` java
interface Calculable {
    double PI = 3.14;
    public int sum(int v1, int v2) {
        return v1 + v2;
    }
}
```

### 5. 다음 중 클래스가 데이터 타입에 따라 다양한 형태로 보여질 수 있는 성질을 뭐라고 정의할까요? 답 : 다형성

### 6. 여러분은 동료가 작업해줄 클래스를 기다리고 있습니다. 친구는 아직 작업을 마치지 못했지만, 클래스가 다음 인터페이스를 구현한다는 것을 알게 되었습니다. 여러분은 클래스의 어떤 기능들이 있다고 생각할 수 있을까요?

- 답 : isEatable 및 Eat 메서드가 있습니다

``` java
interface Food {
    boolean isEatable();
    void Eat();
}
```

### 6. 다음 중 인터페이스를 사용하기 적합한 케이스는 무엇일까요? 답 : 위의 모든 항목에서 적합합니다

```
클래스의 기능이 너무 많아져서, 선택적으로 사용자에게 제공하고 싶어질 때
다른 사람과 협업할 때, 기능을 명확히 하고 싶을 때
여러 목적의 클래스들을 공통적으로 기능적으로 묶고자 할 때
```