class Solution {
public:
    bool isMatch(string s, string p) {

        int i = 0;
        int j = 0;
        int is = -1;
        int ip = -1;
        int n = s.size();
        int m = p.size();

        while (i < n)
        {
            if( j < m && s[i] == p[j])
            {
                i++;
                j++;
            }
            else if(j < m && p[j] == '?')
            {
                i++;
                j++;
            } 
            else if(j < m && p[j] == '*')
            {
                is = i;
                ip = j;
                j++;
            }
            else if(ip != -1)
            {
                j = ip + 1;
                i = is + 1;
                is++;
            }
            else
            {
                return false;
            }
        }

        while(j < m && p[j] == '*')
        {
            j++;
        }

        if(j == m)
        {
            return true;
        }

        return false;
    }
};

/*
class Solution {
public:
    bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();

    bool dp[2001][2001] = {false,};

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(!i && !j) 
            {
                dp[i][j] = true;
            }
            else if(!i && j)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
            else if(!j)
            {
                dp[i][j] = false;
            }
            else if(s[i-1] == p[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                if(p[j-1] == '*')
                {
                     dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }   
                else if(p[j-1] == '?')
                {
                     dp[i][j] = dp[i-1][j-1];
                }
                   
                else
                {
                      dp[i][j] = false;
                }
            }
        }
    }

    return dp[n][m];
  }
};
*/