class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    
    int dy[4] = {1,-1,0,0};
    
    bool f(int i ,int j, int m ,int n) 
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    
    bool ot(int i,int j,int m ,int n)
    {
        return (i==0 || i==m-1 || j==0 || j==n-1);
    }
    
    
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        if(!m) return;
        int n = board[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(ot(i,j,m,n) && board[i][j]=='O') 
                {
                    board[i][j] = '#' ;
                    
                    q.push(make_pair(i,j));
                }
            }
        }        
        while(!q.empty()) 
        {
            pair<int,int> curr = q.front();
            
            q.pop();
            
            int cx = curr.first;
            int cy = curr.second;
            
            for(int i=0;i<4;i++) 
            {
                int x = cx+dx[i];
                int y = cy+dy[i];
                
                
                if(f(x,y,m,n) && !ot(x,y,m,n) && board[x][y]=='O') 
                {
                    board[x][y] = '#';  
                    
                    q.push(make_pair(x,y));
                }
            }
        }
      
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};