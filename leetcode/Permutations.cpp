//46. Permutations
1. 백트래킹 방법

class Solution {
public:
    
    void go(vector<vector<int>> &v, vector<int> &nums, int cnt, int n)
    {
        if (cnt==n)
        {
            v.push_back(nums);
        }
        else
        {
            for(int i=cnt;i<=n;i++)
            {
                int tmp = nums[cnt];
                nums[cnt]=nums[i];
                nums[i]=tmp;
                
                go(v, nums,cnt+1,n);
                
                tmp = nums[cnt];
                nums[cnt]=nums[i];
                nums[i]=tmp;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums)
    {
        
        vector<vector<int>> v;
        
        go(v, nums,0,nums.size()-1);
        return v;
        
    }
};

2. 넥스트퍼뮤 방법


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> v; //넥스트 퍼뮤를 위해서 꼭해줘야함(특성)
        sort(nums.begin(), nums.end());
        do {
            v.push_back(nums);
            
        } while(next_permutation(nums.begin(), nums.end()));
        return v;
    }
};