package com.pattern.dp.strategy;

public class Sword implements Weapon {

	/**
	 * 내구성, 공격력, 특수 능력 등
	 */

	public int doAttack() {
		System.out.println("검 공격");
		return 0;
	}

}
