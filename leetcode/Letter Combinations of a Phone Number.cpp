//Letter Combinations of a Phone Number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        
        if (digits.size() == 0)
        {
            return ans;
        }
        
        
        if (digits.size() == 1)
        {
            if (digits[0] == '2') ans = {"a", "b", "c"};
            else if (digits[0] == '3') ans = {"d", "e", "f"};
            else if (digits[0] == '4') ans =  {"g", "h", "i"};
            else if (digits[0] == '5') ans =  {"j", "k", "l"};
            else if (digits[0] == '6')  ans =  {"m", "n", "o"};
            else if (digits[0] == '7') ans =  {"p", "q", "r", "s"};
            else if (digits[0] == '8') ans =  {"t", "u", "v"};
            else if (digits[0] == '9') ans =  {"w", "x", "y", "z"};
            return ans;
        }
        
        //빽트래킹
        vector<string> ver = letterCombinations(digits.substr(1));
            
        string str;
        //계속계속 돌고돌고
        str.push_back(digits[0]);
        
        vector<string> cur = letterCombinations(str);
            
        for (auto& c: cur)
        {
            for (auto& v: ver)
            {
                ans.push_back(c + v);
            }
        }

        return ans;
    }
};