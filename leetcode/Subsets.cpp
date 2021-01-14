//떠오르는 방법이 재귀/ 백트래킹 밖에없다... 

class Solution {
public:
    void subsets(vector<int> &nums, int i, vector<int> & cur, 
                vector<vector<int>>& ans) {
        ans.push_back(cur);		
        for (int j = i; j < nums.size(); j++) 
        {
            cur.push_back(nums[j]);
            subsets(nums, j + 1, cur, ans);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        subsets(nums, 0, cur, ans);
        return ans;
    }
};