class Solution {
public:
    
  map<char, int> m_v = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
    
  int romanToInt(string s) 
  {
     
        int ans = 0;
      
        for(int i = 0; i < s.size(); ++i)
        {
            if(m_v[s[i+1]] <= m_v[s[i]])
            {
                ans = ans + m_v[s[i]];
            }
            
            else if(m_v[s[i+1]] > m_v[s[i]])
            {
                ans = ans - m_v[s[i]];
            }
        }
      
        return ans;
    }
};