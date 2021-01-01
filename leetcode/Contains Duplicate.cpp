class Solution {
public:
    bool containsDuplicate(vector<int>& nums){
        unordered_set<int>s;
        bool flag=false;
        
        for(int i:nums)
        {
            if(s.find(i)!=s.end())
            {
                flag=true;
                break;
            }
            s.insert(i);
        }
        
        return flag;
    }
};