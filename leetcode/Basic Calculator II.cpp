//스택이용
#define ll long long
class Solution {
public:
    int calculate(string s) 
    {
        
        stack<int> v;
        
        char c = '+';
        
        int ans = 0;
        ll tmp = 0; // long long 형으로 하지않으면 터짐
        
        for (ll i = 0; i < s.size(); i++) 
        {
            if (isdigit(s[i])) tmp = 10*tmp + s[i]-'0';
            
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1)
            {
    
                if (c == '-') v.push(-tmp);
                else if(c == '+') v.push(tmp);
                else 
                {
                    ll num = 0;
                
                    if (c == '*') num = v.top()*tmp;
                    else  num = v.top()/tmp;
                    v.pop();
                    v.push(num);
                } 
            
                c = s[i];
                tmp = 0;
            }
        }
        
        while (!v.empty()) 
        {
            ans += v.top();
            v.pop();
        }
        return ans;
    }
};