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
