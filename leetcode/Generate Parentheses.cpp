//-재귀 사용풀이

class Solution {
private:
    vector<string> ans;
public:
    void go(string s,int left,int right, int n)
    {
        if(right == n) 
        {
            ans.push_back(s);
            return;
        }
        if(left == n)
        {
            while(right != n)
            {
                s.push_back(')');
                right++;
            }
            ans.push_back(s);
            return;
        }
        
        if(right + 1 <= left)
        {
            go(s+')',left,right+1,n);
        }
        
        go(s+'(',left+1,right,n);
    }
    
    vector<string> generateParenthesis(int n) 
    {
        int left = 1;
        int right = 0;
        
        string s = "(";
        
        go(s,left,right,n);        
        return ans;
    }
};