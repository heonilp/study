
## - 3주차 (1월 25일 ~ 1월 31일): 나의 앱 만들기

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


### 14-6. 나의 앱 만들기_조건문

## 생각해보기 
 
### 1) 조건문은 어떤 경우에 필요할 것 같은지 댓글로 토론해 보세요

### 14-7. 나의 앱 만들기_배열

## 생각해보기 

### 1) 배열은 무엇인지, 왜 사용하는지 댓글로 토론해 보세요



### 14-9. 나의 앱 만들기_메소드

## 생각해보기 

### 1) 메소드는 무엇인지 왜 사용하는지 댓글로 토론해 보세요


### 14-10. 나의 앱 만들기_클래스


## 생각해보기 

### 1) 클래스는 무엇인지 왜 사용하는지 댓글로 토론해 보세요


### 14-11. 나의 앱 만들기_인스턴스

## 생각해보기 

### 1) 인스턴스는 무엇인지, 왜 사용하는지, 클래스와는 어떻게 다른지 댓글로 토론해 보세요


### Quiz 4



### Quiz 5

