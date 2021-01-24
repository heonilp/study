
## - 3주차 (1월 25일 ~ 1월 31일): 나의 앱 만들기

- 3주차에서 나온 주요 키워드
1. 프로그램
2. 변수
3. 리팩토링
4. 아규먼트, 파라미터
5. 조건문
6. 배열
7. 반복문
8. 메소드, 필드, 지역변수, static
9. 클래스
10. 인스턴스

### 14-1. 나의 앱 만들기_오리엔테이션

- 이러한 문제를 JAVA 프로그래밍 해보자

```
우선 우리가 해야할 일은 현실을 분석하는 것입니다.
판매자인 우리는 소비자에게 물건을 공급할때 공급가(Value of supply)를 받습니다.
그리고 공급가의 10%만큼 소비자는 부가가치세(Value added tax)를 더 지불하고 판매자는 국세청에 부가가치세를 납부합니다.
이 때 물건을 판매하기까지는 30%의 비용이 들고 나머지 70%가 이익이라고 할 때,
이익은 투자한 동업자들에게 5:3:2의 비율로 배당합니다.
```

### 14-2. 나의 앱 만들기_기본 기능 구현

- 핵심 단어
```
프로그램
```
``` java
- 14-1에서 강의 한것을 JAVA 프로그램으로 나타내었습니다.
AccountingApp.java

public class AccountingApp {
	public static void main(String[] args) {
		
		System.out.println("Value of supply : " + 10000.0);
        System.out.println("VAT : " + (10000.0 * 0.1));
        System.out.println("Total : " + (10000.0 + (10000.0 * 0.1)));
        System.out.println("Expense : " + (10000.0 * 0.3));
        System.out.println("Income : " + (10000.0 - (10000.0 * 0.3)));
        System.out.println("Dividend 1 : " + (10000.0 - (10000.0 * 0.3)) * 0.5);
        System.out.println("Dividend 2 : " + (10000.0 - (10000.0 * 0.3)) * 0.3);
        System.out.println("Dividend 3 : " + (10000.0 - (10000.0 * 0.3)) * 0.2);
	}
}
```

### 14-3. 나의 앱 만들기_변수도입

- 핵심 단어
```
변수(Variable)
리팩토링(Refactoring)
```
``` java 
public class AccountingApp {
    public static void main(String[] args) {
        double valueOfSupply = 10000.0;
        double vatRate = 0.1;
        double expenseRate = 0.3;
        double vat = valueOfSupply * vatRate;
        double total = valueOfSupply + vat;
        double expense = valueOfSupply * expenseRate;
        double income = valueOfSupply - expense;
        double dividend1 = income * 0.5;
        double dividend2 = income * 0.3;
        double dividend3 = income * 0.2;
 
        System.out.println("Value of supply : " + valueOfSupply);
        System.out.println("VAT : " + vat);
        System.out.println("Total : " + total);
        System.out.println("Expense : " + expense);
        System.out.println("Income : " + income);
        System.out.println("Dividend 1 : " + dividend1);
        System.out.println("Dividend 2 : " + dividend2);
        System.out.println("Dividend 3 : " + dividend3);
    }
}
```

## 생각해보기 
### 1) 이렇게 프로그램의 기능은 바꾸지 않으면서 이해하기 쉽게 바꾸는 과정을 리팩토링이라고 합니다. 리팩토링에 대해 더 알아보세요.

