
//이문제는 A+B에서 -나 +를 쓰지않고 푸는 문제입니다.

class Solution {
public:
    int getSum(int a, int b) 
    {
        unsigned int c;
        
        while(b!=0)
        {
            c = (a & b);
            a = a ^ b;
            b = (unsigned int)(c) << 1;
        }
        return a;
    }
};


class Solution {
public:
    int getSum(int a, int b) {
        
        int ans = 0;
        
        if(a>0)
        {
            for(int i = 0 ; i < a; i++)
            {
                ans++;
            }
            
        }
        else if(a<0)
        {
           
            for(int i =a; i<0; i++)
            {
                ans--;
            }
           
        }
        

        
        if(b>0)
        {
            for(int i = 0 ; i < b; i++)
            {
                ans++;
            }
        }
        
        else if(b<0)
        {
            for(int i =b; i<0; i++)
            {
                ans--;
            }  
        }

        
        return ans;
    }
};