package com.pattern.dp.strategy;

public class GameCharacter {

	// 체력,마력,스테미너 등..
	//접근가능
	private Weapon weapon;

	public int attack() {
		//델리게이트, 전략패턴
		//어떤것을 사용하는거에 따라서 달라짐.
		//전략 패턴 ( Strategy Pattern )
		//객체들이 할 수 있는 행위 각각에 대해 전략 클래스를 생성하고, 유사한 행위들을 캡슐화 하는 인터페이스를 정의하여,
        //객체의 행위를 동적으로 바꾸고 싶은 경우 직접 행위를 수정하지 않고 전략을 바꿔주기만 함으로써 행위를 유연하게 확장하는 방법을 말합니다.
		return weapon.doAttack();
	}

	//교환 가능
	public void setWeapon(Weapon weapon) {
		this.weapon = weapon;
	}

}
