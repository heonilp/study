
//메모리 절약
//48 <<플라이급<<51
//플라이웨이트 패턴을 통해 메모리 공간을 절약할 수있다.
//플라이웨이트를 누가 관리해줘야함 ->FlyweightFactory
//pool에 넣어서 관리함
public class Main {

	public static void main(String[] args) {
		FlyweightFactory factory = new FlyweightFactory();

		Flyweight flyweight = factory.getFlyweight("A");

		System.out.println(flyweight);

		//메모리 사용이 재사용한다.
		flyweight = factory.getFlyweight("A");

		System.out.println(flyweight);

		flyweight = factory.getFlyweight("B"); // 새로생성

		System.out.println(flyweight);


		flyweight = factory.getFlyweight("B"); //재사용

		System.out.println(flyweight);
	}

}
