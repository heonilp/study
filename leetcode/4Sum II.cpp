class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      
        int ans = 0 ;
        
        unordered_map<int,int>v;
        
        for(int i = 0 ; i < A.size() ; i ++ ){
            
            for(int j = 0 ; j < B.size() ; j ++ )
            {
                v[A[i]+B[j]]++;
            }
        }
        for(int i = 0 ; i < C.size() ; i ++ )
        {
            for(int j = 0 ; j < D.size() ; j ++ )
            {
                ans =  ans + v[-C[i]-D[j]];
            }
        }
        return ans;
    }
};