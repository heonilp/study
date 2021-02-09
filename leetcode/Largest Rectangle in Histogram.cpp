
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int>s;
        int ans = INT_MIN;
        
        heights.push_back(-1);
        int h = heights.size();
        
        for(int i = 0; i < h; i++) 
        {
            while(!s.empty() && heights[s.top()] > heights[i]) 
            {
                int top = s.top();
                s.pop();
                if(s.empty())  ans = max(ans, i * heights[top]);
                
                else ans = max(ans, heights[top]*(i-s.top()-1));
            }
            s.push(i);
        }
        return ans;
    }
};