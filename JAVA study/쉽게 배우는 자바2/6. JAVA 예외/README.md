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
