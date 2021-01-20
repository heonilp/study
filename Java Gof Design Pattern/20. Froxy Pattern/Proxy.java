
//대리인 내새우기
//프록시 패턴을 통해 작업을 나눠서 구현할수 있다.

public  class Proxy implements Subject{

	private  Subject real;

	public Proxy(){
		real = new RealSubject();
	}

	@Override
	void action1(){
		System.out.println("간단한 업무");
	}// 리소스가 적게 드는일


	@Override
	void action2(){
		//System.out.println("");

	}// 리소스가 많이 드는일, 네트워크 메모리
}