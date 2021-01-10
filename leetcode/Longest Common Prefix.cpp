class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int n=strs.size();
        
        if(n==0)return "";
        
        int ans = INT_MAX;
         
        for(int i=1;i<n;i++)
        {
            int cnt=0;
            int m = min(strs[0].size(),strs[i].size());
            
            for(int j=0;j<m;j++)
            {
                if(strs[0][j]==strs[i][j])
                {
                    cnt++;
                }
                else 
                {
                    break;
                }
            }
            ans = min(ans,cnt);
        }
        
        return strs[0].substr(0,ans);
    }
};