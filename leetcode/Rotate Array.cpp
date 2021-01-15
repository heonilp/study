class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cell = (int)nums.size();
        k = k % cell;
        if(k==0)
        {
            return;
        }
        
        k = nums.size()-k;
        
        //바꾸는것 로직
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
        
        //rotate을 한번 쓸때마다 이동// N사(net~) 필기시험이었...
            
    }
};