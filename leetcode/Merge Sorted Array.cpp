//1. O(NlogN) 양아치 인정합니다 ㅎㅎ
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for(int i = m; i< m+n; i++ )
        {
            nums1[i] = nums2[i-m];
        }
        
        sort(nums1.begin(), nums1.end());
    }
};

//2 O(N) //ㅠㅠ다시풀이

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m-1;
        int j = n-1;
        int end = m+n-1;
        while(i >=0 && j>=0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[end] = nums1[i];
                i--;
                end--;
            }
            else
            {
                nums1[end] = nums2[j];
                j--;
                end--;
            }
        }
        
        while(j>=0)
        {
            nums1[end] = nums2[j];
            j--;
            end--;
        }
    }
};