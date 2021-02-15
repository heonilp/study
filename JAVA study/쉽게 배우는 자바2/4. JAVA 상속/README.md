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
