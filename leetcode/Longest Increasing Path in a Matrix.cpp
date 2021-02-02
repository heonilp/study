//BFS방식으로 풀기, DFS으로도 풀수있음!
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i+1<m && matrix[i][j] > matrix[i+1][j]){
                    v[i][j]++;
                }
                if(i-1>=0 && matrix[i][j] > matrix[i-1][j]){
                    v[i][j]++;
                }
                if(j+1<n && matrix[i][j] > matrix[i][j+1]){
                   v[i][j]++;
                }
                if(j-1>=0 && matrix[i][j] > matrix[i][j-1]){
                    v[i][j]++;
                }
                if(v[i][j]==0){
                    q.push(make_pair(i,j));
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int p = q.size();
            while(p>0){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i+1<m && matrix[i][j] < matrix[i+1][j]){
                    v[i+1][j]--;
                    if(v[i+1][j]==0){
                        q.push(make_pair(i+1,j));
                    }
                }
                if(i-1>=0 && matrix[i][j] < matrix[i-1][j]){
                    v[i-1][j]--;
                    if(v[i-1][j]==0){
                        q.push(make_pair(i-1,j));
                    }
                }
                if(j+1<n && matrix[i][j] < matrix[i][j+1]){
                    v[i][j+1]--;
                    if(v[i][j+1]==0){
                        q.push(make_pair(i,j+1));
                    }
                }
                if(j-1>=0 && matrix[i][j] < matrix[i][j-1]){
                    v[i][j-1]--;
                    if(v[i][j-1]==0){
                        q.push(make_pair(i,j-1));
                    }
                }
                p--;
            }
            ans++;
        }
        return ans;
    }
};