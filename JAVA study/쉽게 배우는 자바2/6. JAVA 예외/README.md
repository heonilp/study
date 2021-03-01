# 6. JAVA 예외

## 1. 수업소개
- 핵심 단어
```
예외(Exception)
```

- 우리의 프로그램은 여러 오류(Error)를 낼 수 있습니다.

실제로는 파일이 없다거나

나눗셈을 하는 프로그램에서 나누는 숫자에 0을 넣어서 돌린다거나,

배열을 다루는 프로그램에서 범위를 벗어난 인덱스를 호출한다거나 하는 상황이 있습니다.

이러한 경우는 자바에서는 예외(Exception)라고 부릅니다.

### 생각해보기

#### 1) 예외를 처리하는 일은 왜 생기게 될까요?

- 잘못된 입력이나 로직에 문제가 생길 때 예외를 둬서 안전한 코딩을 위해 예외 처리 하는 일을 합니다.

## 2. 예외의 발생

- 핵심 단어

```
예외(Exception)
ArithmeticException // 산술적 예외
```

- 예외가 발생하는 이유

여러 경우가 있겠지만 프로그램이 실행하는 동안에
프로그램을 만들 사람들이 설계한 모양대로 운영되지 않았기 때문일 것입니다.
이번 시간에는 예외가 발생하는 상황을 예제를 이용하여 알아봅니다.

``` java


자바에서는 숫자를 0으로 나누는 경우에 예외로 처리합니다.
실제로 실행을 시켜보면 ArithmeticException이라고 알려주고, 0으로 나누었다는 설명도 나오게 됩니다.
나누는 숫자를 이 경우에는 직접 입력하여 구현하였지만, 
나누는 숫자를 인자로 받아서 프로그램을 구동하는 경우가 있을 수 있습니다.
사용자가 입력한 값에 따라서 나누는 숫자가 결정된다면
나누는 숫자가 0이 절대 아니라는 보장이 없습니다.

public class ExceptionApp {
	public static void main(String[] args) throws ArithmeticException {
		System.out.println(1);
		System.out.println(2/0); // Run-Time Exception ArithmeticException
		System.out.println(3); 
	}
}
```


### 생각해보기

#### 1) 산술적인 연산에서 예외를 발생시키는 경우는 또 어떤 경우가 있을까요?

- 배열의 범위나 자료형의 범위 넘을 때 발생하고, 메소드나 API 매개변수 타입을 잘못 넣을 때 발생합니다.

## 3. 예외의 처리

- 핵심 단어
```
예외 처리(Exception Handling)
try catch
```

예외는 날지라도 그 뒤의 작업을 실행하기 위해서는 어떻게 해야 할까요?
try catch 문을 이용해서 예외를 처리하면
이상한 경우에도 끝까지 실행되는 튼튼한 프로그램이 됩니다.

``` java
//자바에서는 Exception 클래스를 제공하여 예외를 처리할 수 있게 도와줍니다.
//예외가 발생할 것으로 예상되는 부분을 try로 묶어서 처리하면 일단 코드를 실행합니다.
//그리고 예외가 발생하는 코드가 실행되면 그 다음 코드를 실행하지 않고
//해당 예외를 처리하는 catch 문으로 넘어갑니다.
public class ExceptionApp {
	public static void main(String[] args) throws ArithmeticException {
		System.out.println(1);
		int[] scores = {10, 20, 30};

		try {
			System.out.println(2);
			System.out.println(scores[3]); //ArrayIndexOutOfBoundsException
			// 여기까지 실행 -> catch(ArrayIndexOutOfBoundsException e)문으로 이동
			System.out.println(3);
			System.out.println(2/0); //ArithmeticException
			System.out.println(4);
		} catch(ArithmeticException e) {
			System.out.println("잘못된 계산이네요.");
		} catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("없는 값을 찾고 계시네요 ^^");
		}		
		System.out.println(5); 
	}
/*
try 문에서 발생한 ArrayIndexOutofBoundsException은 catch 문을 순회하면서
처음으로 잡히게 되는 곳인 Exception을 포괄적으로 잡는 catch 문으로 가서 코드를 실행합니다.
만약 ArrayIndexOutofBoundsException가 발생할 부분이 주석 처리 되어있다면
ArithmeticException이 발생하는데, 이 역시 catch 문을 순회하면서 
처음으로 잡히게 되는 곳인 ArithmeticException을 잡는 catch 문으로 가서 코드를 실행합니다.
*/
}
```

### 생각해보기

#### 1) 어떤 예외가 나올지 예측되지 않는 경우에는 어떻게 해야 할까요?

- RuntimeException으로 돌립니다. 그럼 여러 예외가 있으면 파악 할 수 있습니다. 

## 4. 예외의 우선순위

- 핵심 단어

```
예외
Exception 클래스
```

