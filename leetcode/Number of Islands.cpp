
//200. Number of Islands

class Solution {
public:
    
    void go(vector<vector<char>>& grid, int i, int j)
    {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size())
        {
            if(grid[i][j]=='1')
            {
                grid[i][j]='0';
                
                go(grid,i-1,j);
                go(grid,i+1,j);
                go(grid,i,j-1);
                go(grid,i,j+1);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    go(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};