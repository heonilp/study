class Solution {
public:
    void moveZeroes(vector<int>& nums) {

       int h = 0;
      
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] != 0)
            {
                nums[h++] = nums[i];
            }
        }
       
        for (;h < nums.size(); h++)
        {
            nums[h] = 0;
        }
    }
};