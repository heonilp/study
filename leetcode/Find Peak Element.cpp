class Solution {
    
public:
    int findPeakElement(vector<int>& a)
    {
        if(a.size() == 1 ) return 0; 
        int n = a.size();
        int l = 0,r = n-1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(a[mid] < a[mid+1]) l = mid+1;
            else  r = mid;
        }
        return l;  
    }      
};