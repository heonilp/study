class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        
        sort(nums.begin(),nums.end());
        
        set<vector<int>> s;
        
        int n = nums.size();
        
        for(int i = 0; i < n-2; i++)
        {
            int sum = 0 - nums[i];
            
            int start = i+1;
            int end = n-1;
            
            while(start < end)
            {
                if(nums[start] + nums[end] == sum)
                {
                    vector<int> v {nums[i],nums[start],nums[end]};
                    s.insert(v);
                    start++;
                    end--;
                }
                else if(nums[start] + nums[end] > sum)
                {
                    end--;
                }
                else if(nums[start] + nums[end] < sum)
                {
                    start++;
                }
            }
        }
        
        vector<vector<int>> ans(s.begin(),s.end());
        
         
        return ans;
    }
};