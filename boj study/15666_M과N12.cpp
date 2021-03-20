#include<algorithm>
#include<iostream>
using namespace std;
 
int n, m, num[8], result[8];
 

void go(int count, int start) {

    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int f = -1; 

    for (int i = start; i < n; i++)
    {

        if (f != num[i])
        {
            result[count] = num[i];
            f = num[i];
            go(count + 1, i);
        }
    }
}
 
int main(void) 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
         cin >> num[i];
    }
      
    sort(num, num + n);
 
    go(0, 0);
    return 0;
}
