# 상속

## 1. 수업소개

- 핵심 단어
```
상속
```

- 상속

우리는 만들어진 클래스, 혹은 인스턴스를 통해서 프로그램을 구성하는 방식에 대해서 알아보았습니다.
그런데, 두 개의 클래스를 만들어야 할 일이 있는데 한 클래스가 다른 클래스의 기능들을 모두 포함하는
형태라면 어떻게 해야 할까요? 모두 복사해서 일일이 넣어 주어야 할까요? 
이럴 경우 이용하면 좋은 기능이 상속입니다.



Cal3 클래스를 생성할 때 **extends** 키워드를 이용해서 Cal로부터 상속을 받을 수 있습니다.
Cal3라는 Cal로부터 상속받은 클래스에 아무것도 넣지 않아도,
Cal에 있는 메소드인 sum을 사용할 수 있습니다.

``` java

class Cal {
	public int sum(int v1, int v2) {
		return v1 + v2;
	}
}
class Cal3 extends Cal{
	
}
...
public class InheritanceApp {

	public static void main(String[] args) {
		Cal c = new Cal();
		System.out.println(c.sum(2, 1));
		Cal3 c3 = new Cal3();
		System.out.println(c3.sum(2, 1));
	}

}
```

### 생각해보기

#### 1) 상속을 이용하면 어떤 문제점을 해결할 수 있을 것 같나요?

- 여러개 클래스에 중복된 내용이나 같은 기능을 할때 상속을 받아서 해결할 수 있습니다.


## 2. 기능의 개선과 발전

- 핵심 단어
```
부모 클래스(superclass)
자식 클래스(subclass)
재정의(override)
```

- 만약 부모 클래스가 가진 기능이지만 더 보태서 멋지게 만들려고 하려면 어떻게 해야 할까요?
: 같은 이름으로 다시 재정의(override)하여 만들 수 있습니다.
``` java
class Cal3 extends Cal{
	
	public int sum(int v1, int v2) { //재정의 오버라이딩
		System.out.println("Cal3!!!");
		return v1 + v2;
	}

	public int minus(int v1, int v2) {
		return v1 - v2;
	}
}
```

### 생각해보기

#### 1) 어떤 경우에 부모 클래스의 메소드를 재정의해야 할까요? 구체적인 상황을 생각해 봅시다.

- 같은 이름인데 부모 클래스의 메소드를 재정의해서 다시 기능이나 해당 값을 다를경우 재정의 할 때 쓰인다.


## 3. Overriding, Overloading

- 핵심 단어
```
override : 상속관계에서 부모의 메소드를 자식이 재정의해서 쓰는 경우
overload : 메소드의 이름은 같으나 매겨변수나 타입, 리턴값은 다른 경우
```

- Overloading

오버로딩은 상속과는 직접적인 관련이 없습니다.
특정 이름을 지닌 메소드가 있다고 할지라도 우리는 같은 이름을 가진 메소드를 또 만들 수 있습니다.
다만 파라미터의 형식이 달라야 합니다.

- overriding

같은 클래스 안에서는 이뤄질 수 없고, 상속 관계를 가진 클래스 사이에서 이뤄질 수 있습니다.


### 생각해보기

#### 1) 우리가 지금까지 많이 사용해 왔던 자바의 api에서 overload와 override의 예를 찾아보세요

- 오버로딩 : 수학 메소드에서 절대값이나 반올림 같은 수학적기호에서 int타입이나 double 타입으로 매개변수를 넣어서 사용한점

- 오버라이딩 : 부모 몬스터 클래스에 자식 몬스터 종류에 따라서 상속받아서 재정의해서 쓰이는 경우 


## 4. This Super

- 핵심 단어
```
this
super
```

- Super

this는 인스턴스를 가리키는 키워드입니다.
이와 비슷하게 부모 클래스를 가리키는 super라는 키워드도 존재합니다.
자식 클래스에서 super를 이용하여 접근 권한이 부여된 부모 클래스의 변수와 메소드에 접근할 수 있습니다.

