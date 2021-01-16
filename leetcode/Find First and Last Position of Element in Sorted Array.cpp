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