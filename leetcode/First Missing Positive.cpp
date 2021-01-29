// C++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map <int, int> m;
        
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = 1;
        }
              
        int i = 1;
        while (i)
        {
            if (m[i] != 1) return i;
            i++;
        }
        
        return -1;
    }
};


// java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int result = 0;
        HashMap<Integer,Integer> m = new HashMap<>();
        for(int i=0;i<nums.length;i++){ 
            m.put(nums[i],1);
        }
        
        for(int i=1;i<Integer.MAX_VALUE;i++)
        {
            if(!m.containsKey(i)){
                result = i;
                break;
            }
        }
        return result;
    }
}

/* JAVA HashMap 사용 연습
import java.util.HashMap;

public class test {
    public static void main(String[] args) {
        HashMap<String, Integer> hashMap = new HashMap<String, Integer>();
        hashMap.put("A",1);

        if (hashMap.containsKey("A")) {
            Integer value = hashMap.get("A");
            hashMap.put("A", ++value);
        }

        System.out.println(hashMap);
    }
}


*/