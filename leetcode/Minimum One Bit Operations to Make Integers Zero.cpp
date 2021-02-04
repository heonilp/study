//하드문제 어렵...
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = n;
        while(n >>= 1)
            ans ^= n;
        return ans;
    }
};