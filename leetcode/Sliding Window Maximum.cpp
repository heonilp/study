
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> q, ans;
        int m = 0;
        int x = 0;
        for(int i = 0; i<n; i++)
        {
            if(m > 0 && i - q[x] >= k)
            {
                x++;
            }
            //while(m > x && nums[i] >= nums[q.back()]) //구간 최소값
            while(m > x && nums[i] >= nums[q.back()]) //구간 최대값
            {
                q.pop_back();
                m--;
            }
            q.push_back(i);
            m++;
            if(i >= k-1)
            {
                ans.push_back(nums[q[x]]);
            }
        }
        return ans;
    }
};
/*

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        
        deque<int>dq;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            
            while (!dq.empty() && (i - dq.front() >= k))
                dq.pop_front();
            
            // while (!dq.empty() && (nums[i] <= nums[dq.back()])) //최소
             while (!dq.empty() && (nums[i] >= nums[dq.back()]))// 최대
                dq.pop_back();
            
            dq.push_back(i);
            
            if (i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
*/