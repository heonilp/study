# JAVA 제어문


- 핵심 단어
```
제어문
boolean data type
비교 연산
조건문
반복문
```

## 1. 수업소개

### 제어문

- 프로그램이란? : 컴퓨터에게 우리가 원하는 작업들을 시간 순서대로 진행하도록 명령하는 것

- 로그인 기능으로 예시를 들음

- 아이디와 비밀번호가 제대로 맞는지 확인하고, 맞거나 맞지 않다면 어떤 작업을 할지 달라질 수 있습니다.
- 이러한 작업을 위해서는 조건에 따라서 실행할 작업의 순서를 제어하는 조건문이 필요합니다.

- 같은 작업을 여러 번 반복할 경우 사용되는 것이 반복문

- 조건을 구성하기 위해서 자바에서는 Boolean 데이터 타입과, 비교 연산 기능을 제공


## 생각해보기

### 1) 작업을 반복하기 위해서 왜 조건이 필요할까요?

- for문이나 while문으로 해당 조건을 찾아서 데이터나 값을 얻어내기 위해서 조건이 필요합니다.


## 2. Boolean Datatype

- 핵심 단어
``` java 
boolean
```

- boolean
```
boolean 데이터 타입은 참과 거짓을 표현하는 데이터 타입으로, 
true와 false 키워드를 이용하여 직접 입력할 수도 있고
메소드의 리턴 값이나 비교 연산으로 도출할 수 있습니다.
```

``` java
public class BooleanApp {
    public static void main(String[] args) {
         
        System.out.println("One");
        System.out.println(1);
         
        System.out.println(true);
        System.out.println(false);
         
        String foo = "Hello world";
        // String true = "Hello world"; reserved word
        //boolean 데이터 타입은 콘솔에서 출력해보면 true, false로 출력된다는 것을 알 수 있습니다.
        //그리고 문자열 객체의 contains 메소드와 같이 결과값이 boolean 데이터 타입인 경우,
        //또는 비교 연산자를 이용해서 계산하는 경우에도 boolean 데이터 타입을 다루게 됩니다.
        System.out.println(foo.contains("world"));
        System.out.println(foo.contains("egoing"));
    }
}
```
## 생각해보기

