class Solution {
public:
    bool isHappy(int n) {
        for(int i = 0; i < n; i++)
        {
            int ans = 0;
            
            while(n) 
            {
                ans += pow(n % 10, 2);
                n /= 10;
            }
            if(ans == 1) return true;
                
            n = ans;
        }
        return false;
    }
};