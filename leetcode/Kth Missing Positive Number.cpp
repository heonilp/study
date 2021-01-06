

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k)
        {
             return k;
        }
           
        int n = arr.size();
        int u = n+k;
        
        if(arr[n-1] < u)
        {
            return u;
        }
        
        int left = 0;
        int right = n-1;
        
        while(left < right)
        {
            int mid = (left+right)/2;
            int tmp = arr[mid]-mid-1;
            if(tmp < k)
            {
                left = mid+1;
            }
                
            else
            {
                right = mid;
            }
                
        }
        
        int ans = k+left;
        return ans;
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0, e = arr.size();
        if(arr[0] > k) return k;
        while(s<e){
            int m = (s+e)/2;
            if(arr[m] < m+k+1){
                s = m+1;
            }
            else e= m;
        }
        return e+k;
    }
};

