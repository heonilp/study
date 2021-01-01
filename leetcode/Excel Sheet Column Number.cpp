class Solution {
public:
    int titleToNumber(string s) 
    {
        int ans = 0;
        int a = static_cast<int>('A') -1;
        unsigned int p = 1;
        
        for(int i = s.size() -1 ; i >=0  ; --i)
        {
            ans += p*(static_cast<int>(s[i]) - a);
            p *=26;
        }
        
        return ans;
        
    }
};