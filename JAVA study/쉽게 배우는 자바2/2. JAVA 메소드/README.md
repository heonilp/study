# JAVA 메소드

## 수업 소개

- 핵심 단어
```
메소드
함수
```

- 메소드

메소드는 클래스와 관련된 작업을 하는 함수입니다.
메소드를 이용하여 코드를 정리정돈하고 재사용성을 높일 수 있는 방법에 대해서 알아봅니다.

### 생각해보기

#### 1) 코드를 재사용하게 된다면 어떤 장점이 있을까요

## 2. 이미 익숙한 메소드

- 핵심 단어
```
메소드
main 메소드
```

``` java
public class FirstMethod {
 
    public static void main(String[] args) {
         
        System.out.println("Hello Method");
        System.out.println(Math.floor(1.1));
 
    }
 
}
//Math 클래스의 floor 메소드는 double 형 자료형을 받아서 올림 연산을 수행하여 double 형으로 반환합니다.

//그리고 main 메소드는 특수한 메소드로, 우리가 클래스를 실행할 때

```


### 생각해보기

#### 1) 지금까지 사용해왔던 메소드를 떠올려 보세요


## 3. 메소드의 기본 형식

- 핵심 단어
```
메소드
리팩토링
```

- 메소드를 이용한다면 쉽게 같은 코드를 재사용하고, 유지보수를 쉽게 할 수 있습니다.

``` java
public class WhyMethod {
    public static void main(String[] args) {         
        // 100000000
        printTwoTimesA();
        // 100000000
        printTwoTimesA();
        // 100000000
        printTwoTimesA();

    }
    public static void printTwoTimesA() {
        System.out.println("-");
        System.out.println("a");
        System.out.println("a");
    }
}
```

### 생각해보기

#### 1) 메소드의 활용 방법에 대해서 생각나는 것이 있다면 공유해 봅시다.

## 4. 메소드의 입력

- 핵심 단어

```
메소드
파라미터
```

- 파라미터와 아규먼트
파라미터를 통해 우리가 원하는 문자열과 구분자를 출력하는 메소드를 만들어 봅시다.

``` java
이와 같이 메소드에 파라미터를 넣어서 만들게 되면,
파라미터의 값에 따라 다른 결과를 만드는 메소드를 만들 수 있게 됩니다.

매개변수(파라미터)는 메소드 안에서 통용되는 변수입니다.
메소드를 호출할 때는 실제 데이터를 메소드의 파라미터 안에 넣게 되는데, 
이를 인자(아규먼트)라고 합니다.

이전에 로그인 프로그램에서 만들었던 것에서도 볼 수 있듯, 
main 메소드는 문자열 배열인 args 파라미터를 이용합니다.
프로그램을 실행할 때 아규먼트로 주어지는 값을 넣게 되면
args에 아규먼트 값들이 들어가게 되고, 이를 이용해서 작업을 실행하게 됩니다.

public class WhyMethod {
    public static void main(String[] args) {
                         //인자, argument
            printTwoTimes("a", "-");
            // 100000000
            printTwoTimes("a", "*");
            // 100000000
            printTwoTimes("a", "&");
            printTwoTimes("b", "!");
    }                                //매개변수,parameter 
    public static void printTwoTimes(String text, String delimiter) {
        System.out.println(delimiter);
        System.out.println(text);
        System.out.println(text);
    }
}
```

### 생각해보기

#### 1) 파라미터와 아규먼트는 무엇을 가리키는 용어인가요?
#### 2) 메소드가 파라미터로 값을 받아 들인다면 어떤 이점이 있을까요?

## 5. 메소드의 출력

- 핵심 단어
```
메소드
return
```

-  두 메소드에서 사용하는 문자열을 구성하는 메소드를 만들어서 그것을 이용하게 한다면 콘솔에 출력하거나 파일에 출력하거나 문자열 구성은 한번만 실행하지 않을까요? 그렇게 하기 위해서는 메소드가 문자열 객체를 반환하도록 만들어야 합니다.

