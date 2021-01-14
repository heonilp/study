//양아치 권법 O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.size() == 1) return 0;
        int ans = 0;
        int num_size = (int)nums.size(); 
        
        int m = nums[0];
        
        for(int i = 0; i<num_size; i++ )
        {
           
            m = max( nums[i], m);    
        }
        
        for(int i = 0; i < num_size; i++)
        {
            if(m == nums[i])
            {
                ans = i;
                break;
            }
        }
        
        return ans;
        
    }
};

// 이진검색으로 O(log N)
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