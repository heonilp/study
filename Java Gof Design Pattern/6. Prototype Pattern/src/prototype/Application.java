package src.prototype;

public class Application {

	//학습 목표
	//프로토 타입 패턴을 통해 복잡한 인스턴스를 복사할수 있다.
	//원형, 객체 
	//생산 비용이 높은 인스턴스 복사를 통해 쉽게 생성할수 있도록하는 패턴
	//인스턴스 생산 비용이 높은경우
	//1.종료가 너무많아서 클래스로 정의되지않은경우
	//2.클래스로부터 인스턴스 생성이 어려운경우
	public static void main(String[] args) throws CloneNotSupportedException {

		Circle circle1 = new Circle();

		circle1.setId("1");

		circle1.setX(1);
		circle1.setY(1);
		circle1.setR(3);

		circle1.a.x = 1;

		//복사, 이렇게 하지않고 바로 넣으면 동일한 주소값을 가리켜서 동일한게 나온다.
		Circle circle2 = (Circle) circle1.copy();

		System.out.println(circle1.a.x);
		System.out.println(circle2.a.x);

		circle1.a.x = 2;

		System.out.println(circle1.a.x);
		System.out.println(circle2.a.x);

		circle2.a.x = 3;

		System.out.println(circle1.a.x);
		System.out.println(circle2.a.x);

	}

}
