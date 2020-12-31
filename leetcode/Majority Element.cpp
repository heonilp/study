class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        int res=0;
        int hsize = nums.size() / 2;
        sort(nums.begin(), nums.end());
        res= nums[hsize];
        return res;
    }
};