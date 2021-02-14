class TrieNode
{
    public:
    unordered_map<char, TrieNode*> c;
    string word = "";
};

class Trie
{
    public:
    TrieNode *root;
    char e;
    
    Trie()
    {
        root = new TrieNode();
        e = '*';
    }
    
    void insert(string str)
    {
        TrieNode *node = root;
        for(char c : str)
        {
            if(node->c.find(c) == node->c.end())
            {
                node->c[c] = new TrieNode();
            }
            node = node->c[c];
        }
        node->word = str;
        node->c[e] = NULL;
    }
};

class Solution 
{
public:
    void dfs(int i, int j, TrieNode * root, vector<vector<bool>> &vis, 
             vector<vector<char>> &board, set<string> &ans)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || vis[i][j])
        {
            return;
        } 
        char c = board[i][j];
        if(root->c.find(c) == root->c.end())
        {
            return;
        }
        root = root->c[c];
        
        vis[i][j] = true;
        
        if(root->c.find('*') != root->c.end())
        {
            ans.insert(root->word);
        }
        
        dfs(i + 1, j , root, vis, board, ans);
        dfs(i - 1, j , root, vis, board, ans);
        dfs(i, j - 1 , root, vis, board, ans);
        dfs(i, j + 1 , root, vis, board, ans);
        
        vis[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        Trie trie;
        
        for(string w : words)
        {
            trie.insert(w);
        }
        
        vector<string> res;
        set<string> ans;
        
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
               if(!vis[i][j]){
                   dfs(i, j, trie.root, vis, board, ans);
               } 
            }
        }
        
        for(auto it : ans)
        {
            res.push_back(it);
        }
        
        return res;
    }
};