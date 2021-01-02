//재귀 방식으로 풀이

class Solution {
public:
    int cnt =0;
    
    TreeNode* go(vector<int>& pre, vector<int>& in, int s, int e)
    {
        if(s > e)
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(pre[cnt]);
        
        cnt++;
        
        if(s == e)
        {
            return node;
        }
        
        int ncnt= 0;
        
        for(int n=s; n<=e; n++)
        {
            if(node->val == in[n])
            {
                ncnt = n;
                break;
            }
        }
        node->left = go(pre, in, s, ncnt-1);
        
        node->right = go(pre, in, ncnt+1, e);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        TreeNode* node = go(preorder,inorder,0,preorder.size()-1);
        
        return node;
    }
};