#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 100000
using namespace std;
int n, m, par[MAX_N + 1][21], x, y, visited[MAX_N + 1], d[MAX_N + 1];
vector<vector<int>> vt;
void dfs(int here,int depth) {
    visited[here] = true;
    d[here] = depth;
    for (int there : vt[here]) {
        if (visited[there])
            continue;
        par[there][0] = here;
        dfs(there, depth + 1);
    }
}
void f() {
    for (int j = 1; j < 21; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
int lca(int x, int y) {
    if (d[x] > d[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) 
            y = par[y][i];
    }
    if (x == y)return x;
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}
int main() 
{
  
    scanf("%d", &n);
    vt.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    dfs(1, 0);
    f();
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}