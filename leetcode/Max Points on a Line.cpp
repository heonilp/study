class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2) return points.size();
        
        int ans = 0;
        
        for(int i = 0; i < points.size(); i++)
        {
            map<long double , int> m;
			
            int cnt = 1;
            long double s;
            int x = 0; 
            int y = 0;
            int maxmax = 0;
            
            for(int j = i+1 ; j < points.size(); j++)
            {
                x = points[i][0] - points[j][0];
                y = points[i][1] - points[j][1];
                
                if(!x && ! y)
                {
                    cnt++;
                    continue;
                }
                                   
                if(x == 0)
                {
                    s = DBL_MAX;
                }
                else
                {
                    s = (long double)(y)/x;
                }
                
                m[s]++;
				
                maxmax = max(maxmax, m[s]);
            }
            
            ans = max(ans, maxmax + cnt);
        }
        
        return ans;
    }
};