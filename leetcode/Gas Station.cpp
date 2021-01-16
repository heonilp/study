class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int t=0;
        int s=0;
        int a=0;
        
        for(int i=0;i<gas.size();i++)
        {
            t+=(gas[i]-cost[i]);
            a+=(gas[i]-cost[i]);
            
            if(a<0)
            {
                s=i+1;
                a=0;
            }
        }
        if(t<0) return -1;
        
        return s;
        
    }
};