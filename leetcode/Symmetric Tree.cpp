class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return sol(root->left,root->right);
    }
    bool sol(TreeNode* left,TreeNode* right)
    {
        if(!left&&!right) return true;
        if((!left&&right)||(left&&!right)||(left->val!=right->val)) return false;
        return sol(left->left,right->right)&&sol(left->right,right->left);
    }
};