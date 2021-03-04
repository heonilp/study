#include <iostream>

using namespace std;
bool isvisit[10];
int map[10];

void go(int index, int start, int n, int m)
{
    if (index == m) {
        for (int i=0; i<m; i++) 
        {
            cout << map[i];
            if (i != m-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=start; i<=n; i++)
    {
        if (isvisit[i]) continue;
        isvisit[i] = true;
        map[index] = i;
        go(index+1, i+1, n, m);
        isvisit[i] = false;
    }
}
int main() 
{
    int n, m;
    cin >> n >> m;
    
    go(0,1,n,m);

    return 0;
}