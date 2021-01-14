package chapter11;

import java.util.Scanner;

import chapter11.abst.IBeverage;
import concrete.Base;
import chapter11.concrete.Espresso;
import chapter11.concrete.Milk;

//데코레이션 패턴
//동적으로 책임추가 필요할때 사용할수있다.
// 동적(실시간으로변화), 책임(할수 있는 일, 기능)

//예제 커피 제조방법
//에스프레소 : 커피의 기본
//아메리카노 : 에스프레소 +물
//카페라떼 : 에스프레소 + 스팀밀크
//헤이즐넛 : 아메리카노 + 헤이즐넛 시럽
//카페모카 : 카페라뗴 + 모카시럽
//카라멜마키야또 : 라떼 + 시럽


public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		// base
		IBeverage beverage = new Base();
		boolean done = false;
		while (!done) {
			System.out.println("음료 현재 가격 : "+beverage.getTotalPrice());
			System.out.print("선택 : 1:샷 추가 / 2:우유 추가");
			switch (sc.nextInt()) {
			case 0: done = true;
				break;
			case 1: 
				beverage = new Espresso(beverage);
				break;
			case 2:
				beverage = new Milk(beverage);
				break;
			}
		}

		System.out.println("음료 가격 : "+beverage.getTotalPrice());
		sc.close();
	}

}