- 리팩토링이란 무엇인가? [참고](https://nesoy.github.io/articles/2018-05/Refactoring)
```
외부 동작을 바꾸지 않으면서 내부 구조를 개선하는 방법입니다.
코드가 작성된 후에 디자인을 개선하는 작업입니다.
모든 것을 미리 생각하기보다는 개발을 하면서 지속적으로 좋은 디자인을 찾는다.
메소드 내의 지역변수와 parameter를 주의 깊게 볼 필요가 있다.
값이 수정되지 않는 변수는 파라미터로 넘길 수 있다.
값이 수정되는 변수는 주의가 필요하다. 변화되는 부분을 함수로 추출하여 리턴 값으로 돌려줄 수 있다.
```

- 목적
```
리팩토링의 목적은 소프트웨어를 보다 이해하기 쉽고, 수정하기 쉽도록 만드는 것이다.
리팩토링은 겉으로 보이는 소프트웨어의 기능을 변경하지 않는다는 것이다.
```
### 14-4. 나의 앱 만들기_입력값 도입

- 핵심 단어
```
아규먼트(Argument)
파라미터(Parameter)
```

``` java 
- 실행 : java AccountingApp 33333.0

public class AccountingApp {
    public static void main(String[] args) {
        double valueOfSupply = Double.parseDouble(args[0]); //입력 값

        double vatRate = 0.1;
        double expenseRate = 0.3;
        double vat = valueOfSupply * vatRate;
        double total = valueOfSupply + vat;
        double expense = valueOfSupply * expenseRate;
        double income = valueOfSupply - expense;
        double dividend1 = income * 0.5;
        double dividend2 = income * 0.3;
        double dividend3 = income * 0.2;
 
        System.out.println("Value of supply : " + valueOfSupply);
        System.out.println("VAT : " + vat);
        System.out.println("Total : " + total);
        System.out.println("Expense : " + expense);
        System.out.println("Income : " + income);
        System.out.println("Dividend 1 : " + dividend1);
        System.out.println("Dividend 2 : " + dividend2);
        System.out.println("Dividend 3 : " + dividend3);
    }
}
```

### 14-5. 나의 앱 만들기_오리엔테이션2
이번 강의 이후부터는 여러분이 문제를 해결하면서 해결하지 못할 불편함을 예견하고 
불편함을 해소할 수 있을 만한 도구들을 소개하게 될 것입니다.

### 14-6. 나의 앱 만들기_조건문

- 핵심 단어
```
조건문
```
- 조건문
제어문은 프로그램의 실행 과정을 조건에 따라 바꾸는 것입니다.
```
EX: 서울 지하철을 예로 들어 보면 같은 길로 가던 1호선 열차도 방향에 따라 구로역에서 인천 방향과 천안 방향 노선이 분기하고
2호선처럼 성수역이 나올 때까지 빙글빙글 돌기도 합니다.
```

``` java
public class AccountingIFApp {
    public static void main(String[] args) {
        double valueOfSupply = Double.parseDouble(args[0]);
        double vatRate = 0.1;
        double expenseRate = 0.3;
        double vat = valueOfSupply * vatRate;
        double total = valueOfSupply + vat;
        double expense = valueOfSupply * expenseRate;
        double income = valueOfSupply - expense;
         
        double dividend1;
        double dividend2;
        double dividend3;
         
        if(income > 10000.0) {
            dividend1 = income * 0.5;
            dividend2 = income * 0.3;
            dividend3 = income * 0.2;
        } else {
            dividend1 = income * 1.0;
            dividend2 = income * 0;
            dividend3 = income * 0;
        }
//우리의 문제상황에 새로운 조건이 하나 생기게 되었다고 해 봅시다.
//수익(income)이 1만원이 넘을 경우에만 동업자들에게 기존의 배당률대로 수익을 배당하고,
//수익이 1만원 이하일 경우에는 1번 동업자에게만 모든 수익을 배당하게 되었습니다.

        System.out.println("Value of supply : " + valueOfSupply);
        System.out.println("VAT : " + vat);
        System.out.println("Total : " + total);
        System.out.println("Expense : " + expense);
        System.out.println("Income : " + income);
        System.out.println("Dividend 1 : " + dividend1);
        System.out.println("Dividend 2 : " + dividend2);
        System.out.println("Dividend 3 : " + dividend3);
    }
}

```
## 생각해보기 
 
### 1) 조건문은 어떤 경우에 필요할 것 같은지 댓글로 토론해 보세요

- 변수 값이나 상수 값, 범위 값 등을 if문(else if, else ...)으로 판단할 수있습니다.
``` java
1. and(&&), or(||), not(!)


2. 비교연산자 설명
x < y	x가 y보다 작다
x > y	x가 y보다 크다
x == y	x와 y가 같다
x != y	x와 y가 같지 않다
x >= y	x가 y보다 크거나 같다
x <= y	x가 y보다 작거나 같다
```

3. contains : List 자료형에는 해당아이템이 있는지 조사하는 contains라는 메소드가 있다


- 추가적으로 switch으로 변수값이 들어가면 해당 케이스로 스위칭 되어 로직이 들어갑니다.
``` java 
//다음은 등수에 대한 메달 switch java 문법이다.
        int rank = scanner.nextInt();
		char medalColor; 
				
		switch(rank) {
			case 1: medalColor = '금';// char은 '' String은 ""
				System.out.println("금메달");
				break; // 중괄호를 빠져나가라. 안쓰면 금은동메달 다나오고 마지막에 A라고나옴..
			case 2: medalColor = '은';
				System.out.println("금메달");
				break;
			case 3: medalColor = '동';
				System.out.println("금메달");
				break;
			default : medalColor = 'A';  //default 값을 안넣어도 되는데 안낳을거면 초기값을 줘야함- medalcolor : 'A'
		}
		
```
### 14-7. 나의 앱 만들기_배열
- 핵심 단어
```
배열(Array)
동일한 자료형(Data Type)의 데이터를 연속된 공간에 저장하기 위한 자료구조이다. 인덱스는 0부터 시작합니다.
```

``` java
        ...

        double[] dividendRates = new double[3];
        dividendRates[0] = 0.5;
        dividendRates[1] = 0.3;
        dividendRates[2] = 0.2;
        
//배열은 데이터 타입 옆에 대괄호([])를 붙여서 표현하고, 인스턴스를 만들 때는 배열의 길이를 지정하여 생성합니다.
//배열 내의 데이터는 인덱스를 이용하여 접근할 수 있습니다.
//인덱스는 0부터 시작합니다.
//프로그램의 기능은 변하지 않았지만, 배열로 묶어서 표현함으로써 각각의 배당률이 서로 연관된 정보라는 것을 분명히 할 수 있게 되었고, 변수의 개수도 줄어들게 되었습니다.

		double dividend1 = income * dividendRates[0];
        double dividend2 = income * dividendRates[1];
		double dividend3 = income * dividendRates[2];
 
        ...

```
## 생각해보기 

### 1) 배열은 무엇인지, 왜 사용하는지 댓글로 토론해 보세요
- [JAVA 배열 참고](https://wikidocs.net/206)

- 동일한 자료형(Data Type)의 데이터를 연속된 공간에 저장하기 위한 자료구조이다. 즉, 연관된 데이터를 그룹화하여 묶어준다고 생각하면 된다.

- 배열의 장점

연관된 데이터를 저장하기 위한 변수의 선언을 줄여주며, 반복문 등을 이용하여 계산과 같은 과정을 쉽게 처리할 수 있다.
``` java 
선언

int[] i= new int[8]; //초기값 0
String[] s = new String[8]; //초기값 ""
배열의 초기화
//배열에 특정값 대입하며 선언
int[] i = {1,2,3,4,5};
String[] s = {"a","b","c","d"};
		
//배열의 주소를 모두 같은값으로 초기화
Arrays.fill(i,1);//i의 모든 index값을 1로 초기화
	
//for문을 통해 값을 대입
for(int m=0;i<i.length;m++) {
    i[m]=m;
}

//foreach문을 통한 배열출력
for(int m:i) {
    System.out.print(m);
}	
```

### 14-8. 나의 앱 만들기_반복문

- 핵심 단어
```
반복문 for문
while 문
```
- for, while 반복문을 이용하여 반복적으로 동작하던 작업을 간결하게 바꿀 수 있게 되었습니다.


``` java
        //변경 전
        System.out.println("Dividend 1 : " + dividend1);
        System.out.println("Dividend 2 : " + dividend2);
        System.out.println("Dividend 3 : " + dividend3);

        //변경 후
        int i = 0;
        while (i < dividendRates.length) {
            System.out.println("Dividend : " + income * dividendRates[i]);
            i = i + 1;
        }


```

## 생각해보기 


### 1) while 문 외에 다른 반복문이 또 있을까요?

- for문과 for each 문이 있습니다.

- 예제
``` java
String[] numbers = {"one", "two", "three"};
for(int i=0; i<numbers.length; i++) {
    System.out.println(numbers[i]);
}

String[] numbers = {"one", "two", "three"};
for(String number: numbers) {
    System.out.println(number);
}

```

### 2) 반복문은 무엇인지 왜 사용하는지 댓글로 토론해 보세요

- for, while 등 반복문을 이용하여 반복적으로 동작하던 작업을 간결하게 바꿀 수 있습니다.

### 14-9. 나의 앱 만들기_메소드

- 핵심 단어
```
메소드(method)
필드(Field)
지역 변수(Local Variable)
```

- main 메소드 안의 동작들은 단순해졌고, 세부적인 동작들은 다른 메소드 안에서 정의되어
프로그램을 사용하는 입장에서 보기 단정한 코드로 바뀌었습니다.

``` java 
public class AccountingMethodApp {
 
    public static void main(String[] args) {
 
        ...
        double vat = getVAT(valueOfSupply, vatRate);
        ...

        ...
        print(); //출력하는 부분들도 메소드로 정리합니다.
        ...
    }
    //메소드로 변경해서 깔끔하게 짤 수 있다.
	public static double getVAT(double valueOfSupply, double vatRate) {
		return valueOfSupply * vatRate;
	}


    public static void print() {
		System.out.println("Value of supply : " + valueOfSupply);
        System.out.println("VAT : " + getVAT());
        System.out.println("Total : " + getTotal());
        System.out.println("Expense : " + getExpense());
        System.out.println("Income : " + getIncome());
        System.out.println("Dividend 1 : " + getDividend1());
        System.out.println("Dividend 2 : " + getDividend2());
        System.out.println("Dividend 3 : " + getDividend3());
    }
 
}
```

## 생각해보기 

### 1) 메소드는 무엇인지 왜 사용하는지 댓글로 토론해 보세요

- 메소드
```
보통 다른언어에는 함수라는 것이 별도로 존재한다. 하지만 자바는 클래스를 떠나 존재하는 것은 있을 수 없기 
때문에 자바의 함수는 따로 존재하지 않고 클래스 내에 존재한다. 자바는 이 클래스 내의 함수를 메소드라고 부른다.

※ 보통 함수와 메소드가 공존하는 언어(예:파이썬)에서는 두 개를 구분하여 말하기도 하지만 
자바는 보통 메소드와 함수를 구분하여 말하지 않는다. 다만 자바에서 사용되는 함수의 정확한 명칭은 메소드이다.
```

- 사용하는 이유?
``` java
가끔 프로그래밍을 하다 보면 똑같은 내용을 자신이 반복해서 적고 있는 것을 발견할 때가 있다.
이 때가 바로 메소드가 필요한 때이다. 여러 번 반복해서 사용된다는 것은 언제고 또다시 사용할 만한 가치가 있는 부분이라는 뜻이다.
즉, 이러한 경우 이것을 한 뭉치로 묶어서 “어떤 입력값을 주었을 때 어떤 리턴값을 돌려준다”라는 식의 메소드를 작성하는 것이 현명한 일일 것이다.

// 예제
public int sum(int a, int b) {
    return a+b;
}

```

### 14-10. 나의 앱 만들기_클래스

- 핵심 단어
```
클래스
``` 
- 클래스
```
클래스는 서로 연관된 변수와 메소드를 묶어 놓은 것이라는 것
```

``` java
// 이전에 main 클래스 쪽에 있던 것을 Accounting 클래스로 묶음
class Accounting {
	
	public static double valueOfSupply;
	public static double vatRate;
	public static double expenseRate;
	
	public static void print() {
		System.out.println("Value of supply : " + valueOfSupply);
        System.out.println("VAT : " + getVAT());
        System.out.println("Total : " + getTotal());
        System.out.println("Expense : " + getExpense());
        System.out.println("Income : " + getIncome());
        System.out.println("Dividend 1 : " + getDividend1());
        System.out.println("Dividend 2 : " + getDividend2());
        System.out.println("Dividend 3 : " + getDividend3());
	}

	public static double getDividend3() {
		return getIncome() * 0.2;
	}

	public static double getDividend2() {
		return getIncome() * 0.3;
	}

	public static double getDividend1() {
		return getIncome() * 0.5;
	}

	public static double getIncome() {
		return valueOfSupply - getExpense();
	}

	public static double getExpense() {
		return valueOfSupply * expenseRate;
	}

	public static double getTotal() {
		return valueOfSupply + getVAT();
	}

	public static double getVAT() {
		return valueOfSupply * vatRate;
	}
	
}



public class AccountingClassApp {

	public static void main(String[] args) {
        //클래스 
		Accounting.valueOfSupply = 10000.0;
		Accounting.vatRate = 0.1;
		Accounting.expenseRate = 0.3;
		Accounting.print();
    }
}


```

## 생각해보기 

### 1) 클래스는 무엇인지 왜 사용하는지 댓글로 토론해 보세요

- 클래스는 서로 연관된 변수와 메소드를 묶어 놓은 것이라는 것, 행동을 하는 객체를 만드는 것 **클래스**

``` java 
public class Animal {

}
```

위 Animal 클래스는 가장 간단한 형태의 클래스이다. 클래스의 선언만 있고 내용이 없는 껍데기뿐인 클래스이다.
하지만 이 껍데기뿐인 클래스도 아주 중요한 기능을 가지고 있다. 그 기능은 바로 객체(object)를 만드는 기능이다.


### 14-11. 나의 앱 만들기_인스턴스

- 핵심 단어
```
인스턴스(Instance)
```
```
인스턴스는 클래스를 실제로 실행시킨 실체화된 클래스라고 할 수 있습니다.
이를 통해 다양한 상태에 있는 여러 개의 클래스를 돌릴 수 있습니다.
```

```
1. OO 상품

공급가 : 10000
부가가치세율 10%
공급가 대비 비용률 : 30%
2. XX 상품

공급가 : 20000
부가가치세율 5%
공급가 대비 비용률 : 20%
```

1. 우선 Accounting 클래스의 static 키워드를 모두 제거합니다.

``` java
class Accounting {
	public double valueOfSupply;
	public double vatRate;
	public double expenseRate;
	
	public void print() {
		System.out.println("Value of supply : " + valueOfSupply);
        System.out.println("VAT : " + getVAT());
        System.out.println("Total : " + getTotal());
        System.out.println("Expense : " + getExpense());
        System.out.println("Income : " + getIncome());
        System.out.println("Dividend 1 : " + getDividend1());
        System.out.println("Dividend 2 : " + getDividend2());
        System.out.println("Dividend 3 : " + getDividend3());
	}

	public double getDividend3() {
		return getIncome() * 0.2;
	}

	public double getDividend2() {
		return getIncome() * 0.3;
	}

	public double getDividend1() {
		return getIncome() * 0.5;
	}

	public double getIncome() {
		return valueOfSupply - getExpense();
	}

	public double getExpense() {
		return valueOfSupply * expenseRate;
	}

	public double getTotal() {
		return valueOfSupply + getVAT();
	}

	public double getVAT() {
		return valueOfSupply * vatRate;
	}
}
```
2. 두 개의 인스턴스를 생성합니다.
``` java

public class AccountingClassApp {
	public static void main(String[] args) {
	    Accounting a1 = new Accounting();
        a1.valueOfSupply = 10000.0;
        a1.vatRate = 0.1;
        a1.expenseRate = 0.3;
        a1.print();

        Accounting a2 = new Accounting();
        a2.valueOfSupply = 20000.0;
        a2.vatRate = 0.05;
        a2.expenseRate = 0.2;
        a2.print();
```


## 생각해보기 

### 1) 인스턴스는 무엇인지, 왜 사용하는지, 클래스와는 어떻게 다른지 댓글로 토론해 보세요

- ※ 객체와 인스턴스

클래스에 의해서 만들어진 객체를 인스턴스라고도 한다. 그렇다면 객체와 인스턴스의 차이는 무엇일까?
이렇게 생각 해 보자. Animal cat = new Animal() 이렇게 만들어진 cat은 객체이다. 
그리고 cat이라는 객체는 Animal의 인스턴스(instance)이다. 
즉 인스턴스라는 말은 특정 객체(cat)가 어떤 클래스(Animal)의 객체인지를 관계위주로 설명할 때 사용된다. 
즉, "cat은 인스턴스" 보다는 "cat은 객체"라는 표현이 "cat은 Animal의 객체" 보다는 "cat은 Animal의 인스턴스" 라는 표현이 훨씬 잘 어울린다.

### Quiz 4

- 결과 : 90점
- 다시 정리해서 올립니다. 3번을 틀렸다... 정수 말고 실수형인 doblue형을 골랐어야했다. 

1. 여러분이 적금한 돈 10000 원에 대해 10% 만큼 이자가 들어왔습니다. 이를 Java 화면에서 어떻게 출력할 수 있을까요?
``` java
답 : System.out.println(10000 + 10000.0 * 0.1);
```
2. 여러분이 적금한 돈이 money 만큼 있고, income 만큼 추가로 돈이 들어왔습니다. 수입을 변수 total 을 통해 관리하는 방안은 무엇일까요?
``` java
답 : int total = money + income;
```

3. 여러분의 프로그램 AccountingApp 에 Argument 로 실수 money 와 income 이 다음과 같이 전달됩니다. 총 수입을 출력하는 방안은 무엇일까요?
- (ex) java AccountingApp 1000.0 15.0
``` java 
답 : System.out.println(Double.parseDouble(args[0]) + Double.parseDouble(args[1]));
```
4. 특정 상황에 따라 프로그램의 흐름을 바꿔줄 수 있는 조건을 지정하는 구문을 뭐라고 할까요? 답 : 조건문

5. 다음 중 배열을 나타내는 올바른 방식은 무엇일까요?
``` java
double[] rates = new double[3];
```
6. 연속적인 동작을 반복적으로 수행할 수 있게 해주는 구문을 뭐라고 할까요? 답 : 반복문

7. 다음 중 서로 연관된 코드를 그루핑해서 별도 기능의 코드 상자를 만든 것을 뭐라고 할까요? 답: 메서드

8. 다음 중 서로 연관된 변수와 메서드를 그루핑한 개념을 뭐라고 말할 수 있을까요? 답: 클래스

9. 다음 중 하나의 클래스를 이용해서 독립된 값과 메서드를 가진 개체를 뭐라고 할까요? 답: 인스턴스

10. 프로그래밍이란 무엇일까요? 답 : 논리적으로 뭐든 할 수 있는 것


### Quiz 5 (복습)

- 결과 : 100점
1. 다음 중 최고의 프로그래밍 언어는 무엇일까요? 답 : Anything

2. 다음 Java 프로그램을 시작시키려 헀지만, 실행되지 않았습니다. 어떤 문제일까요? 답 : 클래스 이름이 파일 이름과 다릅니다
``` java
파일 이름 : HelloWorld.java
파일 내용 :
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello");
    }
}
```

3. 다음 Java 사칙연산의 결과로 어떤 값이 출력될까요? 답 : 2
``` java
System.out.println((10+2*5)/10);
```

4. Java 로 안드로이드용 모바일 셀카 어플리케이션을 개발하고자합니다. 다음 중 가장 적합한 편집용 도구는 무엇일까요? 답 : Android Studio

5. 여러분은 프로그램을 열심히 개발하고 있습니다. 그리고 어디선가 프로그램이 문제가 생긴 걸 알아챘습니다. 문제점을 파악하기 위해 시도해볼 수 있는 방안에 무엇이 있을까요? 답 : 디버깅

6. 10000 번의 동일한 작업을 수행해야 합니다. 다음 중 어떤 구문을 고려해볼 수 있을까요? 답: 반복문

7. 책의 각 문장을 읽는 프로그램이 있습니다. 각 문장은 다음 중 어떤 타입에 저장되면 좋을까요? 답 : String

8. 여러분은 부루마블 게임을 만드는데 주사위 관련 개발을 담당하게 되었습니다. 그리고 주사위 나온 숫자를 구분하여 말을 이동시켜야한다는걸 알았습니다. 어떤 구문을 고려해봐야할까요? 답 : 조건문

9. 여러분은 팀프로젝트를 하고 있고, 어떤 복잡한 기능 구현이 필요한 상황입니다. 그리고 누군가가 이 기능을 만들어 놓았으면 좋겠다는 생각을 하게됩니다. 다음 중 어떤 접근을 하면 좋을까요? 답 : 기능이 구현된 라이브러리를 찾아봅니다.

10. 여러분은 어떤 외부 라이브러리를 발견했고, 그 안에서 다음과 같은 클래스를 찾게 됩니다. 이 클래스가 하는 역할은 무엇일까요? 
- 답 : 덧셈을 제공해주는 메서드를 제공합니다.
``` java
public static class Calc {
    public static int add(int a, int b) {
        return a + b;
    }
}
```