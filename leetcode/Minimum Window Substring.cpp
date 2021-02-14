class Solution {
public:

    string minWindow(string s, string t)
    {
        std::vector<int> v(126, 0);
        for (char& ch : t) 
        {
            v[ch]++;
        }
        
        int l = INT_MAX;
        int ans = -1;
        int c = 0;

        int st = 0;
        
        for (int ed = 0; ed < s.length(); ed++) {
            
            if (--v[s[ed]] >= 0)
            {
                c++;
            }
            
            while (c == t.length()) 
            {
                int length = ed - st + 1; 
                if (l > length) 
                {
                    l = length;
                    ans = st;
                }
                
                
                if (++v[s[st]] > 0)
                {
                    c--;
                }
                st++;
            }
        }
        return ans == -1 ? "" : s.substr(ans, l);
    }
};