class Solution {
public:

    int search(vector<int>& nums, int target) 
    {
        int left=0;
        int right=nums.size()-1;
        
        while(left<=right)
        {
            int m=(left+right)/2;
            if(nums[m]==target)
            {
                return m;
            }
            
            if(nums[m]>=nums[0])
            {
                if(target>=nums[0] && target<nums[m]) right=m-1;
                else left=m+1;
            }
            
            else
            {
                if(target<nums[0] && target>nums[m]) left=m+1;
                else right=m-1;
            }
            
        }
        
        return -1;
    }
};