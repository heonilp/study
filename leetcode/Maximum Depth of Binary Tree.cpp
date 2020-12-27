//Maximum Depth of Binary Tree


class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        
        int depth = 0;
        int a = 0;
        int b = 0;
        if(root == NULL)
        {
            depth = 0;
            return depth;
        }
        else if(root->left == NULL && root->right == NULL)
        {
            depth++;
            return depth;
        }
        else
        {
            
            a= maxDepth(root->left);
            b= maxDepth(root->right);
            depth++;
            depth =  depth + max(a,b);
            return depth;
        }
    }
    
};