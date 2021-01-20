class Solution 
{
public:
    int mySqrt(int x) 
    {
        if (x == 0 || x == 1) return x; 
        
        unsigned int i = 1;
        unsigned int s = 0;
        for (; s <= x;s=++i*i) {}
        
        return i - 1;
    }
};

// 다시풀기

class Solution {
public:
    int mySqrt(int x) {
        
        long long start = 0;
        long long end = x;
        long long mid =0;
        int ans= 0;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(mid * mid == x) return mid;
            else if(mid * mid < x)
            {
                start = mid + 1; 
                ans = mid;
            }
            else  end = mid-1;
        }
        return ans;
    }
};