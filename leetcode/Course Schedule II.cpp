class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) 
    {
        int m=arr.size();
        int cnt=0;
        vector<int> v[n];
        vector<int> g(n,0);
        
        for(int i=0;i<m;i++)
        {
            v[arr[i][1]].push_back(arr[i][0]);
            g[arr[i][0]]++;
        }
        
        vector<int> ans;
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(g[i]==0) q.push(i);
        }
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            
            for(auto v:v[u])
            {
                if(--g[v]==0) q.push(v);
            }
            cnt++;
        }
        
        if(cnt!=n) return {};
    
        return ans;
    }
};