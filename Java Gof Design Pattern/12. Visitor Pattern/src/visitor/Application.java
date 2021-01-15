package visitor;
import java.util.ArrayList;

import visitor.concrete.VisitableA;
import visitor.concrete.VisitorA;
import visitor.contract.Visitable;

//방문자 패턴을 이용하여 객체에서 처리를 분리해서 사용할수있다.
//객체/ 처리/ 분리
//왜 필요하냐 ? 유지보수

//참고
//https://thecodinglog.github.io/design/2019/10/29/visitor-pattern.html
public class Application {

	public static void main(String[] args) {
		
		ArrayList<Visitable> as = new ArrayList<Visitable>();
		
		as.add(new VisitableA(1));
		as.add(new VisitableA(2));
		as.add(new VisitableA(3));
		as.add(new VisitableA(4));
		as.add(new VisitableA(5));
		
		VisitorA visitor = new VisitorA();
		for (Visitable va : as) {
			va.accept(visitor);
		}
		System.out.println(visitor.getNumber());
	}
}


