
// 98. Validate Binary Search Tree
Given the root of a binary tree, determine
if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

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


//벡터로 쉬운풀이

이진 탐색 트리(BST: binary search tree) 의 특징
각 노드에 값이 있다.
값들은 전순서가 있다.(#전순서란 임의의 두 원소를 비교할 수 있는, 부분 순서 집합다)
노드의 왼쪽 서브트리에는 그 노드의 값보다 작은 값들을 지닌 노드들로 이루어져 있다.
노드의 오른쪽 서브트리에는 그 노드의 값과 같거나 큰 값들을 지닌 노드들로 이루어져 있다.
좌우 하위 트리는 각각이 다시 이진 탐색 트리여야 한다.
이렇게 루트키로부터 크게 두 카테괴로 분류된 구조덕분에 빠른 검색과 아이템들의 추가 제거가 특징이다.
이러한 특징덕에 아이템의 동적 세트로써 혹은 키값으로 아이템 검색이 가능한 데이트 테이블의 구조로 활용되어진다.


- BST inorder 중위순회를 하니까 left < root <right 순서로 크기값이 됨. 

class Solution {
public:
    vector<int> vec;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]<=vec[i-1])  return false;
        }
        return true;
    }
    void inorder(TreeNode* root)
    {
        if(root == nullptr) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
};




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