- Exception 클래스
```
자바의 예외도 클래스로 구현되어 있습니다.
ArithmeticException도 Java API 문서를 참고하면,
RuntimeException으로부터 상속받은 클래스라는 것을 알 수 있습니다.
또한 RuntimeException은 Exception 클래스로부터 상속받은 클래스입니다.
그래서 여러 예외가 있더라도 Exception 클래스를 이용해서 포괄적으로 처리할 수 있습니다.
또한, 예외의 처리에 있어서 catch 문의 위치도 중요합니다.
try 문에서 발생한 예외는 여러 개의 catch 문을 순서대로 거쳐가면서 
해당 catch 문의 예외가 이번에 발생한 예외와 맞는지 확인합니다.
그래서 맞다면 그 catch 문을 실행합니다.
```

### 생각해보기

#### 1) 왜 예외를 포괄적으로 처리하는 것이 좋지 않을까요?

- 예외를 포괄적으로 넣는다면 어떤 에러인지 파악이 없기 때문에 추적(트러블 슈팅)이 어렵습니다.


## 5. e의 비밀

- catch 문에 있는 e 변수는 무엇일까요?

- 핵심 단어
```
Throwable 클래스
```

- catch 문의 e 변수
```
catch 문의 변수 e도 인스턴스인데 이것을 이용해서 무엇인가 할 수 있을까요?
예외들의 인스턴스에는 예외가 발생한 원인, 어디서 발생했는지 등에 대한 정보들이 들어 있습니다.
이것들을 이용하면 프로그램의 어디서 왜 예외가 발생했는지 손쉽게 알 수 있습니다.
getMessage 메소드를 이용하면 예외 상황에 대한 디테일한 정보를 얻을 수 있습니다.

```

### 생각해보기


#### 1) 구체적으로 왜 예외 상황의 디테일한 정보를 사용자가 알게 되는 것이 좋지 않을까요?
```
이러한 정보를 통해, 코드의 내용이나 구조 등을 나쁜 의도를 가진 사람들에게 노출할 수도 있기 때문에
보통 이러한 정보를 사용자가 직접 볼 수 있게 구성하지는 않고, 
서버 측에서 로그 파일 등을 이용해 관리자만 볼 수 있게 처리합니다.
자세한 메소드의 종류는 Throwable 클래스의 설명서에서 확인할 수 있습니다. 
- 로깅시스템으로 만들어야한다
```

## 6. Checked exception vs Unchecked exception

- 핵심 단어
```
어떤 Exception은 사용자가 try catch로 잡아내지 않더라도 무사히 컴파일이 되기도 하고
어떤 Exception은 try catch 또는 메소드 단위에서 throws를 이용해서 잡지 않으면 컴파일이 되지 않습니다.

checked, unchecked Exception

```

하지만 try catch 문 등으로 잡아내지 않으면 프로그램이 컴파일도 안되는 예외들도 있습니다.

이러한 예외들을 checked Exception이라고 부릅니다.

Throwable로부터 상속된 모든 클래스에서 RuntimeException을 제외한 모든 에러와 예외들이

checked Exception에 속합니다.

checked Exception은 반드시 예외 처리를 해 주어야 합니다.

``` java


import java.io.FileWriter;
import java.io.IOException;

public class CheckedExceptionApp {

	public static void main(String[] args) {
		try {
			FileWriter f = new FileWriter("data.txt");
			f.write("Hello");
			f.close();//원래 더복잡하게 해야함
			//만약 IOException을 처리하지 않는다면 제대로 컴파일이 되지 않는 모습을 볼 수 있습니다.
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}
```

### 생각해보기

#### 1) 왜 unchecked Exception들을 컴파일 시에 체크하지 않는 것일까요?

- Unchecked Exception
```

먼저, RuntimeException을 살펴보자. 

RuntimeException은 다시말하면, Unchecked Exception이라고 말할 수 있는데, 발생할 것 같은 예외를 체크해주지 않아서 

(즉, 프로그래머의 실수로인해서) 발생하는 실수이기 때문이다.

  => Code를 잘못 만들어서 생기는 문제. 

=> 업무의 흐름보다는 core(기본)적인 부분의 에러. 

//기본이 안되있는 코드. 

=> 컴파일 하는데는 문제가 없다. 실행하면 문제가 발생함. 

```

- Checked Exception

```

Checked Exception은  Exception처리코드 여부를 compiler가 check

 - 없으면 컴파일 에러!!

=> 프로그램 실행 흐름상 예외 발생 가능성있는 상황을 표현.(로직상 나올 수 있는 상황)

=> Code상의 문제가 아니라, 실행상황에 따라 발생가능성 있는 예외.

=> 프로그램 구현 흐름상 발생할 수 있는 예외.


```



## 7. Finally와 Resource 다루기

- 핵심 단어
```
자원(Resource)
finally
```

- finally 문

try 문에서 오류가 발생하면 이후에 작업이 있더라도 catch 문으로 넘어갑니다.

그래서 자원을 놓아주는 작업을 try 문에 넣게 되면,

예외가 발생했을 때 자원을 놓아주는 작업을 하지 못하게 됩니다.

그래서 예외가 발생했든, 발생하지 않았든 자원을 일단 잡았으면 놓아주는 작업을 실행하도록 해야 합니다.

이런 경우에 사용하는 형식이 finally 문입니다.

