class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());        
        for(int i = 1; i <(int)nums.size(); i++)
        {   
            if(nums[i-1] == nums[i])
            {
                return nums[i] ;
            }
            
        }     
        return 0; 
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int ans =0; 
        
        for(int i=0; i<nums.size(); i++)
        {
            
            if(nums[abs(nums[i])] < 0)
            {
                ans = abs(nums[i]);
            }
            else
            {
                nums[abs(nums[i])] = nums[abs(nums[i])] * -1;
            }
        }
        
        return ans;
    }
};