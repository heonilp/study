class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0) return (double)1;
        
        double d = x;
        if(n < 0) d = 1/x;
        
        double mul = d*d;
        double dev = abs(n/2);
        int ifx = abs(n);
        
        if(ifx % 2 == 0)
        {
            return myPow(mul, dev);
        }
        else
        {
            return d*myPow(mul, dev);
        }
    }
};