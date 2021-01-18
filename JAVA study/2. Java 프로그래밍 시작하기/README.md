
# -2주차 (1월 18일 ~ 1월 24일)
## Java 프로그래밍 시작하기

- **Windows10 환경, 이클립스, 인텔리제이, JAVA**로 실습하였습니다.

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
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/2.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0/pc/1.png" width="30%"></img>
</div>


- 프로그램의 입력과 출력 : 아래 도식과 같이 프로그램은 입력정보를 받아서 출력을 하는 것이라고 할 수 있습니다.

<details>
<summary>예제 보기 OkJavaGoInHomeInput.java</summary>

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
</details>

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

<details>
<summary>예제 보기 - Scanner 사용</summary>

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
</details>
<details>

<summary>예제보기 - char를 입력 받을 때는 (char)System.in.read 메서드를 이용</summary>

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
</details>

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

### 2) 라이브러리와 패키지는 무슨 차이점이 있을까요?


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
<img src="https://github.com/heonilp/study/blob/master/JAVA%20study/2.%20Java%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0/pc/2.png" width="30%"></img>
</div>

## 생각해보기 

### 1) 자바 API는 무엇인가요?
### 2) API와 UI의 차이점은 무엇인가요?
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

### 13-3. 자바 문서 보는 법 - 클래스

### 13-4. 자바 문서 보는 법 - 인스턴스

### 13-5. 자바 문서 보는 법 - 상속
