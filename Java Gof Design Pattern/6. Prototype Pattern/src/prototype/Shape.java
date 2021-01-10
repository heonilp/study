package src.prototype;

//자바는 Cloneable라는 인터페이스가 정의되어있다.
public abstract class Shape implements Cloneable {

	private String id;

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

}
