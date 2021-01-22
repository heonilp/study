
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
        int c = arr[0];
        
        for(int i = 1; i < arr.size(); i ++)
        {
            if(arr[i] >= c)
            {
                s.push(c);
                c = arr[i];
            }
            else
            {
                while(!s.empty() && s.top() > arr[i]) s.pop();
            }
        }
        return s.size() + 1;
    }
};


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> srt = arr;
        sort(srt.begin(), srt.end());
        unordered_multiset<int> _set;
        int ans = 0, last = 0;
        for (int x: srt){
            _set.insert(x);
            while (last < arr.size() && _set.count(arr[last]))
                _set.erase(_set.find(arr[last++]));
            if (_set.size() == 0) ans++;
        }
        return ans;
    }
};