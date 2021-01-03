//https://leetcode.com/problems/two-sum/


//O(n^2) 풀다가 이건아닌거같아서 map써서 O(n)으로품
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> imap;
        int i =0;
        while(1)
        {    
            auto it = imap.find(target - nums[i]);
            if (it != imap.end()) return vector<int> {i, it->second};  
            imap[nums[i]] = i;
            i++;
        }
    }
};