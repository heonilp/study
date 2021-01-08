


class Solution {
public:
    int strStr(string haystack, string needle)
    {
      
        int n = haystack.size();
        int m = needle.size();
        if(m>n) return -1;
        
        int l =n-m+1;
        int j = 0;
        
        for(int i=0; i<l; i++)
        {
            j = 0;
         
            for(j=0; j<m; ++j)
            {
                if(haystack[i+j]!=needle[j]) break;
            }
            
            if(j==m) return i;
        }
        return -1;
    }
};