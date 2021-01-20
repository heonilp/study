
//대리인 내새우기
//프록시 패턴을 통해 작업을 나눠서 구현할수 있다.

public  interface Subject {
	void action1();// 리소스가 적게 드는일
	
	void action2();// 리소스가 많이 드는일, 네트워크 메모리
}