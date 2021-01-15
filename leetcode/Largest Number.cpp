 //10의 자리수이므로 다음과 같이 뒤집어서 생각
bool compare(int a,int b)
{
        
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        return ((s1+s2)>(s2+s1));
}

class Solution {
public:
  
    string largestNumber(vector<int>& vec)
    {
        int n = vec.size();
        
        if(n==0) return "";
        
        sort(vec.begin(),vec.end(),compare);
        
        
        int cnt=0;
        
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            if(vec[i]==0)
            {
                cnt++;
            }
            ans+=to_string(vec[i]);
            
        }
        
        if(vec.size() == cnt)
        {
            return "0";
        }
        else
        {
            return ans;
        }
    }
};