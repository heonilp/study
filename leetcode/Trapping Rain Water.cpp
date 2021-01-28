

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int l = 0;
        vector<int> v(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            v[i] = l;
            l= max(height[i], l);
        }
        
        int r = 0;
        
        for(int i = n - 1; i >= 0; --i)
        {
            int h = min(v[i], r);
            
            if(height[i] < h)
            {
                v[i] = h - height[i];
            }
            else
            {
                v[i] = 0;
            }
            
            r = max(height[i], r);
        }
        
        return accumulate(v.begin(), v.end(), 0);
    }
};