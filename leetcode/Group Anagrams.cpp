
//2번으로 풀어달라고해서 다시풀었습니다.
//1. 소트해서 하기.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
        //간단히 맵으로 넣고
        unordered_map<string, vector<string>> d;

        //안에 있는데이터를 소팅하고 d에 넣음
        for(auto &input : strs)
        {
            string data = input;
            sort(data.begin(), data.end());
            d[data].push_back(input);
        }
        
        
        vector<vector<string>> ans;
        //답에 넣음
        for(auto &e : d)
        {
            ans.push_back(e.second);
        }

        return ans; 
    }

};

//2. 소수값 이용해서 key 하기
class Solution {
public:
    int mod = 1e9 + 7;
    
    int hash(string s, vector<int>& p, int mod) 
    {
        long long key = 1;
        
        for (char c : s)
        {
            key = key * p[c - 'a'] % mod;
        }
        
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<int, int> v;
        
        vector<vector<string>> ans;
        
        vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        

        for (string str : strs) 
        {
            
            int key = hash(str, p, mod);
            
            auto it = v.find(key);
            
            if (it == v.end()) 
            {
                v[key] = ans.size();
                
                vector<string> vec;
                
                vec.push_back(str);
                
                ans.push_back(vec);
            } 
            else 
            {
                ans[it->second].push_back(str);
            }
        }
        return ans;
    }
};