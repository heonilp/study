class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        
        //0 <= s.length <= 5 * 104 
        int ck[50001] = {0,};
        //이거 또는 해쉬맵이나 셋으로 풀면될듯싶음
        int ans=0;
        int j=0;
        
        for(int i=0;i<s.size();i++)
        {
            j = max(ck[s[i]],j);
            ans=max(ans,i-j+1);     
            ck[s[i]]=i+1;
        }
        return ans;
    }
};