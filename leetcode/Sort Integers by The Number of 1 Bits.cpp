
class Solution {
public:
    static int bitcnt(int num)
    {
        int res =0;
        while(num)
        {
            num &=(num-1);
            res++;
        }
        return res;
    }

    static bool compare(int &a, int &b)
    {
        if(bitcnt(a) == bitcnt(b))
        {
            return a > b ? false : true;
        }
        return bitcnt(a) > bitcnt(b) ?  false : true;
    }

    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};