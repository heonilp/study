문제에 2가지 조건이 있습니다. 그래서 스택을 이용해서 풀었습니다.

1 조건
//Given the root of a binary tree, return the inorder traversal
// of its nodes' values.

2 조건
//Follow up:
//Recursive solution is trivial, could you do it iteratively?

class Solution {
public:
 vector<int> inorderTraversal(TreeNode* root)
 {
        vector<int> ans; //답으로 넘길 벡터선언
        if(root ==nullptr)
        {
            return ans; //root에 []이면 그냥 빈 벡터 넘김
        }

        stack<TreeNode*> s; //TreeNode에 대한 스택 선언
        while(!s.empty()||root)
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            
            root = s.top(); 
            s.pop(); 
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
        
    }
};