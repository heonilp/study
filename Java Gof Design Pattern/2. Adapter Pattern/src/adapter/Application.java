package adapter;

public class Application {

	//어댑터 패턴 (adapter pattern)
	//한 클래스의 인터페이스를 클라이언트에서 사용하고자하는 다른 인터페이스로 변환한다.
	//어댑터를 이용하면 인터페이스 호환성 문제 때문에 같이 쓸 수 없는 클래스들을 연결해서 쓸 수 있다.
	//어댑터 패턴은 구조 패턴(Structural Pattern) 중 하나로, 서로 관계없는 인터페이스들을 함께 사용할 수 있게 하는 패턴입니다.

	public static void main(String[] args) {

		//요구사항을 수행하는 인스턴스
		Adapter target = new AdapterImpl();
		
		System.out.println(target.twiceOf(100.0f));
		System.out.println(target.halfOf(100.3f));
		
	}
	
	
}
