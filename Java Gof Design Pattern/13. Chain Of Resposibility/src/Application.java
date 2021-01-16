
//다양한 처리방식을 유현하게 연결할 수 있다.
//결합을 느슨하게 하기 위해 고안된 패턴
//
//
// 명령 객체와 일련의 처리 객체를 포함하는 디자인 패턴이다.
//각각의 처리 객체는 명령 객체를 처리할 수 있는 연산의 집합이고,
//체인 안의 처리 객체가 핸들할 수 없는 명령은 다음 처리 객체로 넘겨진다.
// 이 작동방식은 새로운 처리 객체부터 체인의 끝까지 다시 반복된다.
//가장 대표적인 연쇄 책임 패턴의 예는 Java 에서의 try catch 문의 있다.
public class Application {

	public static void main(String[] args) {
		
		Calculator plus = new PlusCalculator();
		Calculator sub = new SubCalculator();
		
		plus.setNextCalculator(sub);
		
		Request request1 = new Request(1,2,"+"); //3
		Request request2 = new Request(10,2,"-");//8
		
		plus.process(request1);
		plus.process(request2);
		
	}
}
