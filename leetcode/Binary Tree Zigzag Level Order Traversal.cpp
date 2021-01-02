class Solution {
public:
    void go(map<int,vector<int>> &m, TreeNode* root, int h)
    {
        if(root !=nullptr)
        {
            m[h].push_back(root->val);
            
            go(m,root->left,h+1);
            go(m,root->right,h+1);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        map<int,vector<int>> m;
        
        go(m,root,0);
        
        vector<vector<int>> v;
        int n = m.size();
        
        for(int i=0;i<n;i++)
        {
            if(i%2 != 0)
            {
                reverse(m[i].begin(),m[i].end());
            }
            v.push_back(m[i]);
        }
        return v;        
    }
};
