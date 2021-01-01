class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        
        for(int i = 0; i< numRows; ++i )
        {
            vector<int> a;
            a.clear();            
            if(i == 0)
            {
                a.push_back(1); 
                ans.push_back(a);
            }
            else if(i ==1)
            {
                a.push_back(1); 
                a.push_back(1); 
                ans.push_back(a);
            }
            else
            {
                a.push_back(1);
                
                for(int j = 0; j <i-1 ; ++j)
                {
                   
                    int putdata = ans[i-1][j]  + ans[i-1][j+1] ;
                    a.push_back(putdata);             
                }
                
                a.push_back(1);  
                
                ans.push_back(a);
                
            }
            
                
        }
        
        return ans;
    }
};