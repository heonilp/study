1. 복사본 만든 것...

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> v;
        
        
        int cnt = 0;
        
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                cnt++; //0의 개수 세기
            }
            else
            {
                v.push_back(nums[i]);
            }
        }
        
        for(int i = 0; i< cnt; i++)
        {
            v.push_back(0);
        }
        
        
        nums.clear();
        
        nums = v;
        
        
    }
};

2. 복사본없이 한것

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