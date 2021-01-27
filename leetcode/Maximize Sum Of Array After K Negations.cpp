
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int,vector<int>,greater<int> > pq;
        
        for (auto i: A) 
        {
            pq.push(i);
        }
        int t = K;
        while (t != 0)
        {
            int s = pq.top();
            pq.pop();
            pq.push(s*-1);
            t--;
        }
        int ans = 0;
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};