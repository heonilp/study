class Solution {
public:
    bool isMatch(string s, string p) {

        int i = 0;
        int j = 0;
        int is = -1;
        int ip = -1;
        int n = s.size();
        int m = p.size();

        while (i < n)
        {
            if( j < m && s[i] == p[j])
            {
                i++;
                j++;
            }
            else if(j < m && p[j] == '.')
            {
                i++;
                j++;
            } 
            else if(j < m && p[j] == '*')
            {
                is = i;
                ip = j;
                j++;
            }
            else if(ip != -1)
            {
                j = ip + 1;
                i = is + 1;
                is++;
            }
            else
            {
                return false;
            }
        }

        while(j < m && p[j] == '*')
        {
            j++;
        }

        if(j == m)
        {
            return true;
        }

        return false;
    }
};
