class Solution {
public:
    bool isMatch(string s, string p)
    {
        int sn=s.length();
        int pn=p.length();
        
        vector<vector<bool>> dp(sn+1,vector<bool>(pn+1,0));
        
        dp[0][0]=1;
        
        for (int j=1; j<=pn; ++j)
        {
          dp[0][j]=p[j-1] == '*' && dp[0][j-2];  
        } 
        
        for (int i=1; i<=sn; ++i) 
        {
            for (int j=1; j<=pn; ++j)
            {
                if (isalpha(p[j-1])) dp[i][j]=dp[i-1][j-1]&&s[i-1]==p[j-1];
                else if (p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=dp[i][j-2]||dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.');
            }
        }
        
        return dp[sn][pn];
        
    }
};