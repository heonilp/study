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

#### 2) 왜 어떤 변수와 메소드들은 클래스에서 직접 호출하여 사용하고 어떤 것들은 인스턴스를 생성해서 사용할까요?

#### 3) 인스턴스를 생성할 수 없는 클래스도 있을까요


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
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/%EC%89%BD%EA%B2%8C%20%EB%B0%B0%EC%9A%B0%EB%8A%94%20%EC%9E%90%EB%B0%942/3.%20JAVA%20%EA%B0%9D%EC%B2%B4%EC%A7%80%ED%96%A5%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D/pc/2.PNG" width="50%"></img>
</div>


그러므로, 한 파일 안에 여러 클래스가 등장할 수도 있지만
여러 클래스를 각각 하나의 java 파일로 만들게 되면, 
프로그램의 기능별로 쪼개어서 소스 코드를 별도로 저장할 수 있게 됩니다.
실행을 담당하는 main 메소드가 들어 있는 MyOOP.java 파일,
프로그램의 실질적인 액션을 담당하는 Print.java 파일로 분리해서 
코드를 정리정돈 할 수 있게 됩니다.

### 생각해보기

#### 1) 여러 개의 클래스를 하나의 파일에 쓰는 것과, 각각 하나의 파일에 쓰는 것은 어떤 장단점이 있을까요