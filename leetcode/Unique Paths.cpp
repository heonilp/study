//1. 아래 오른쪽 - dp 풀이

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> d (n, 0);
        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                if (i==0 || j==0)
                {
                    d[j] = 1;
                }
                else
                {
                    d[j] =  d[j] + d[j-1];
                }
            }
        }
        return d.back();
    }
};

//2. 신기한 풀이


class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        
        for(int i = n; i < (m + n - 1); i++){
            ans *= i;
            ans /= (i - n + 1);
        }
            return ans;
    }
};