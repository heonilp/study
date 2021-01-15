class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        
        int left=0;
        int right=m-1;
        int down=n-1;
        int up=0;
        
        int dir=1;
    
        while(left<=right && up<=down)
        {
            if(dir==1)
            {
                for(int i=left;i<=right;i++) ans.push_back(matrix[up][i]);
                dir=2;
                up++;
            }
            
            else if(dir==2)
            {
                for(int i=up;i<=down;i++) ans.push_back(matrix[i][right]);
                dir=3;
                right--;
            }
            
            else if(dir==3)
            {
                for(int i=right;i>=left;i--) ans.push_back(matrix[down][i]);
                dir=4;
                down--;
            }
            
            else if(dir==4)
            {
                for(int i=down;i>=up;i--) ans.push_back(matrix[i][left]);
                dir=1;
                left++;
            }
        }
        return ans;
        
    }
};