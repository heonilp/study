
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        map<int, vector<int>> mp;
        
        for (vector<int> v : buildings) 
        {
            mp[v[0]].push_back(v[2]);
            mp[v[1]].push_back(-v[2]);
        }
        
        vector<vector<int>> o;
        int prev=0;
        
        map<int, int> w;
        
        for (auto it=mp.begin(); it!=mp.end(); it++) 
        {
            for (int e : it->second) 
            {
                if (e<0) 
                {
                    w[-e]--;
                    if (w[-e]==0) w.erase(-e);
                }
                else 
                {
                    w[e]++;
                }
            }
            int curr;
            
            if (w.size()==0) curr = 0;
            else curr = w.rbegin()->first;
            
            if (curr != prev) 
            {
                vector<int> row = {it->first, curr};
                o.push_back(row);
            }
            prev = curr;
        }
        return o;
    }
};