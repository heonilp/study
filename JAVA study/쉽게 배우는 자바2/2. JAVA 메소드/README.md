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