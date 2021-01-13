
public class Main {

	//브릿지 패턴 : 기능 계층과 구현 계층의 분리

	//브릿지패턴에 대해서이해
	//어댑터 패턴과 브릿지 패턴을 연결하여 이해
	// 모스부호로 강의를 찍으셨다함.
	public static void main(String[] args) {
		PrintMorseCode code = new PrintMorseCode(new FlashMCF());

		code.g().a().r().a().m();
	}
}
