

class Solution {
public:
    
    bool ckpoint(int n)
    {
        int num = sqrt(n);
        int u = num * num;
        if(u == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    int numSquares(int n) 
    {
        if(ckpoint(n) == true)
        {
            return 1;
        }

        int f = n;
        
        while(f % 4 == 0)
        {
            f /= 4;
        }
        
        if(f % 8 == 7)
        {
            return 4; 
        }
            
        
        for(int i = 1; pow(i,2) <= n; i++)
        {
            if(ckpoint(n - pow(i,2)) == true)
            {
                return 2;
            }
        }
            
            
        return 3;
        
    }

};