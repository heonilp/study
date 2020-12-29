//1.생각나는데로 막풀이

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans = 0;
        vector<int> v;
        int s = matrix.size();
        for(int i = 0 ; i <s; i++ )
        {
            for(int j = 0; j< s; j++)
            {
                v.push_back(matrix[i][j]);
            }
        }
        
        sort(v.begin(), v.end());
        
        
        for(int i = 0 ; i < (int)v.size(); i++)
        {
            if(i +1 ==k)
            {
                ans = v[i];
            }
        }
          
        return ans;
       
    }
};

//2. 그나마 생각

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int l = matrix[0][0];
        int r = matrix.back().back();
        
        while (l < r) 
        {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            
            for (int i = 0; i < matrix.size(); i++ ) 
            {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (cnt < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};