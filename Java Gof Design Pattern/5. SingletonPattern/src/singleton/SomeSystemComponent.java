package singleton;

public class SomeSystemComponent {

	private static SomeSystemComponent instance;
	private int system;
	
	private SomeSystemComponent() {
		system= 5;
		
	}
	
	public static SomeSystemComponent getInstance(){
		if (instance == null) {
			//시스템
		}else {
			instance = new SomeSystemComponent();
		}
		return instance;
	}
}
