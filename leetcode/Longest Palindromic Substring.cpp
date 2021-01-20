//Manacher's_algorithm 보면 O(N)으로 풀수 있다는데... 흠...
//https://algospot.com/wiki/read/Manacher's_algorithm

class Solution {
public:
     string longestPalindrome(string s) {
         
        int n = s.size();
        if (n < 2) 
        {
            return s;
        }
         
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) 
        {
            dp[i][i] = true;
        }
         
        string ans = s.substr(0,1);
         
         
        for (int x = n-1; x >= 0; --x) 
        {
            for (int y = x + 1; y < n; ++y)
            {
                if (s[x] == s[y]) 
                {
                    if (y-x == 1 || dp[x+1][y-1])
                    {
                        dp[x][y] = true;
                        int len = y - x + 1;
                        
                        if (ranses.size() < len)
                        {
                            ans = s.substr(x, len);
                        }
                    }
                }
            }
        }
        return ans;
    
    }
};
