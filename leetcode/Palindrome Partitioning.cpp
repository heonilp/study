//백트래킹으로 풀기

class Solution {
public:
    bool go(string str, int s, int e)
    {
        while(s <= e)
        {
            if(str[s] != str[e])
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> v;
        vector<string> p;
        b(s, v, p, 0);
        return v;
    }

    void b(string s, vector<vector<string>> &v, vector<string> p,  int start)
    {
        if(start == s.length())
        {
            v.push_back(p);
            return;
        }

        for(int i = start; i < s.length(); i++)
        {
            if(go(s, start, i))
            {
                p.push_back(s.substr(start, i - start + 1));
                b(s, v, p, i + 1);
                p.pop_back();
            }
        }
    }
};