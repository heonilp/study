class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int m =200000000;

        for(int i = 0 ; i<(int)prices.size(); i++)
        {
            p = max(p , prices[i] - m);
            m= min(m, prices[i]);    
        }
        return p;
    }
};