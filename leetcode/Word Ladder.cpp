

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord || wordList.size() == 0) return 0;
        unordered_map<string, bool> m;
        
        for(int i=0;i<wordList.size();i++)
        {
            m[wordList[i]] = false; 
        }
        
        if(m.find(endWord) == m.end()) return 0; 
        
        int n = beginWord.size();
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        m[beginWord] = true;
        
        while(!q.empty()) 
        {
            auto front  = q.front();
            q.pop();
            string cur_word = front.first;
            int cnt = front.second;
            if(cur_word == endWord) return cnt;
            
            for(int i=0;i<n;i++) 
            {
                char c = cur_word[i]; 
                for(int j=0;j<26;j++) 
                {
                    cur_word[i] = 'a'+j;
                    if(m.find(cur_word) != m.end() && !m[cur_word])
                    {
                        q.push({cur_word,cnt+1});
                        m[cur_word] = true;
                    }
                }
                cur_word[i] = c;
            }
        }
        return 0;
    }
};