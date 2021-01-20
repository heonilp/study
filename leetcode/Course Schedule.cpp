//재귀로

class Solution {
public:
    bool dfs(int h, vector<int> a[], vector<bool> &v, vector<bool> &m){
        v[h] = true;
        m[h] = true;
        
        for(auto i: a[h])
        {
            if(v[i] && m[i]) return true;
            if(v[i]) continue;
            if(dfs(i, a, v, m)) return true;
        }
        m[h] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> a [numCourses];
        
        for(auto i: prerequisites)
        {
            a[i[1]].push_back(i[0]);
        }
        

        vector<bool> v (numCourses, false);
        vector<bool> m (numCourses, false);
        
        for(int i=0; i<numCourses; i++)
        {
            if(!v[i])
                if(dfs(i, a, v, m)) return false;
        }
        return true;
    }
};