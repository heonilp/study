class Solution {
public:
int calculate(string s) 
{
        
    stack<int> sk;
        
    char b = '+';
        
    int ans = 0;
        
    long long tmp = 0;
        
    for (long long i = 0; i < s.size(); i++) 
    {
        if (isdigit(s[i]))
            tmp = 10*tmp + s[i]-'0';
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1)
        {
            if (b == '-') sk.push(-tmp);
            else if (b == '+') sk.push(tmp);
            else 
            {
                int num;
                if (b == '*')num = sk.top()*tmp;
                else num = sk.top()/tmp;
                sk.pop();
                sk.push(num);
            } 
            b = s[i];
            tmp = 0;
        }
    }
    while (!sk.empty()) {
        ans =   ans + sk.top();
        sk.pop();
    
    }
    return ans;
}
};