//문제 : 0이 있을떄 가로 세로 다 0만드는거

// 1. 공간 활용 x, 이건 아이디어만 보면될듯

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> r(n,-1),c(m,-1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0) //r 0또는 c 0이나 있으면 메트릭에 0넣는거
                {
                    r[i]=0;
                    c[j]=0;
                }
            }
        }
        
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(r[i]==0 || c[j]==0) //r 0또는 c 0이나 있으면 메트릭에 0넣는거
                {
                    matrix[i][j]=0;
                }
            }
        } 
    }
};

//2. 공간 활용, matrix 변수로 다 컨트롤해야한다.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int ir = matrix.size();
      int ic = matrix[0].size();
       //(r, 0)에 0이 있는지 확인 
      bool f = false;
        
      for(int r = 0; r < ir; ++r)
      {
          if(matrix[r][0] == 0) 
                
            f = true; 
          }
          
          for(int c = 1; c < ic; ++c) 
          {
            // c에 0으로 넣고
            if(matrix[r][c] == 0) 
            {
              matrix[r][0] = 0;
              matrix[0][c] = 0;
            }
          }
      }
        
      for(int r = 1; r < ir; r++) 
      {
        for(int c = 1; c < ic; c++) 
        {
           //0인 것 있으면 쭈욱 0으로 채운다.
          if(matrix[r][0] == 0 || matrix[0][c] == 0)
          {
            matrix[r][c] = 0;
          }
        }
      }
       //(0,0) 에 0이있으면 (c,0) 쭈욱 채운다. 
       if(matrix[0][0] == 0) 
       {
         for(int c = 0; c < ic; ++c)
         {
           matrix[0][c] = 0;
          }
       }
      //(r, 0)에 0이 있는지 확인해서 쭈욱 0으로 넣기
      if(f) 
      {
        for(int r = 0; r < ir; ++r) 
        {
           matrix[r][0] = 0;
        }
      }
    
  }
};