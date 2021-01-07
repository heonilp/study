package com.templatemethod;

public class Application {

	//템플릿 : 사전적의미 : 모양자
	//알고리즘의 구조를 메소드에 정의 하고 하위클래스에서 알고리즘 구조의 변경없이 알고리즘을 재정의하는 패턴
	//구현하는 알고리즘이 일정한 프로세스가 있다.
	//구현하려는 알고리즘 변경가능성이 있다.
	//방법
	//여러단계로 나눈다
	//단계를 메소드로 선언한다.
	//템플릿메소드를 만든다
	//하위클래스에서 나눠진 메소드를 구현한다.
	
	public static void main(String[] args) {
		AbstConnectHelper abstConnectHelper = new ConcreteConnectHelper();
		
		abstConnectHelper.requestConnection("info");
	}

}
