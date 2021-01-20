import  java.util.Map;
import  java.util.TreeMap;
//메모리 절약
//48 <<플라이급<<51
//플라이웨이트 패턴을 통해 메모리 공간을 절약할 수있다.
//플라이웨이트를 누가 관리해줘야함


//매니저같은 존재
public class FlyweightFactory {
    Map<String, Flyweight> pool;

    public  FlyweightFactory(){
        pool =new TreeMap<>();
    }

    public  Flyweight getFlyweight(String key){
        Flyweight flyweight = pool.get(key);

        if(flyweight ==null){
            flyweight = new Flyweight(key);

            pool.put(key ,flyweight);
            System.out.println("새로생성"+key);
        }else{
            System.out.println("재사용"+key);
        }

        return flyweight;
    }


}
