
# -2주차 (1월 18일 ~ 1월 24일)
## Java 프로그래밍 시작하기

- **Windows10 환경, 이클립스, 인텔리제이, JAVA**로 실습하였습니다.

# JAVA 프로그램밍 소개

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



### 2) 다른 방법으로도 자바에서 입력값을 받을 수 있을까요?