#include <iostream>
#include <deque>
using namespace std;
 
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int N;
        cin >> N;
 
        deque<int> dq;
        for (int i = 1; i <= N; i++)
                 dq.push_back(i);
 
        while (dq.size() != 1)
        {
                 dq.pop_front();
                 dq.push_back(dq.front());
                 dq.pop_front();
        }
 
        cout << dq.front() << "\n";
        return 0;
}
