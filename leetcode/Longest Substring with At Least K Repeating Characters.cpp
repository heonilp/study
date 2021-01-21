class Solution {
public:
    int go(string &s, int k,int start,int end)
    {
	    int m[500]={0,};
        
	    for(int i=start;i<end;i++)
	    {
	    	m[s[i]]++;
    	}
        
	    for(int i=start;i<end;i++)
	    {
	    	if(m[s[i]]<k) return max(go(s,k,start,i),go(s,k,i+1,end));
    	}
        
	    return end-start;
    }
    
    int longestSubstring(string s, int k) {
	    return go(s,k,0,s.length());
    
    }
};