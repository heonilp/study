package memento;

import java.lang.Thread.State;
import java.util.Stack;
import java.util.StringTokenizer;

import memento.abc.Memento;
import memento.abc.Originator;

//설명
//메멘토 : 기념품 ,유품, 추억거리
//상태의 상태를 저장했다가 이전의 상태로 돌림

//메멘토 패턴을 통해 객체체의 상태를 저장하고 이전의 상태로 복구한다.
//접근제한자 protected를 이해한다.
//중요 : protected을 써서 밖에서 값을 수정 못하게 막는다.
//protected : 상속 받은 내, 패키지 내에서 만 접근 가능
//키워드 : 복구
public class Application {

	public static void main(String[] args) {
		
		Stack<Memento> mementos = new Stack<>();
		
		Originator originator = new Originator();
		
		originator.setState("state 1");
		mementos.push(originator.createMemento());
//		Memento memento = new Memento();//X
//		memento.getState();//X
		originator.setState("state 2");
		mementos.push(originator.createMemento());
		originator.setState("state 3");
		mementos.push(originator.createMemento());
		originator.setState("state Final");
		mementos.push(originator.createMemento());
		
		originator.restoreMement(mementos.pop());
		System.out.println(originator.getState());//state Final
		originator.restoreMement(mementos.pop());
		System.out.println(originator.getState());//state 3
		originator.restoreMement(mementos.pop());
		System.out.println(originator.getState());//state 2
		originator.restoreMement(mementos.pop());
		System.out.println(originator.getState());//state 1
	
		
	}
}
