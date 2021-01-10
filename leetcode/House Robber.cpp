class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0; 
        int b = 0;
        for(int i =0; i<nums.size() ; i++)
        {
            int c = b;
            b = max(b, nums[i] + a);
            a = c;
        }
        return b;
    }
};