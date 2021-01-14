class Solution {
    
public:
    int number;
    int cnt;
    
    int kthSmallest(TreeNode * root, int k) 
    {
        cnt = k;
        inorder(root);
        return number;
    }
    
    void inorder(TreeNode *node) 
    {
        if (node->left != nullptr) 
        {
            inorder(node->left);
        }
        cnt--;
        
        if (cnt == 0) 
        {
            number = node->val;
            return;
        }
        
        if (node->right != nullptr)
        {
            inorder(node->right);
        }
    }
};