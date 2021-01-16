bool cmp(vector<int> &a1, vector<int> &a2)
{
       return a1[0] < a2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        
        int index = 0;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[index][1] >= intervals[i][0])
            {
                intervals[index][0] = min(intervals[index][0], intervals[i][0]);
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            }
            else
            {
                index++;
                intervals[index] = intervals[i];
            }
        }
        
        intervals.resize(index+1);
        
        return intervals;
    }
};