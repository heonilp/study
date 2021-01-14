//재귀로 얍얍!

class Solution {
    bool go(string& s, int i, vector<string>& wordDict, vector<bool>& v)
    {
        if(i >= s.length())
        {
            return true;
        }
        
        if (v[i]!=0) return false;
       
        for(const auto& word: wordDict)
        {
            if(word.length() > s.length() - i)
            {
                continue;
            }    
            
            string str(s.c_str() + i, word.length());
            
            if(str == word && go(s, i + word.length(), wordDict, v))   
            {
               return true;
            }
        }
        
        v[i] = true;
        
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    { 
        vector<bool> visited(s.length(), false);
        
        return go(s, 0, wordDict, visited);
    }
};