``` java
메소드가 데이터를 반환하도록 만들기 위해서는
그렇지 않은 메소드에 비해 몇 가지 구성 요소가 필요합니다.
반환되는 데이터의 타입
return 

'return 반환값' 형식으로 입력하여 메소드가 데이터를 반환하도록 합니다.

그리고 return이 실행된 후에는 그 뒤에 실행할 코드가 메소드에 남아 있어도
더 처리하지 않고 바로 메소드를 빠져 나옵니다.

// 예제 1
public class OutputMethod {
    public static String a() {
        // ... 
        return "a";
    }
    public static int one() {
        return 1;
        //...
    }
    public static void main(String[] args) {
        System.out.println(a());
        System.out.println(one());    
    }
}

// 예제 2
import java.io.FileWriter;
import java.io.IOException;
public class WhyMethod {

	public static void main(String[] args) throws IOException {
		String out = twoTimes("a", "-");
		System.out.println(out);
		FileWriter fw = new FileWriter("out.txt");
		fw.write(out);
		fw.close();
		System.out.println(twoTimes("a", "*"));
	}
	public static String twoTimes(String text, String delimiter) {
		String out = "";
		out = out + delimiter + "\n";
		out = out + text + "\n";
		out = out + text + "\n";
		return out;
	}
}
```

 
### 생각해보기

#### 1) 공통된 작업을 추출해서 하나의 메소드로 만들게 되면 어떤 장단점이 있을까요?
#### 2) 그 장점과 단점은 어떠한 경우에도 항상 성립하나요?


## 6. 메소드의 활용

- 핵심 단어
```
메소드
```

``` java
public class AccountingApp {
	public static void main(String[] args) {
		double valueOfSupply = 10000.0;
		double vatRate = 0.1;
		double vat = valueOfSupply * vatRate;
		double total = valueOfSupply + vat;
		
		System.out.println("Value of supply : " + valueOfSupply);
		System.out.println("VAT : " + vat);
		System.out.println("Total : " + total);
	}
}

// 메소드
public class AccountingApp {
    //공급가와 부가가치세율은 모든 메소드에서 바로 접근할 수 있게
    //클래스의 static 필드로 빼내었습니다.
    // 이부분은 나중에 따로 빼서 상속으로 받는게 좋을듯!
    // 공급가액
    public static double valueOfSupply = 10000.0;
    // 부가가치세율
    public static double vatRate = 0.1;
 
    public static double getVAT() {
        return valueOfSupply * vatRate;
    }
     
    public static double getTotal() {
        return valueOfSupply + getVAT();
    }
 
    public static void main(String[] args) {
 
        System.out.println("Value of supply : " + valueOfSupply);
        System.out.println("VAT : " + getVAT());
        System.out.println("Total : " + getTotal());
    }

    //메소드 안에서 메소드를 호출할 수 있습니다.
    //main 메소드에서 여러 메소드를 호출할 수 있었던 것처럼
    //우리가 만든 메소드도 다른 메소드를 호출할 수도 있습니다.

    //이렇게 메소드를 이용해서 만든 코드는 지금의 예시에서는 큰 차이가 존재하지는 않지만 재사용성이 훨씬 높아집니다.
}
```

### 생각해보기

#### 1) 이 프로그램을 좀 더 확장성 있게 리팩토링할 수 있는 방법이 더 있을까요?


## 7. 수업을 마치며

-핵심 단어
```
클래스
OOP
```

``` java
클래스는 비슷한 연관된 일을 하는 메소드와 변수들을 묶어 그룹으로 만든 것입니다.

이러한 클래스를 틀로 하여 실제로 프로그램에서 동작하는 객체들을 인스턴스라고 합니다.

이러한 객체를 뼈대로 해서 프로그램을 만들어 가는 방식을

객체 지향 프로그래밍(OOP, Object Oriented Programming)이라고 합니다.
```


## 8. 부록 (access level modifiers)

- 핵심 단어
``` java
접근 제어
private, public, protected, default
```

``` java
public class AccessLevelModifiersMethod {

	private static void hi() {
		System.out.println("Hi");
	}
	public static void main(String[] args) {
		hi();
	}
}

class Greeting {
	private static void hi() {
		System.out.println("Hi");
	}
}

public class AccessLevelModifiersMethod {
	public static void main(String[] args) {
		Greeting.hi();
	}
}

public 과 private 과 같은 접근 제어도 비슷한 맥락으로 이해할 수 있습니다.

public 은 선풍기의 버튼들과 같이 사용자가 외부에서 선풍기의 동작을 제어하기 위해서

바깥으로 드러나서 호출할 수 있는 것들을 위해 지정합니다.

private 은 선풍기의 부품들과 전선들과 같이 동작을 위해 꼭 필요하지만, 

외부에서 굳이 알 필요도 없거나 알아서는 안되는 것들을 위해서 지정합니다.
```

