/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = -1000;
    int go(TreeNode* root) 
    {
        if(!root) return 0;
    
        int left = go(root->left);   
        int right = go(root->right);  
 
        if(left < 0) left = 0;
        if(right < 0) right = 0;
    
        int sum =0;
        sum = left + right + root->val;
        ans = max(ans, sum);
    
        return max(left, right) + root->val;
    }
    
    
    int maxPathSum(TreeNode* root) 
    {
        go(root); 
        return ans; 
    }
};