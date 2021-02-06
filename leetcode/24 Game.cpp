//679. 24 Game

class Solution {
public:
    vector<double> helper(double x, double y)
    {
        return { x + y, x - y, y -x, x/y, y/x, x * y};
    }
    
    bool dfs(vector<double> &nums, int n) 
    {
        if (n == 1 && abs(nums[0] - 24) < 0.0001)
            return true;
            
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double x = nums[i];
                double y = nums[j];
                vector<double> result;
                
                result = helper(x, y);
                nums[j] = nums[n - 1];
                for (auto it: result)
                {
                    nums[i] = it;
                    if (dfs(nums, n - 1)) return true;
                }
                nums[i] = x;
                nums[j] = y;
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums)
    {
        vector<double> tmp(nums.begin(), nums.end());
        return dfs(tmp, 4);
    }
};