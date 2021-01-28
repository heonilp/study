

class Solution {
public:
     int minnode(TreeNode* root)
     {
        if(root->left && root->right || root->left && !root->right)
        {
            return minnode(root->left);
        } 
        return root->val;
    }
    
    int maxnode(TreeNode* root)
    {
        if(root->left && root->right || !root->left && root->right)
        {
            return maxnode(root->right);
        }
        return root->val;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(root->left)
        { 
            if(maxnode(root->left) >= root->val) return false;
        }
        
        if(root->right)
        {
             if(minnode(root->right) <= root->val) return false;  
        }
        
        return isValidBST(root->left) && isValidBST(root->right);
        
    }
};