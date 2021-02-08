class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int numsize = nums.size();
        
        if(numsize == 0) return {-1, -1};
        
        int start = 0;
        
        int end = numsize - 1;
        
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
                
        }
        end++;

        if(end >= numsize || nums[end] != target)
        {
            return {-1, -1};
        }
        
        int temp = end;
        start = end;
        end = numsize - 1;
        
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if(nums[mid] > target)
            {
                 end = mid - 1;
            }
               
            else
            {
                 start = mid + 1;
            }                
        }
        return {temp, start-1};
    }
};
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        
  
        for(int i =0 ; i<(int)nums.size(); i++ )
        {
            if( nums[i] ==target)
            {
                ans.push_back(i);
            }
            
        }
        
        
        if(ans.size() == 0 )
        {
            ans.resize(2);
            ans[0] = -1;
            ans[1] = -1;
            return ans;
        }
        
        int temp1 = ans[0];
        int temp2 = ans[ans.size()-1];
        
        
        ans.resize(2);
        ans[0] = temp1;
        ans[1] = temp2;
        
        
        return ans;
    }
};
*/