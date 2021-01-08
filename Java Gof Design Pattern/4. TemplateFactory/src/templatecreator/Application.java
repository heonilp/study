package templatecreator;

import com.parkgaram.dp.templatecreator.fw.Creator;
import com.parkgaram.dp.templatecreator.fw.Item;

public class Application {

	//팩토리 메소드 패턴
	//객체를 생성하기 위한 인터페이스를 정의하고, 인스턴스 생성은 서브클래스가 결정하게 한다
	//객체 생성 처리를 서브 클래스로 분리 해 처리하도록 캡슐화하는 패턴
	//팩토리 메소드 패턴에는 템플릿 메스드 패턴의 사용됨을 안다.
	//팩토리 메소드 패턴에서는 구조와 구현을 분리를 이해하고 구조와 구현의 분리의 장점안다.
	public static void main(String[] args) {
		
		Creator creator = new DefaultItemCreator();

		Item item1 = creator.create("나무칼");
		Item item2 = creator.create("나무방패");
		Item item3 = creator.create("나무갑주");
		
		item1.use();
		item2.use();
		item3.use();
	}

}
