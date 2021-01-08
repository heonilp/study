class Solution 
{
public:
    int mySqrt(int x) 
    {
        if (x == 0 || x == 1) return x; 
        
        unsigned int i = 1;
        unsigned int s = 0 ;
        for (; s <= x;s=++i*i) {}
        
        return i - 1;
    }
};
