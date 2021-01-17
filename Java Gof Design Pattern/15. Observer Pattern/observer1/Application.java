package observer;

// 옵저버 : 상태변화 관찰하기
// 옵저버 패턴을 통해 이벤트발생 후 객체 외부에서 처리 할수 있다.
//객체 외부, 이벤트 처리
import observer.Button.OnClickListener;

public class Application {

	public static void main(String[] args) {
		
		Button button = new Button();
		
		//익명 클래스
		button.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(Button button) {
				System.out.println(button+" is Clicked");
			}
		});
		
		button.onClick();
		
	}

}
