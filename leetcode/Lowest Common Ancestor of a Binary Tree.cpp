class Solution {
public:
    TreeNode* node=NULL;
    
    int go(TreeNode*root,TreeNode* p, TreeNode* q){
        int ans=0;
  
        if (root->left)
        {
            ans+=go(root->left,p,q);
        }
        if(root==p||root==q)
        {
            ans++;
        }
        
        if(root->right)
        {
            ans+=go(root->right,p,q);
        }
        if(ans>=2) 
        {
            node =root;
            return 1;
        }
        if(ans>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        go(root,p,q);
        return  node;
    }
};