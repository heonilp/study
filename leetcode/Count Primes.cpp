1.모든 소수에 대해서 검사

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        if(n==3) return 1;
        
        int ans = 1;
        bool f = false;
        
        for(int i=3; i<n; i+=2)
        {
            f = true;
            
            for(int j=3; j*j<=i; j+=2)
            {
                if(i%j == 0) 
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                ans++;
            }
            
        }
        return ans;
        
    }
};


2. 수정한 방법 - 저는 같이 체크하는 방식으로..

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> notP (n, false);
        int ans = 0;

        for (int i = 2; i < n; i++) 
        {
            if (notP[i]==false) 
            {
                ans++;    
                for (int j = 2; i * j < n; j++)
                {
                    notP[i * j] = true;
                }
            }
        }
        
        return ans;
    }
};