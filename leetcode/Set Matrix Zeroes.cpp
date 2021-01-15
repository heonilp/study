class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> r(n,-1),c(m,-1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    r[i]=0;
                    c[j]=0;
                }
            }
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(r[i]==0 || c[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        } 
    }
};