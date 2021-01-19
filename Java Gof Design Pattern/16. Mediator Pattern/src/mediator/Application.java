package mediator;

import contract.Colleague;
import contract.Mediator;

//M:N관계를 1:1 로 변경하기
//미디에이터 패턴을 통해 복잡한 관계를 간단한 관계로 구현한다.
public class Application {

	public static void main(String[] args) {
		Mediator mediator = new ChatMediator();
		
		Colleague colleague1 = new ChatColleague(); //인스턴스 생성
		Colleague colleague2= new ChatColleague();
		Colleague colleague3= new ChatColleague();
		
		colleague1.join(mediator); //조인 1
		colleague2.join(mediator); //조인 2
		colleague3.join(mediator); //조인 3
		
		colleague1.sendData("AAA"); //주고받음 AAA, AAA , AAA
		colleague2.sendData("BBB"); //BBB, BBB, BBB
		colleague3.sendData("CCC"); //CCC, CCC, CCC
		
	}
}
