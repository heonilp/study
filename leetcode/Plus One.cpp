class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int iend = digits.size()-1;
        while(1)
        {
            if(iend == 0 && digits[iend] == 9)
            {
                digits[iend] = 1;
                digits.push_back(0);
                return digits;
            }
            if(digits[iend] == 9)
            {
                digits[iend] = 0;
                iend--;
            }
            else
            {
                digits[iend]++;
                return digits ;
            }
        }
        return digits;
    }
};