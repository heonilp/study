
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