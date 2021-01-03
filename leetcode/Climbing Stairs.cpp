//https://leetcode.com/problems/climbing-stairs/

//1. 피보나치처럼 재귀방법으로 품
class Solution {
public:
    int climbStairs(int n)
    {
        return go(n, 0, 1);
    }
    int go(int n, int a, int b) 
    {
        if (n == 0) return b;
        return go(n - 1, b, a + b);
    }
};

//2.이건 그냥 O(n)으로 문제 그대로
class Solution {
public:
    int climbStairs(int n)
    {
        int s1 = 1;
        int s2 = 1;
        int ans = 1;
        
        for(int i = 1; i<n; i++)
        {
            ans =s1 + s2;
            s1= s2;
            s2 = ans;
        }
        
        return ans;
    }
};