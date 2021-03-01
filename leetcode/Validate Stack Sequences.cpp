class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int>s;
        int i=0;
        for (int j=0;j<pushed.size();++j)
        {
            s.push(pushed[j]);
          
            while (!s.empty() && s.top() == popped[i])
            {
                s.pop();
                i++;
            }
        }
        
        return s.empty();
    }
};