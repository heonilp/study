package singleton;

public class Application {
	//객체 : 속성과 가능을 갖춘것
	// 클래스 ; 속성, 기능을 정의한것
	//인스턴스 : 속성과 기능을 가진것중에 실제하는것
	//전역 변수를 사용하지 않고 객체를 하나만 생성 하도록 하며, 생성된 객체를 어디에서든지 참조할 수 있도록 하는 패턴
	public static void main(String[] args) {
		SomeSystemComponent component = SomeSystemComponent.getInstance();
		
	}

}
