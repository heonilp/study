class Solution {
public:
    vector<string> fizzBuzz(int n) {
        //3,5배수면 벡터에 넣어주고, 아니면 숫자 문자열 변환해서 넣어줌
        vector<string> s;
        
        for(int i = 1; i <= n; i++)
        {
            if(i%3 ==0 && i%5 ==0)
            {
                s.push_back("FizzBuzz");
            }
            else if(i % 3 == 0)
            {
                s.push_back("Fizz");
            }
            else if(i % 5 ==0)
            {
                s.push_back("Buzz");
            }
            else
            {
                string putdata;
                putdata = to_string(i);
                s.push_back(putdata);
            }
             
        }  
        return s;
        
    }
};