class Solution {
public:
    
    struct st_item
    {
        int ans;
        int pretime;
        int totaltime;
        int profit;        
    };
    
    int maxProfit(vector<int>& prices) {
        
        struct st_item item;
        item.ans = 0;
        item.profit = 0;  
        item.totaltime =  prices.size();
        
        for(int time =1; time< item.totaltime; time++)
        {
            item.pretime =time-1;
            if(prices[item.pretime] < prices[time])
            {
                item.profit = prices[time] - prices[item.pretime];
                item.ans = item.ans + item.profit;
            }
        } 
        return item.ans;   
    }
};