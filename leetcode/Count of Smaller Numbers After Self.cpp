
class Solution {
public:
    void update(vector<int> &t, int n, int i, int d)
    {
        for(;i<=n; i+=(i & (-i)))
        {
            t[i]+=d;
        }
    }

    int get(vector<int> &t, int n, int i)
    {
        int sum=0;
        for(;i>0; i-=(i & (-i)))
        {
            sum+=t[i];
        }
        return sum;
    }


    void go(vector<int> &arr)
    {
        int n=arr.size();
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<n;i++)
        {

            arr[i]= lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin()+1;
        }
    }

   
    vector<int> countSmaller(vector<int>& arr) 
    {
        go(arr);
        int n=arr.size();
        vector<int> t(n+1);
        vector<int> ans(n);
    
    
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=get(t,n,arr[i]-1);
            update(t, n,arr[i],1);
        }
        
        return ans;
    }
};