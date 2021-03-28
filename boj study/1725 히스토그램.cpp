//예전에 유명 반도체 회사에서 나온 문제이다..
//간단히 스택으로 푸는 것이었는데 몰라서 완전탐색하다가 터진문제이다.
//늘 복습할것.

#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int h[100001];
stack<int> st;

int main() 
{
    int ans= 0;
    int n = 0;
    int top = 0;
  
    cin >> n;
    for(int i =0;i<n;i++)
    {
        cin >> h[i];
    }
    for(int i = 0; i <= n; i++)
    {
        while(!st.empty() && h[st.top()] > h[i]) 
        {
            int temp = 0; 
            top = st.top();
            st.pop();
            
            if(st.empty())
            {
                temp = i;
            }
            else
            {
                temp = i - st.top() - 1;
            }
            ans = max(ans, h[top] * temp);
        }
        st.push(i);
    }

    
    cout << ans <<'\n';

    return 0;
}