### 생각해보기

#### 1) 외부에서 접근해서는 안되는 데이터나 메소드는 어떤 것들이 있을까요?


## 9. 부록 (static)

- 핵심 단어
```
static 메소드
```

그래서 static 메소드는 클래스의 메소드로, 
프로그램에서 한번만 정의됩니다. 즉 여러 개 가질 수 없는 유일무이한 메소드입니다.

반면 static이 아닌 메소드는 인스턴스의 메소드로, 
프로그램 안에서 여러 개 있을 수 있고, 그 인스턴스를 통해서 접근하는 메소드입니다.

``` java
class Print{
    public String delimiter;
    public void a() {
        System.out.println(this.delimiter);
        System.out.println("a");
        System.out.println("a");
    }
    public void b() {
        System.out.println(this.delimiter);
        System.out.println("b");
        System.out.println("b");
         
    }
    public static void c(String delimiter) {
        System.out.println(delimiter);
        System.out.println("b");
        System.out.println("b");
    }
}

public class staticMethod {
    public static void main(String[] args) {
//      Print.a("-");
//      Print.b("-");
        // instance
        Print t1 = new Print();
        t1.delimiter = "-";
        t1.a();
        t1.b();
        Print.c("$");    
//      Print.a("*");
//      Print.b("*");
        Print t2 = new Print();
        t2.delimiter = "*";
        t2.a();
        t2.b();
    }
}
static 메소드인 c는 Print클래스를 통해서 접근할 수 있습니다.

Math클래스의 floor 메소드는 클래스를 통해서 접근하는 static 메소드입니다.

하지만 static 메소드가 아닌 a와 b는 인스턴스 t1, t2를 생성해서

인스턴스를 통해 접근할 수 있는 메소드입니다. 

String의 equals 메소드는 인스턴스를 통해 접근할 수 있는 인스턴스 메소드입니다.

static 키워드는 필드에도 적용됩니다.

```

### 생각해보기

#### 1) 왜 static 메소드가 필요할까요?



## quiz2

- 1. 다음 중 메서드의 설명이 아닌 것은 무엇일까요? 답 : 메서드라는 개념은 존재하지 않습니다.

- 2. 다음 중 메소드가 아닌 코드는 무엇일까요? 답 : int a = 0; (변수 초기화)

- 3. 우리는 다음 메서드를 정의해보았습니다. print 메서드의 호출 결과는 무엇일까요? 답 : "Hello"
``` java
public static void print() {
    System.out.print("Hello");
}
```

- 4. 다음과 같은 메서드가 있습니다. 다음 myfunc 메서드의 출력 결과는 무엇일까요? 답 : a, b 를 입력받아 a+b 를 반환합니다
``` java
public static int myfunc(int a, int b) {
    return a + b;
}
```

5. 다음과 같은 코드가 있습니다. 코드는 어떤 값을 출력할까요? 답 : "Hello:Hello"
``` java
public static String twoTimes(String value) {
    return value + ":" + value;
}

public static void main(String[] args) {
    System.out.println(twoTimes("Hello"));
}
```

6. 다음 메서드의 출력 결과는 무엇일까요? 답 : "Plus!"
``` java
public class Main
{
    public static void Foo(int val) {
        if (val >= 0) {
            System.out.println("Plus!");
        } else {
            System.out.println("Minus!");
        }
    }
        public static void main(String[] args) {
            Foo(0);
        }
}
```

7. 다음 메서드 출력결과는 무엇일까요?  답 : 1000
``` java
public class Main
{
    public static void Foo(int idx) {
        int[] numbers = { 10, 100, 1000, 10000 };
        System.out.println(numbers[idx]);
    }
        public static void main(String[] args) {
            Foo(2);
        }
}
```

8. 다음 중 메서드가 제공해줄 수 있는 이점이 아닌 것은 무엇일까요? 답: 코드가 자동으로 생성됩니다.

- 코드의 재사용이 가능해집니다.
- 코드의 수정이 용이해집니다.
- 코드의 관리가 쉬워지며, 안정성이 증가합니다.
- 코드가 자동으로 생성됩니다.







