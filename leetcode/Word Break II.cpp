
class Solution {
public:
    vector<string> go(string s, int idx, unordered_set<string> &words, unordered_map<int, vector<string>> &a){
        vector<string> res, sub;
        int n = s.size();
        if(n==idx)
        {
            res.push_back(" ");
            return res;
        }
        if(a.count(idx)) return a[idx];
        
        string temp="";
        for(int i=idx; i<n; ++i)
        {
            temp += s[i];
            if(words.count(temp))
            {
                sub = go(s, i+1, words, a);
                for(auto s : sub)  res.push_back(s == " "?temp:temp+" "+s);
            }
        }
        return a[idx]=res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<int, vector<string>> a;
        unordered_set<string> words;
        for(string s : wordDict) words.insert(s);  
        
        return go(s,0,words,a);
    }
};