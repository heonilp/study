//dfs로 풀기

class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    bool ans = false;
    
    void dfs(vector<vector<char>>& board, string& word, int i, int j, int n)
    {
        //단어 길이와 같다면 넘김
        if(n == word.length()-1) 
        {
            ans = board[i][j];
            return;
        }
        
        board[i][j] = '1';
        
        for(int k=0; k<4; ++k) 
        {    
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(nx<0 || nx>=board.size() || ny<0 || ny>=board[0].size()
               || board[nx][ny] == '1' || board[nx][ny] != word[n+1] )
            {
                continue;
            }
                
            else 
            {
                if(ans)
                {
                    break;
                }
                //성공하면 다음으로 넘김
                dfs(board, word, nx, ny, n+1);
            }
        }
        
        board[i][j] = word[n];
    } 
    
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        
        for(int i=0; i<board.size(); ++i)
        {
            for(int j=0; j<board[0].size(); ++j) 
            {
                
                if(board[i][j] == word[0])
                {
                    dfs(board, word, i, j , 0);
                }
                if(ans)
                {
                     return true;
                }
                   
            }
        }
        
        return false;
    }
};