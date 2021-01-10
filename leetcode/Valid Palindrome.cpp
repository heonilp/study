class Solution {
public:
    
    string go(string s, int n)
    {
        string temp ="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]>=65 and s[i]<=90)temp += s[i] + 32 ;
            if(s[i]>=97 and s[i]<=122) temp+=s[i];
            if(s[i]>=48 and s[i]<=57) temp += s[i];
        }
        
        return temp;
    }
    
    bool isPalindrome(string s) 
    {
        
        int n = s.size();
        string temp = go(s, n);    
        string rtemp = temp;
        reverse(rtemp.begin (),rtemp.end());    
        return (rtemp==temp);
    }
    
};