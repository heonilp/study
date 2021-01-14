//1. unordered_map과 sort 사용해서 O(NlogN)

class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<pair<int,int>>v;
    unordered_map<int,int> m;
    int temp = k;
    vector<int>ans;
    int n= (int)nums.size();
    
    for(int i = 0 ; i< n; i++)
    {
        m[nums[i]]++;
    }
    
    
    for(auto i:m)
    {
        v.push_back({i.second,i.first});
    }
    
    sort(v.begin(),v.end(),greater());
    

    for(auto i:v)
    {
        ans.push_back(i.second);
        
        temp--;
        
        if(temp == 0)
        {
            break;
        }
    }
        return ans;
    }
};

//2.priority_queue 사용해서 다시 풀이

struct st_item
{
    int m_n;
    int m_cnt;
    
    st_item(int n, int cnt) : m_n(n), m_cnt(cnt)
    {
        
    }
    
    bool operator > (const st_item &r) const 
    {
        return this->m_cnt > r.m_cnt;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        int n= (int)nums.size();
        priority_queue<st_item, vector<st_item>, greater<st_item>> pq;
        
        for(int i = 0 ; i< n; i++)
        {
            m[nums[i]]++;
        }
                
        
        for(auto itr = m.begin(); itr != m.end(); itr++) 
        {
            pq.push(st_item(itr->first, itr->second));    
        }
        while(pq.size() > k)
        {
            pq.pop();
        }
        
        vector<int> res;
        
        while(!pq.empty())
        {
            res.push_back(pq.top().m_n);
            pq.pop();
        }
        return res;
    }   
}