### 1) boolean을 어떻게 활용할 수 있을까요?
- [참고](https://wikidocs.net/220)
```
참 또는 거짓의 값을 갖는 자료형을 부울 자료형이라고 한다. 자료형의 명칭은 boolean(불린 또는 불리언이라고 부른다)이다.
부울 자료형에 대입되는 값은 참(true) 또는 거짓(false)만 가능하다.
```

1. 대입연산
2. 부울연산
3. 조건문에 사용된다.

다음은 불리언 변수에 값을 대입한 예제이다.
``` java
boolean isSuccess = true;
boolean isTest = false;


2 > 1             // 참
1 == 2            // 거짓
3 % 2 == 1        // 참 (3을 2로 나눈 나머지는 1이므로 참이다.)
"3".equals("2")   // 거짓 


int base = 180;
int height = 185;
boolean isTall = height > base;

if (isTall) {
    System.out.println("키가 큽니다.");
}


int i = 3;
boolean isOdd = i % 2 == 1;

i % 2 == 1은 i를 2로 나누었을 때 나머지가 1인지를 묻는 조건문이다. 
i는 3이므로 3을 2로 나눈 나머지는 1이 되어 참이 된다. 따라서 isOdd 는 true 값을 갖게 될것이다.

```

## 3. 비교연산자


- 핵심 단어
```
비교 연산자
```

``` java
// 수학 시간에서 배우는 부등호, 등호와 같은 역할을 합니다.
public class ComparisonOperatorApp {
    public static void main(String[] args) {
        System.out.println(1 > 1); // false
        System.out.println(1 == 1); // true
        System.out.println(1 < 1);
        System.out.println(1 >= 1);    
    }
}

비교 연산자는 6가지가 있습니다.

a > b : a가 b보다 큼
a < b : a가 b보다 작음
a >= b : a가 b보다 크거나 같음 
a <= b : a가 b보다 작거나 같음
a == b : a가 b와 같음
a != b : a가 b와 같지 않음
설명에 해당하는 진술이 참이라면 true를, 아니라면 false를 산출합니다.
```

## 생각해보기

### 1) 기존에 배웠던 산술 연산자나 결합 연산자와 비교 연산자는 어떤 차이가 있나요?

- 결합 연산자는 String + String 같이 + 묶는 결합 연산자이다.

``` java 
종류 

연산자  최우선 ( ), [ ] 

단항 연산자  ++, --, +, -, (type), !, ~ 

산술 연산자 %, /, *, +, - 

시프트 연산자 >>, <<, >>> 

관계 연산자 <, <=, >, >=, ==, != 

논리 연산자 &, ^, |, ~, &&, || 

삼항 연산자 ? : 

대입 연산자 =, +=, -=, *=, %=, /=, >>=, <<= 

콤마 연산자 , 

```

## 4-1. 조건문 형식

- 핵심 단어
``` java
if 문
```

``` java 
public class IfApp {
    public static void main(String[] args) {
        System.out.println("a");
        if(false) {
            System.out.println(1);
        } else if(true) {
            System.out.println(2);
        } else {
            System.out.println(3);
        }
        System.out.println("b");
    }
}
```

``` java
if문은 다음 구성 요소로 구성됩니다.

if
조건식
코드블럭 (실행할 코드)
else if
else
if와 조건식이 필수 구성 요소이고, 나머지는 필수요소가 아닙니다.

조건식에는 boolean 타입만 들어갈 수 있습니다.


조건문은 중첩할 수 있고, 

if 와 else 는 하나의 조건문에 한 번만 들어갈 수 있지만, 

else if 는 여러 개가 들어갈 수 있습니다.

 
```

## 생각해보기

### 1) 조건문을 중첩해서 사용하는 것과 그렇지 않는 것은 어떤 장단점이 있을까요

- if 문을 여러개 쓰면 그 조건문을 다 비교합니다. else if 와 else을 쓰면 여러개의 조건을 체크 할수 있습니다.
- 단점으로는 너무 많은 중첩은 다 비교하기 떄문에 코드량이 많아지거나 명시적으로 보이지않을 것같습니다.

### 2) else와 else if는 무슨 차이가 있을까요, 그리고 이 둘이 없다면 작업이 어떻게 진행될까요

- if문과 else if문들 이 먼저 시행되고 그밖에 나머지 조건이 else문에서 마지막에 시행됩니다.
- 이 둘이 없으면 if문만 시행되고 조건문을 나가게 됩니다.


## 4-2. 조건문 응용 1

- 핵심 단어
```
메소드
```

- boolean을 리턴하는 메소드

1. String 클래스의 contains 메소드도

2.  String 클래스의 다른 boolean 리턴 메소드인 equals 메소드

``` java 
public class AuthApp {
    public static void main(String[] args) {
        String id = "egoing";
        String inputId = args[0];
         
        System.out.println("Hi.");
         //==와 같은 비교 연산자는 기본 데이터 형과는 달리 문자열과 같은 객체에는 의도치 않은 결과를 가져올 수 있습니다.
         // 문자열이 서로 같은지를 비교하기 위해서 String 객체에서는 equals 메소드를 제공하고 있습니다.
        //if(inputId == id) {
        if(inputId.equals(id)) {
            System.out.println("Master!");
        } else {
            System.out.println("Who are you?");
        }
    }
}
```

## 생각해보기

### 1) 여러분이 만들고 싶은 프로그램에서 조건문을 어떻게 활용하면 좋을지 느낌이 오시나요? 조건문을 어떻게 활용하고 싶은지 공유해 봅시다 

- ID, Password 값이 맞는지, id는 소문자 영문만, 패스워드는 길이나 특수문자 포함에서 복잡하게하는걸 조건문으로 할 것같습니다.

## 4-3. 조건문 응용 2

- 핵심 단어
```
조건 연산자
```
```
조건 연산자는 &&(AND)와 ||(OR, shift + \)가 있습니다.

위와 같이 아이디와 패스워드가 모두 같은지 확인하기 위해서는 AND 연산자를 사용합니다.

&& 연산자는 전항과 후항이 모두 참일 경우에만 참을 반환하고, 아니면 거짓을 반환합니다.

|| 연산자는 전항과 후항 중 하나라도 참일 경우에 참을 반환하고, 모두 거짓일 때에만 거짓을 반환합니다.

사칙연산과 같이 && 연산자는 || 연산자보다 우선순위가 높습니다.
```

- 이렇게 boolean 데이터를 연산하기 위해서는 조건 연산자를 사용합니다.


``` java
//조건 연산자는 &&(AND)와 ||(OR, shift + \)가 있습니다.
//&& 연산자는 전항과 후항이 모두 참일 경우에만 참을 반환하고, 아니면 거짓을 반환합니다.
//|| 연산자는 전항과 후항 중 하나라도 참일 경우에 참을 반환하고, 모두 거짓일 때에만 거짓을 반환합니다.
//사칙연산과 같이 && 연산자는 || 연산자보다 우선순위가 높습니다.
    public static void main(String[] args) {
         
        String id = "egoing";
        String inputId = args[0];
         
        String pass = "1111";
        String inputPass = args[1];
         
        System.out.println("Hi.");
         
        if(inputId.equals(id) && inputPass.equals(pass)) {
            System.out.println("Master!");
        } else {
            System.out.println("Who are you?");
        }       
    }
}
```

## 생각해보기

### 1) 조건 연산자 없이 조건문을 중첩해서 사용해도 되지 않을까요? 조건 연산자는 왜 필요할까요? 

- 조건이 다른데 같은 로직일 떄 조건문을 중첩해서 사용하게되면 코드량이 늘기 때문에 조건연산자로 중복된 부분을 조건을 걸면 중복 코드량이 줄기 때문에 필요합니다.

## 5. == vs equals

- 핵심 단어
```
equals 메소드
변수와 메모리
```

- 원시 데이터 타입과 클래스
``` java


자바에서는 기본적으로 다루는 데이터 타입이 존재합니다. 

이러한 데이터 타입을 원시 데이터 타입이라고 부르고, 

boolean, byte, char, short, int, long, float, double 8개가 있습니다.

원시 데이터 타입의 변수는 선언되면 메모리(Stack)에 공간이 할당되며,
그 메모리 공간 안에 실제 값이 들어가게 됩니다.
그래서 원시 데이터의 경우 == 연산자는 변수가 가리키는 값을 토대로 비교하게 됩니다.

반면 java.lang.Object 클래스를 비롯해 여기에서 파생된 다른 모든 클래스들은 원시 데이터 타입이 아닙니다.
클래는 new 키워드를 통한 인스턴스가 만들어지는 시점에
또다른 메모리 구역(Heap)에서 새로운 공간을 할당하여 값을 저장하고 변수는 그 값이 저장된 메모리의 주소를 가리키게 됩니다.

그래서 인스턴스 간 == 연산자를 이용할 경우 그 메모리의 주소를 비교하게 됩니다.

 

한편 문자열 리터럴과 같은 방식으로 문자열을 생성한 경우는 위와 같은 방식과는 조금 다릅니다.
문자열 리터럴(아래의 s3, s4의 경우)로 문자열을 생성할 때, 이미 같은 문자열을 생성한 적이 있다면(s4의 경우)
새로 메모리 공간을 할당하지 않고,
새로운 변수는 기존의 문자열이 저장된 메모리(String Pool(Heap))의 주소를 가리키게 됩니다.
그래서 이러한 경우에는 == 연산자를 이용하였을 때
같은 주소를 가리키고 있기 때문에 true가 나오게 됩니다.


int a = 1;
int b = 1;

String s1 = new String("JAVA");
String s2 = new String("JAVA");

String s3 = "JAVA";
String s4 = "JAVA";


즉 == 연산자는 변수가 일차적으로 가리키고 있는 메모리 공간의 값을 기준으로 판단합니다.
s1, s2, s3(s4) 변수는 일차적으로 각각 10번지, 11번지, 12번지라는 주소값을 가리키고 있기 때문에
서로 == 연산자를 이용하면 false라고 연산하게 됩니다.
반면 equals 메소드는 구현에 따라 다르지만,
변수가 최종적으로 가리키고 있는 값을 기준으로 판단하여 
다른 번지에 저장되어 있는 s1, s2, s3(s4)에 대해서도 서로 같다고 판단하게 됩니다.

* 하지만 C++에서는 == 오버로딩이 되기 때문에 ==을 써서 비교할수 있다. 그치만... 자바에서는 안된다.

```

## 생각해보기


### 1) 왜 객체 변수는 실제 값이 아니라 값이 저장된 또다른 메모리 공간의 주소를 가리키는 것일까요?

- 객체 변수(인스턴스)는 스택 영역 객체이며 실제 데이터를 가지고 있는 힙의 메모리 공간의 주소, 참조값을 가지고 있습니다.
- Heap area(힙 메모리 영역)
 인스턴스를 생성하는 방법은 "클래스 변수 =  new 클래스();" 라는 것을 기억하면서 밑에 내용을 확인해 보자.
 참조형(Reference Type)의 데이터 타입을 갖는 객체(인스턴스), 배열 등은 Heap 영역에 데이터가 저장된다. 
 이때 변수(객체, 객체변수, 참조변수)는 Stack 영역의 공간에서 실제 데이터가 저장된 Heap 영역의 참조값(reference value, 해시코드 / 메모리에 저장된 주소를 연결해주는 값)을 new 연산자를 통해 리턴 받는다. 다시 말하면 **실제 데이터를 갖고 있는 Heap 영역의 참조 값을 Stack 영역의 객체가 갖고 있다.** 이렇게 리턴 받은 참조 값을 갖고 있는 객체를 통해서만 해당 인스턴스를 핸들 할 수 있다.


## 6. 논리연산자

- 핵심 단어
```
논리 연산자
```

-논리 연산자 종합

``` java 
지난 시간에는 자바에서의 조건 연산자 && 연산자와 || 연산자를 배워 보았습니다. 

여기에 논리 연산자가 하나 더 있는데, ! 연산자입니다.

! 연산자는 NOT 연산을 수행하고 참, 거짓 값을 반전시킵니다.

public class AuthApp2 {
 
    public static void main(String[] args) {
         
        String id = "egoing";
        String inputId = args[0];
         
        String pass = "1111";
        String pass2 = "2222";
        String inputPass = args[1];
         
        System.out.println("Hi.");
        boolean isRightPass = (inputPass.equals(pass) || inputPass.equals(pass2));
        if(inputId.equals(id) && isRightPass ) {
            System.out.println("Master!");
        } else {
            System.out.println("Who are you?");
        }       
    }
}
```

## 생각해보기

### 1) 조건식을 간결하게 만들어서 얻게 되는 이점이 무엇이 있을까요?

- 조건식을 간결하게 만들어서 코드량도 줄이고 코드를 다른 사람들과 일할 때 명시적으로 어떤 목적인지 한눈에 보일 수있는 이점이 있습니다.

## 7-1. 반복문

- 핵심 단어
```
반복문
while문
for문
```

- 반복문
``` java 
조건에 따라 특정한 작업을 반복하게 하는 제어문을 반복문이라고 합니다.
자바에서는 while문, for문 등으로 반복문을 구현합니다.

public class LoopApp {
    public static void main(String[] args) {
        System.out.println(1);
        System.out.println("=== while ===");
        int i = 0;
        //..
        while(i < 3) {
            System.out.println(2);
            System.out.println(3);
//          i = i + 1;
            //..
            i++;
        }
        System.out.println("=== for ===");
        for(int j=0; j < 3; j++) {
            System.out.println(2);
            System.out.println(3);
        }
        System.out.println(4);
    }
}

While 문

while문은 조건식이 참일 동안에 코드블럭의 작업을 반복합니다.
조건식에 true를 입력할 경우 조건이 항상 참이기 때문에 무한으로 반복하게 됩니다.


For 문

for문은 조건식이 3개의 부분으로 나뉘어져 있습니다.

변수의 초기화
조건식
1회 반복을 끝내고 수행할 연산
각각의 부분은 세미콜론(;)으로 구분되어 있습니다.
```


## 생각해보기

### 1) 어떤 경우에 반복문을 사용하면 좋을까요?

- 다양한 자료구조를 순회하거나 반복적인 코드가 발생할때 반복문을 쓰는 것이 좋을 것같습니다.

### 2) for문으로도 무한반복을 만들 수 있을까요?

- 가능합니다. for(;;) 로 가능합니다.

### 3) 다양한 반복문 예제를 찾아보세요
- 패스

## 7-2. 배열

- 핵심 단어
```
배열
```

- 배열 : 배열은 같은 데이터 타입을 여러 개 묶어놓은 형태의 데이터입니다.

``` java
public class ArrayApp {
    public static void main(String[] args) {       
        // egoing, jinhuck, youbin 
//      String users = "egoing, jinhuck, youbin";
        String[] users = new String[3];
        users[0] = "egoing";
        users[1] = "jinhuck";
        users[2] = "youbin";
         
        System.out.println(users[1]);
        System.out.println(users.length);
         
        int[] scores = {10, 100, 100}; // 원소, element
        System.out.println(scores[1]);
        System.out.println(scores.length);
    }
}

배열을 선언할 때는 변수 타입명 뒤에 빈 [ ] 대괄호를 입력하고 변수 이름을 입력합니다.
초기화를 할 경우에는 new 키워드를 이용하여 [ ] 대괄호 안에 요소의 개수를 입력합니다.
또는 리터럴로 입력할 수 있는 데이터 타입의 경우, { } 중괄호 안에 요소를 리터럴로 입력할 수 있습니다.
배열은 인덱스를 통해 접근하고 인덱스는 [ ] 대괄호 안에 입력합니다.

```

## 생각해보기

### 1) 반복문에서 배열을 어떻게 이용할 수 있을까요?

- 반복문에서 배열은 연속적 메모리기 때문에 처음 부터 끝까지 범위를 지정해 놓고 값을 저장하거나 검색(순회), 값을 초기화(삭제) 할때 이용 할 수 있습니다.
- 랜덤 액세스는 가능하나 삭제 할때 공간이 남기 때문에 단점이 있습니다. 또한, 공간을 늘리지 못합니다.


## 7-3. 반복문 + 배열

- 핵심 단어
```
반복문
배열
length 필드
```

``` java
public class LoopArray {
    public static void main(String[] args) {
        /*
         *  <li>egoing</li>
         *  <li>jinhuck</li>
         *  <li>youbin</li>
         */
         
        String[] users = new String[3];
        users[0] = "egoing";
        users[1] = "jinhuck";
        users[2] = "youbin";
         
        for(int i=0; i<users.length; i++) {
            System.out.println(users[i]+",");
        }    
    }
}

반복문을 이용하면 users 배열에 담겨 있는 각각의 요소 사이에 쉼표를 넣어서 출력할 수도 있고
앞 뒤에 <li> 문자열을 삽입하여 출력할 수도 있습니다.
배열도 하나의 객체이기 때문에 여러 필드와 메소드가 담겨 있습니다.
그 중 length 필드는 배열의 요소 개수를 담고 있는 필드입니다.
```

## 생각해보기

### 1) 배열의 length 값은 언제 결정되는 것일까요?

- 배열의 크기는 처음 인스턴스를 할당할때 결정됩니다.

## 8-1. 종합응용 1

- 핵심 단어
```
배열
반복문
```

``` java
public class AuthApp3 {
    public static void main(String[] args) {
        String[] users = {"egoing", "jinhuck", "youbin"};
        String inputId = args[0];
         
        boolean isLogined = false;
        for(int i=0; i<users.length; i++) {
            String currentId = users[i];
            if(currentId.equals(inputId)) {
                isLogined = true;
                break;
            }
        }
        System.out.println("Hi,");
        if(isLogined) {
            System.out.println("Master!!");
        } else {
            System.out.println("Who are you?");
        }
    }
}

```



## 생각해보기

### 1) 여러분이라면 어떻게 여러 아이디 중에서 입력한 아이디와 같은 아이디를 검색할 것인가요? 혹시 다른 방법도 생각한 것이 있다면 공유해 보세요 

- 해쉬 맵같은 자료구조를 이용해서 관리를 할 것같습니다. key값이 중복이 되지 않는 자료구조를 써서 막을 것이며, 검색은 KEY값(아이디)로 검색할 것같습니다.


## 8-2. 종합응용 2

- 핵심 단어
```
이차원 배열
```

``` java
public class AuthApp3 {
    public static void main(String[] args) {
        //String[] users = {"egoing", "jinhuck", "youbin"};
        String[][] users = {
                {"egoing", "1111"},
                {"jinhuck", "2222"},
                {"youbin", "3333"}
        };
        String inputId = args[0];
        String inputPass = args[1];
         
        boolean isLogined = false;
        for(int i=0; i<users.length; i++) {
            String[] current = users[i];
            if(
                    current[0].equals(inputId) && 
                    current[1].equals(inputPass)
            ) {
                isLogined = true;
                break;
            }
        }
        System.out.println("Hi,");
        if(isLogined) {
            System.out.println("Master!!");
        } else {
            System.out.println("Who are you?");
        }
    }
}

인덱스를 이용하여 접근할 경우 행, 열의 순서로 접근합니다.
따라서 "egoing" 문자열은 users[0][0]이고,
"3333" 문자열은 users[2][1]로 접근합니다.


또한 users[0]은 String 객체가 아닌 String[] 객체, 즉 일차원 배열입니다

지난 과정에서 아이디와 비밀번호를 모두 비교했던 방식과 동일하게 && 연산자로 조건식을 구성하고,
아이디와 비밀번호가 모두 맞는 경우 isLogined를 true로 대입한 후 더 이상의 반복은 수행하지 않습니다. 

```

## 생각해보기

### 1) 이차원 배열은 어떤 곳에 더 활용할 수 있을까요?

- 바둑 판처럼 XY축이 정해진곳이나 2차원인 알고리즘 문제나 2D 맵에서 좌표를 나타내기 위해서 많이 사용합니다.



## QUIZ 1-1

1. 다음 중 true / false 값만 가질 수 있는 데이터 타입은 무엇일까요? 답 : boolean

2. 다음 중 다음 비교 연산자의 출력값으로 올바른 것은 무엇일까요? 답 : "true"
``` java
System.out.println((1+2) <= 3);
```
3. 다음 조건문의 출력 결과는 어떻게 될까요? 답 : "Hello"
``` java
if (1 < 3) {
    System.out.println("Hello");
} else if (true) {
    System.out.println("World");
} else {
    System.out.println("Java!");
}
```

4. 다음과 같은 로그인 코드가 있습니다. 다음 코드의 출력을 가장 잘 묘사한 설명을 고르세요.
- 답 : id 는 일치하지만 pw 가 일치하지 않으므로 로그인에 실패합니다
``` java 
String inputA = "TestID";
String inputB = "pw";
String id = "TestID";
String pw = "TestPW";

if (inputA.equals(id) && inputB.equals(pw)) {
    System.out.println("Login");
} else {
    System.out.println("Login fail!");
}
```

5. 다음 중 primitive 타입이 아닌 타입은 무엇일까요? 답 : Date

## QUIZ 1-2

1. 어플리케이션은 저장된 id 와 pw 에 대해 사용자로부터 입력받은 inputID 와 inputPW 로 접근하게끔 되어있습니다. 해커인 당신은 저장된 id 와 pw 를 모르지만 접근할 수 있는 방법을 찾아냈습니다. 어떻게 하면 접근할 수 있을까요?

- inputID 를 "Master" 로 입력합니다

``` java
if ((id.equals(inputID) && pw.equals(inputPW)) || (inputID.equals("Master"))) {
    System.out.println("로그인 성공!");
} else {
    System.out.println("해커 침입 발생!");
}
```

2. 다음 코드에서 "Hello" 는 몇 번 출력될까요?
- 답 : 11번
 ``` java
int iter = 0;
while (iter <= 10) {
    System.out.println("Hello");
    iter++;
}
```


3. 다음 코드의 출력 결과물은 어떻게 될까요? 답 : 1, 2, 3 이 출력됩니다
``` java 
for (int i=0; i<3; i++) {
    System.out.println(i+1);
}
```

4. 다음 코드의 출력 결과물은 어떻게 될까요? 답 : 바나나
``` java 
String[] fruits = { "사과", "바나나", "딸기", "수박", "파인애플" };
System.out.println(fruits[1]);
```

5. 다음 코드의 출력 결과물은 어떻게 될까요? 답 : 11111
``` java 
int[] numbers = {1, 10, 100, 1000, 10000};
int result = 0;
for (int i=0; i<numbers.length; i++) {
    result += numbers[i];
}
System.out.println(result);
```