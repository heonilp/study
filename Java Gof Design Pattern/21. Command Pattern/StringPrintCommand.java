
//대리인 내새우기
//프록시 패턴을 통해 작업을 나눠서 구현할수 있다.

public class StringPrintCommond {

	protected   String string;

	public StringPrintCommond(String string){
		this.string = string;
	}

	@Override
	public  int compareTo(Commend o) {
		StringPrintCommond other = (StringPrintCommond)o;
		return  this.string.length() -other.string.length();
	}

	@Override
	void execute(){
		System.out.println(this.string);
	}

}