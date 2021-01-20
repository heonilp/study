
//메모리 절약
//48 <<플라이급<<51
//플라이웨이트 패턴을 통해 메모리 공간을 절약할 수있다.
//플라이웨이트를 누가 관리해줘야함
public class Flyweight {

    public Flyweight(String data){
        this.data =data;
    }

    private  String data;

    public String getData() {
        return data;
    }
}
