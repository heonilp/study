class Trie {
public:
    /** Initialize your data structure here. */
    unordered_map<string,bool> s;
    unordered_map<string,bool> p;
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        if(s.find(word)==s.end())
        {
            s[word]=true;
            
            for(int i=0;i<=word.size();i++)
            {
                p[word.substr(0,i)]=true;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        if(s.find(word)!=s.end())
        {
            return true;
        }
            
        return false;      
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        if(p.find(prefix)!=p.end())
        {
            return true;
        }
        return false;
    }
};