``` java
//Cal3에서 Cal의 변수와 메소드에 접근하기 위해서 super를 이용할 수 있습니다.
//이를 이용해서 오버라이딩하는 메소드에서 기존의 작업 앞 뒤로 손쉽게 추가적인 작업을 더 넣을 수 있게 됩니다.
class Cal {
	public int sum(int v1, int v2) {
		return v1 + v2;
	}
	// Overloading
	public int sum(int v1, int v2, int v3) {
		return this.sum(v1, v2) + v3;
	}
}
class Cal3 extends Cal{
	// Overriding
	public int sum(int v1, int v2) {
		System.out.println("Cal3!!!");
		return super.sum(v1, v2);
	}

	public int minus(int v1, int v2) {
		return v1 - v2;
	}
```

### 생각해보기

#### 1) super 키워드는 어떤 점에서 편리한가요?

## 5. 상속과 생성자

- 핵심 단어
```
상속
생성자
```


자식 클래스의 생성자

부모 클래스에 생성자가 있는 경우에 자식 클래스의 생성자는 무엇을 호출할까요?

자식 클래스에 이미 해당하는 생성자가 만들어져 있다면 그것을 호출하겠지만, 

그렇지 않다면 암묵적으로 부모 클래스의 생성자(super())를 호출하게 됩니다.

하지만 상속관계에 있는 클래스의 생성자에 기본 생성자(인자가 전혀 없는 생성자)가 아닌 

인자가 포함된 생성자를 사용하는 경우 주의해야 합니다.

위와 같이 부모 클래스에 기본 생성자가 아닌 인자를 주는 생성자만 명시된 경우,

자식 클래스에서 생성자를 명시적으로 만들지 않는다면 컴파일이 되지 않습니다.

왜냐하면, 자식 클래스에서 생성자를 호출하는 경우(인스턴스 생성),

정의한 생성자가 없기 때문에 부모 클래스의 생성자(super())를 사용해야 하는데,

명시적으로 인자를 받는 생성자만 부모 클래스에 만들어져 있기 때문에 

기본 생성자가 없는 것으로 받아들여지기 때문입니다.

자식 클래스의 경우에도, 기본 생성자는 명시적으로 만들지 않고,

인자를 받는 생성자만 만들었을 경우에는 인수를 주지 않고 인스턴스를 생성할 수 없습니다.


``` java
class Cal{
    int v1,v2;
    Cal(int v1, int v2){
        System.out.println("Cal init!!");
        this.v1 = v1; this.v2 = v2;
    }
    public int sum(){return this.v1+v2;}
}
class Cal3 extends Cal{
    Cal3(int v1, int v2) {
        //따라서 부모 클래스에 인자를 받는 생성자만 만들었을 경우에는,
        //다음과 같이 자식 클래스에도 인자를 받는 생성자를 만들어야 합니다.
        super(v1, v2);
        System.out.println("Cal3 init!!");
    }
    public int minus(){return this.v1-v2;}
}
public class InheritanceApp {
    public static void main(String[] args) {
        Cal c = new Cal(2,1);
        Cal3 c3 = new Cal3(2, 1);
        System.out.println(c3.sum()); // 3
        System.out.println(c3.minus()); // 1
    }
}
```


### 생각해보기

#### 1) 왜 인자를 받는 생성자를 만들게 되면 기본 생성자는 암묵적으로 만들어지지 않을까요?


## 6. 수업을 마치며

- 핵심 단어
```
다형성(polymorphism)
접근 제어자
Final
Abstract class
```

- 다형성(polymorphism)은 상속 관계에 있는 클래스간의 호환성을 높여주는 기능입니다.

우리가 인스턴스를 생성할 때, 같은 클래스의 자료형을 가진 변수를 선언하여 

인스턴스를 생성해 왔습니다.

그런데 부모 클래스의 자료형을 가진 변수를 선언하여 자식 클래스의 인스턴스를 생성할 수 있습니다.

그렇게 생성한 변수에서 자식 클래스의 변수나 메소드를 호출할 수 있습니다.



- 접근 제어자(access modifier)는 우리가 public과 private에 대해서 이미 알아본 바가 있습니다.

접근 제어자에는 이 외에도 default, protected라는 두 개의 접근 제어자가 더 있습니다.

default의 경우 같은 패키지 내의 클래스에서는 접근할 수 있는 권한이 있고, 

protected의 경우 해당 클래스와 자식 클래스를 통해서 접근할 수 있습니다.



