class Solution {

private:    
    int ZERO = -1;
    int ONE= -2;
    int n;
    int m;

public:
    
    int go(vector<vector<int>>& a, int i, int j)
    {
        int cnt=0;
        
        for(int newi=i-1; newi<=i+1; newi++)
        {
            for(int newj=j-1; newj<=j+1; newj++)
            {
                if(newi==i && newj==j) continue;
                if(newi<n && newi>=0 && newj<m && newj>=0 &&
                (a[newi][newj]==1 || a[newi][newj]==ZERO))
                {
                     cnt++;
                }
                   
            }
        }
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& a) 
    {
        n=a.size();
        m = a[0].size();
       
        int ns;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ns=go(a,i,j);
                
                if(a[i][j]==1)
                {
                    if(ns<2 || ns>3) a[i][j]=ZERO;
                }
                
                else if(a[i][j]==0)
                {
                    if(ns==3) a[i][j]=ONE;
                }
                
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]==ONE) a[i][j]=1;
                
                else if(a[i][j]==ZERO) a[i][j]=0;
            }
        }
    }
};