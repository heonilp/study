//인터페이스로 만들어도 되나 설계자가 하기나름
//값을 가지려면 클래스로 만들어도 됨
abstract public class Component {

	public Component(String name) {
		this.name = name;
	}
	private String name;
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
}
