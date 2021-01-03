//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int v = nums[0];
        for (int i = 1; i < nums.size(); ++i) 
        {
            v = max(nums[i], v+nums[i]);
            ans = max(v, ans);
        }
        return ans;
    }
};