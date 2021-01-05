class Solution {
public:
    
    bool ckpoint(char c, vector<vector<char>>& board,int row,int col)
    {
           
        for(int i = 0;i < 9;i++)
        {
            if(i != col && board[row][i] == c)
            {
                return false;
            }
        }
     
        for(int i = 0;i < 9;i++)
        {
            if(i != row && board[i][col] == c)
            {
                return false;
            }
        }
        
        return true;
        
    }
    
    
    bool go(vector<vector<char>>& board,int row,int col)
    {
      
        char c = board[row][col];
        
        if(ckpoint(c,  board, row, col) == false)
        {
             return false;
        }
        
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                int x = 3*(row/3); 
                int y = 3*(col/3);
                
                if(x+i == row && y+j == col)
                {
                    continue;
                }
                if(board[x+i][y+j] == c)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i = 0;i < 9;i++)
        {
            for(int j = 0;j < 9;j++)
            {

                if(board[i][j] != '.' && !go(board,i,j))
                {
                    return false;
                }
            }
        }
        return true;
    }
};