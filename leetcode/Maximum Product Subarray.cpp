class Solution {
public:
    int maxProduct(vector<int>& a)
    {
        int ans = INT_MIN ,mn =1,mx=1,i=0;
        
        for(i=0;i<a.size();i++)
        {
            if(a[i]==0)
            {
                mx=1,mn=1;
                ans = max(ans,a[i]);
            }
            else if(a[i]>0)
            {
                mx = mx*a[i] ;
                
                mn = min(a[i] , mn*a[i]) ;
                
                ans = max(mx,ans);
            }
            else
            {
                int m_x=mx;
                
                mx = max(1 , mn*a[i]) ;
                
                if(mn <0)
                    ans=max(mx,ans);
                else
                    ans = max(mn*a[i],ans);
                
                
                mn = m_x*a[i];
    
            }
        
            
        }
        return ans ;
    }
};