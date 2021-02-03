class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (int i : nums) m[i] = false;
        
        int ans = 0;
        
        for (auto [num, ck] : m)
        {
            if (!ck) 
            {
                int lower = num;
                int upper = num;
                while (lower > INT_MIN && m.count(lower - 1))
                {
                    m[lower--] = true;
                }
                
                while (upper < INT_MAX && m.count(upper + 1))
                {
                     m[upper++] = true;
                }      
                ans = max(ans, upper - lower + 1);
            }
        }
        return ans;
    }
};