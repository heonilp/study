#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, m;
bool check[8];
int a[8];
vector<int> v;
set<vector<int>> s;

void go(int cnt, int idx) 
{
    if (cnt == m)
    {
        s.insert(v);
        return;
    }
    
    for (int i=idx; i<n; i++) 
    {
        if (!check[i]) 
        {
            check[i] = true;
            v.push_back(a[i]);
            go(cnt+1, i);
            v.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    sort(a, a+n);
    go(0, 0);
    
    for (auto k : s)
    {
        for (auto t : k)
        {
            printf("%d ", t);
        }
        printf("\n");
    }
    return 0;
}