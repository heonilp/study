package facade;

//퍼사드 패턴
//복잡한 과정을 간단하게 제공
//복잡한 과정을 간단하게 표현하는 퍼사드 패턴을 이해한다.
//단순한 접근 , 클라이언트한테 함수를 제공한다.
import facade.system.Facade;

public class Application {

	public static void main(String[] args) {
		Facade facade = new Facade();
		facade.process();
	}
}
