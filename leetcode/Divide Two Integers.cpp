class Solution {
public:
    int divide(int dividend, int divisor) {
        bool f = false;
        
        unsigned int a = dividend;
        unsigned int b = divisor;
        
        
        if (dividend < 0)
        {
            f = !f;
            a = -a;
        }
        if (divisor < 0)
        {
            f = !f;
            b = -b;
        }
        unsigned int cnt = 0;
        
        while (a >= b)
        {
            long m = b;
            long t = 1;
            while (1)
            {
                if (a < m + m)
                {
                    a -= m;
                    cnt += t;
                    break;
                }
                else 
                {
                    m += m;
                    t += t;
                }
            }
        }
        if (f) return -cnt;
        else if (cnt > INT_MAX)
            return INT_MAX;
        else return cnt;
    }
};