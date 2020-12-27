class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size();
        int a =0;
        int b = n-1;
        char t;
        while(b > a)
        {
            t = s[a];
            s[a] = s[b];
            s[b] = t;
            a++;
            b--;
        }
    }
};