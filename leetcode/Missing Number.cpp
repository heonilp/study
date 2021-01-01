class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int ans = nums.size();
        
        for(int i= 0 ; i < static_cast<int>(nums.size()); ++i)
        {
            ans ^=i^nums[i];
        }
               
        return ans;
    }
};