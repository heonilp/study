class Solution {
public:
    bool canJump(vector<int>& nums) {
        int a = nums.size() - 1;
        
        for(int i = a-1; i >=0; i--)
        {
            if(nums[i] + i >= a)
            {
                a = i;
            }
        }
        if(a == 0) return true;
        else return false;
    }
};