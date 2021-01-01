class Solution {
public:
    bool isAnagram(string s, string t) {
        
       if(s.size() != t.size())  return false;
        
      int ans['z' - 'a' + 1] = {};
        
        for (int i = 0; i < s.size(); ++i) 
        {
            ans[s[i] - 'a']++;
            ans[t[i] - 'a']--;
        }
        
        for (int d : ans)
            if (d != 0)
                return false;
        
        return true;
    }
};