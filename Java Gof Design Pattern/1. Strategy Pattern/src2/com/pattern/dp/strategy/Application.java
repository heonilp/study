package com.pattern.dp.strategy;

public class Application {

	//학습목표
	
	//인터페이스
	//기능 선언, 기능을 분류할수 있는것, 기능을 접근접근
	//인터페이스의 역할은 코드 작성하는 사람에게 일정한 컨벤션을 제공하고
	//나중에 코드 보는 사람들한테 어떤 기능이 있는지 안내하는 것
	//델리케이트
	//위임
	//전략패턴
	// 다양한 알고리즘을 접근점을 구현하고 변경가능하게 하는 것

	public static void main(String[] args) {
		
		GameCharacter character = new GameCharacter();
		
		character.setWeapon(new Sword());
		character.attack();
		
		character.setWeapon(new Ax());
		character.attack();
		
		character.setWeapon(new Knife());
		character.attack();
	}
	
}