- final 키워드는 상속과 관련하여 제한을 걸어주는 키워드 입니다.

만약 현재 클래스에서 더 이상 자식 클래스를 생성하지 못하게 막기 위해서는 

클래스에 final 키워드를 삽입합니다.

그리고, 메소드가 자식 클래스에서 더 이상 오버라이드 되기를 원하지 않는다면

메소드에 final 키워드를 삽입합니다.



- abstract 키워드는 해당 클래스, 메소드가 재정의가 필요하다는 것을 강제하는 키워드 입니다.

abstract 메소드는 선언만 되어 있는 상태이고, abstract 클래스는 인스턴스로 만들 수 없습니다.

만약 클래스 안에 abstract 메소드가 있다면 그 클래스는 abstract 클래스여야 합니다.

- 면접문제 그럼 상속과 합성의 차이는 무엇인가?

- Inheritance

예를 들어 위와 같이 Point 클래스가 있고 Point 클래스의 멤버 변수를 모두 포함하는 Circle 클래스가 있을 때 Point 클래스를 상속한다면 아래와 같이 표현할 수 있다.
``` java 
class Circle extends Point {
    int r;
}
```
- Composition
Composition은 클래스 간에 포함(composite) 관계를 맺어주는 것,
즉, 한 클래스의 멤버변수로 다른 클래스 타입의 참조 변수를 선언하는 것을 의미한다.

``` java 
class Circle {
    Point c = new Point();
    int r;
}
```
위와 같이 Point 클래스를 Circle 클래스의 멤버 변수로 선언함으로써 포함 관계를 맺을 수 있다.

그렇다면 상속 관계를 맺을지, 포함 관계를 맺을지는 어떻게 결정하면 좋을까?

- Circle is a Point.
- Circle has a Point

위의 예제에서는 원이 점이라기 보다는 원이 점을 가지고 있는 것이기 때문에 포함 관계를 맺어주는 것이 더 적합하다. 다시 말해 Inheritance는 object 사이에 is-a relationship을 갖고 있을 때 사용되며, compostion은 has-a relationship을 갖고 있을 때 사용된다.

### 생각해보기

#### 1) 어떻게 부모 클래스 타입의 인스턴스인데도 자식 클래스로 생성한 인스턴스라면 자식 클래스의 메소드를 사용하게 될까요?


## Quiz 4

1. 기존의 클래스가 갖고 있는 변수와 메서드를 포함한 기능을 확장하여 다른 클래스에게 물려주는 기능으로, 유지 보수 및 가독성을 높이고, 코드 양을 줄일 수 있게 해주는 기능은 다음 중 무엇일까요? 답 : 상속

2. 부모 클래스가 갖고 있는 기능을 재정의하는 것을 무엇이라고 할까요? 답 : override

3. 같은 이름의 메서드를 클래스 내에서 중복해서 생성하는 것을 무엇이라고 할까요? 답 : overloading

4. 자신의 부모 클래스를 나타내는 키워드는 무엇일까요? 답 :super

5. 다음 코드의 출력 결과는 어떻게 될까요? 답 : Parent Child

``` java
class Parent {
    public Parent() {
        System.out.println("Parent");
    }
}
class Child extends Parent {
    public Child() {
        System.out.println("Child");
    }
}

public class Main
{
    public static void main(String[] args) {
        Child c = new Child();
    }
}
```

6. 다음 중 접근 제어자 (Access Modifiers) 가 아닌 것은 무엇일까요? 답 : personal

7. 변수를 마음대로 수정하지 못하게 하려면 다음 중 어느 키워드를 쓸 수 있을까요? 답 : final

8. 클래스를 상속하려는 대상에게 특정 메소드 구현을 강제하게 할 수 있는 기능은 무엇일까요? 답 : abstract

9. 다음 코드의 예상 출력 결과는 어떻게 될까요? 답 : 90
``` java 
class Calc {
    public int run(int a, int b) {
        return a + b;
    }
}
class MyCalc extends Calc {
    public int run(int a, int b) {
        return a - b;
    }
}

public class Main
{
    public static void main(String[] args) {
        MyCalc myCalc = new MyCalc();
        System.out.println(myCalc.run(100, 10));
    }
}

```







