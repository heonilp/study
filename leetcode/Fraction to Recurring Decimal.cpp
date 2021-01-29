
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return "0";
        
        if(numerator == 0) return "0";
        
        int nt = abs(numerator);
        int dt = abs(denominator);
        
        string ans = "";
        long long multi = (long long)numerator * (long long)denominator;
        
        if(multi < 0) ans.insert(0, "-");
   
        long long r = nt % dt;
        long long  s = nt / dt;

        
        map<int, int> m;
        
        if(r == 0) 
        {
            ans += to_string(s);
            return ans;
        }
        else ans += to_string(s) + "."; 
        
        int i = ans.length();
        
        while(r != 0)
        {
            s = (r * 10) / dt;
            
            if(m.count(r) == 0)m[r] = i++;
            else 
            {
                ans.insert(m[r], "(");
                ans += ")";
                break;
            }
            ans += to_string(s);
            
            r = (r * 10) % dt;
        }

        return ans;
    }
}