#include<iostream>
using namespace std;
int N;
int num[12];
int hi[4];
int MAX = -2e9;
int MIN = 2e9;
void go(int k,int sum)
{
    if (k == N)
    {
        if (sum > MAX)
            MAX = sum;
 
        if (sum < MIN)
            MIN = sum;
 
        return;
    }
 
    for (int i = 0; i < 4; i++)
    {
        if (hi[i] != 0)
        {
            hi[i] -= 1;
 
            if (i == 0)
                go(k + 1, sum + num[k]);
            else if (i == 1)
                go(k + 1, sum - num[k]);
            else if (i == 2)
                go(k + 1, sum*num[k]);
            else
                go(k + 1, sum / num[k]);
 
            hi[i] += 1;
        }
    }
 
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> hi[i];
 
    go(1,num[0]);
 
    cout << MAX << "\n" << MIN << "\n";
 
    return 0;
}