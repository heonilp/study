#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m;
int a[8];
int ck[8];
int tmp[8];

set<vector<int>> ans;

void go(int dth)
{
    if (dth == m)
    {
        vector<int> v;
        for (int i = 0; i < m; i++)
        {
            v.push_back(tmp[i]);
        }
        
        ans.insert(v);
        v.clear();
        return;
    }

    for (int i = 0; i < n; i++)
    {    
        tmp[dth] = a[i];
        go(dth + 1);      
    }
}

int main()
 {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    go(0);
 
    for (auto a : ans)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
