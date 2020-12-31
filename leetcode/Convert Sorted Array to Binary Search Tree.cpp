class Solution {
public:
    
    void go(vector<int>& nums, TreeNode* node, int left ,int right)
    {
		int mid = (left + right) / 2;
		node->val = nums[mid];

		if (left <= mid - 1)
        {                      
            go(nums, node->left = new TreeNode(NULL),left, mid - 1); 
        }
		if (right >= mid + 1)     
        {       
            go(nums, node->right = new TreeNode(NULL),mid + 1, right); 
        }
	}
    
    
	TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
		if (nums.size() == 0) return NULL;

		TreeNode* res = new TreeNode(NULL);        
        int left = 0; 
        int right = nums.size() - 1;
		go(nums, res, left, right);
    
		return res;
	}

};