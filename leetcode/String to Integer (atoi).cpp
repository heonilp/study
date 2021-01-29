class Solution {
public:
    int myAtoi(string s) 
    {
        
        int n=s.length();
        int sign=1;
        int i=0;
        long long ans=0;
        while(i<n)
        {
            if(s[i]==' ')i++;
            else break;
        }       
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
        {
            sign=1;
            i++;
        }
        else if(s[i]<'0'&&s[i]>'9')return -1;
        while(i<n&&s[i]>='0'&&s[i]<='9')
        {
            if(ans>INT_MAX)break;
            
            ans=ans*10+(s[i]-'0');
            i++;
        }
        if(ans>INT_MAX)return sign==1?INT_MAX:INT_MIN;
        int res = ans*sign;
        return res;
    }
};