package state;

//상태를 객체로 나타내기
//상태 패턴을 통해 상태를 객체로 나타내고 행동을 구현한다.
//전략패턴 : 알고리즘 바꿈 vs 상태패턴 : 이벤트, 액션을 발생한걸 바꿈(상태를 바꿈)

public class Application {
	public static void main(String[] args) {
		Light light = new Light();
		
		light.off();
		light.off();
		light.off();
		
		light.on();
		light.on();
		light.on();
		
		light.off();
		light.on();
		light.off();
		light.on();
		light.off();
		light.on();
	}
}
