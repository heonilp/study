class Solution {
public:
    void sortColors(vector<int>& nums) {
        int white =0;
        int red = 0;
        int blue = 0;
        
        for(int i =0 ; i< nums.size(); ++i)
        {
            if(nums[i]  == 0)
            {
                white++;
            }
            else if(nums[i] ==1)
            {
                red++;
            }
            else if(nums[i] ==2)
            {
                blue++;
            }
        }
        
        nums.clear();
        
        
        for(int i = 0; i<white; i++ )
        {
            nums.push_back(0);
        }
        
        for(int i =0; i< red; i++)
        {
            nums.push_back(1);
        }
        
        for(int i = 0; i< blue; i++)
        {
            nums.push_back(2);
        }
        
    }
};