finally 문은 try 문에서 예외가 발생했거나 발생하지 않았거나 무조건 실행됩니다.



``` java
import java.io.FileWriter;
import java.io.IOException;

public class CheckedExceptionApp {

	public static void main(String[] args) {
		FileWriter f = null;
		try {
			f = new FileWriter("data.txt");
			f.write("Hello");
			// close를 하기 전에 예외가 발생한다면 close가 실행되지 않음
			// f.close();
		} catch(IOException e) {
			e.printStackTrace();
		} finally {
			if (f != null) {
				try {
					f.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}			
		}
	}
}
```

### 생각해보기

#### 1) 자원을 붙잡는 작업과 놓아주는 작업을 하지 않는다면 어떤 일이 발생할까요?

- try : 작업을 시키는 동작.  

- catch : 에러 로깅한다.

- finally : 어떤 동작을 했거나 자원을 놓는다.

try 문에서 오류가 발생하면 이후에 작업이 있더라도 catch 문으로 넘어갑니다.

그래서 자원을 놓아주는 작업을 try 문에 넣게 되면,

예외가 발생했을 때 자원을 놓아주는 작업을 하지 못하게 됩니다.

- 붙잡는 놓아주지 않는 작업을 한다면 작업에 무한 대기가 발생한다. 

- 카프카를 예로들면 컨슈머 안놓아주면 비정상 종료시 무한대기현상 생김, 뮤텍스 세마포어 필요??

## 8. Try with Resource

- 핵심 단어

```
try-with-resource 문
```
Java SE 7부터 try-with-resource 문이 등장하여 자원 관리를 훨씬 단순하게 할 수 있게 되었습니다.

클래스가 AutoCloseable 인터페이스를 상속한다면 try-with-resource 문에 사용할 수 있습니다.

try-with-resource 문은 try 문에 괄호를 추가하여 그 안에 사용할 자원을 정의합니다.

객체를 여러 개 선언할 수도 있고, 세미콜론(;)으로 구별합니다.

객체의 정의 가장 마지막에는 세미콜론(;)을 넣지 않습니다.

전체 try 문(try, catch, finally 등)이 종료되면 생성된 인스턴스는 자동으로 종료되기 때문에

명시적으로 close를 이용해서 자원을 놓아주지 않습니다.



``` java

import java.io.FileWriter;
import java.io.IOException;

public class TryWithResource {

	public static void main(String[] args) {
		try (FileWriter f = new FileWriter("data.txt")) {
			f.write("Hello");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

```

### 생각해보기


#### 1) try-with-resource 문을 사용할 때 주의할 점은 무엇인가요?

전체 try 문(try, catch, finally 등)이 종료되면 생성된 인스턴스는 자동으로 종료되기 때문에

명시적으로 close를 이용해서 자원을 놓아주지 않습니다.

## 9. 수업을 마치며

- 핵심 단어
```
throw 구문
throws 구문
```

- throw Exception
``` java
public class MyException {

	public static void main(String[] args) {
		throw new RuntimeException("무언가 문제가 있습니다.");
	}
}

이렇게 문제 상황이 발생했을 때, throw 구문을 통해서 예외를 발생시킬 수도 있습니다.
이 경우에는 RuntimeException 객체를 이용하였지만, Exception 객체도 여러분이 직접 생성할 수도 있습니다.
```


- 메소드 단위로 예외 발생

``` java
우리가 직접 예외를 처리한다기보다는 앞으로 우리의 메소드를 사용할 누군가가 예외를 처리해 주기를 바라는 것과 같습니다.
import java.io.FileWriter;
import java.io.IOException;

public class ThrowException {
	public static void main(String[] args) throws IOException {
		FileWriter f = new FileWriter("./data.txt");
		f.write("Hello");
		f.close();
	}
}
```

## Quiz 6

1. 다음 중 예상치 못한 상황으로 프로그램 동작에 의도치않은 결과가 초래되는 현상을 뭐라고 표현할까요? 답 :예외


2. 다음 코드의 출력 결과는 어떻게 될까요? 답 : 1은 출력되지만 그 이후 예외가 발생합니다

``` java
System.out.println(1);
System.out.println(2/0);
System.out.println(3);
```

3. 예외 발생이 예상되는 상황에서 이를 대응하려면 어떤 구문을 이용해볼 수 있을까요? 답 : try catch 구문을 활용하여 예외 상황 시 동작을 정의합니다


4. 다음 코드의 출력 결과는 어떻게 될까요?(틀렸음) 답 : 1, 3, 4 가 출력됩니다

``` java
public static void main(String[] args) {
    try {
        System.out.println(1);
        System.out.println(0/0);
    } catch (ArrayIndexOutOfBoundsException e) {
        System.out.println(2);
    } catch (Exception e) {
        System.out.println(3);
    }
    System.out.println(4);
}
```

5. 다음 중 예외에 상관없이 실행되어야하는 코드는 어떤 구문을 통해 정의하는게 좋을까요? 답 : finally

6. 어플리케이션에서 직접 예외를 발생시킬 수 있도록 하는 키워드는 무엇일까요? 답 : throw
