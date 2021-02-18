# 5. JAVA 인터페이스 강좌

##  1. 수업소개

- 핵심 단어
```
인터페이스
```

``` java

interface Calculable {
	int sum(int v1, int v2);
}
class RealCal implements Calculable {

	public int sum(int v1, int v2) {
		return v1 + v2;
	}	
}
//인터페이스(Interface)를 이용하면 앞으로 만들 클래스의 메소드 규격을 선언할 수 있습니다.
```

인터페이스에서 이를 이용해서 만들 클래스의 메소드의 형식을 미리 선언하고, 
인터페이스를 이용해서(implements 키워드) 만드는 클래스는 인터페이스의 메소드를 정의합니다.

### 생각해보기
#### 1) 인터페이스는 어떻게 활용하면 좋을까요?
