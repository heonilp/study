class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        int ans = 0;
        
        for(int x: nums) 
        {
            int i = 0;
            int j = ans;
            
            while(i < j) 
            {
                int mid = i+(j-i) / 2;
                
                if(v[mid] < x)
                {
                    i = mid + 1;
                }
                else 
                {
                    j = mid;
                }
            }
            v[i] = x;
        
            if(i == ans)
            {
                ans++;
            }
        }
        
        return ans;
    }
};