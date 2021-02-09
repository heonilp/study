class Solution {
public:
    int go(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2, int k){
        if(idx1 >= nums1.size()) return nums2[idx2 + k-1];
        else if(idx2 >= nums2.size()) return nums1[idx1 + k-1];
        else if(k==1) return min(nums1[idx1], nums2[idx2]);
        
        int mid1 = idx1 + k/2 - 1; 
        int mid2 = idx2 + k/2 - 1;
    
        int m1 = mid1>=nums1.size() ? INT_MAX : nums1[mid1];
        int m2 = mid2>=nums2.size() ? INT_MAX : nums2[mid2];
        
        if(m1 < m2)
        {
               return go(nums1, nums2, mid1+1, idx2, k-k/2);
        }
        else
        {
            return go(nums1, nums2, idx1, mid2+1, k-k/2);      
        }
    }

    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size = nums1.size() + nums2.size();
        if(size%2 == 1)
        {
            return go(nums1, nums2, 0, 0, size/2+1); 
        }  

        return (go(nums1, nums2, 0, 0, size/2+1) 
                + go(nums1, nums2, 0, 0, size/2))/2.0;
    }
};