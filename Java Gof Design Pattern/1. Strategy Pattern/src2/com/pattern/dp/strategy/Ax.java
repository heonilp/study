package com.pattern.dp.strategy;

public class Ax implements Weapon {

	/**
	 * 내구성, 공격력, 특수 능력 등
	 */

	public int doAttack() {
		System.out.println("도끼 공격");
		return 0;
	}

}
