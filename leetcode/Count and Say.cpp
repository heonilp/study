//1단계가 "1" 이라면,
//2단계에서는 1개의 "1"이 있으므로 "11", 
//3단계에서는 2개의 "1"이 있으므로 "21", 
//4단계에서는 1개의 "2"와 1개의 "1"이 있으니 "1211"


class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1) return "1";
        if(n==2) return "11";
        if(n==3) return "21";
        if(n==4) return "1211";
        
        string ans = "1211";
        
        for(int i=5;i<=n;++i)
        {
            ans = ans+"$";
            int cnt = 1;
            string temp;
            for(int go=1; go<ans.size(); ++go)
            {
                if(ans[go] != ans[go-1])
                {
                    temp += cnt +'0';
                    temp += ans[go-1];
                    cnt = 1;
                }
                else
                {
                    cnt++;
                }
            }
            ans = temp;
        }
        return ans;
    }
};