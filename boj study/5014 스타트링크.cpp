#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 1000010
int F, S, G, U, D;
int dist[MAXN];
bool check[MAXN];
 
int main() {
    scanf(" %d %d %d %d %d", &F, &S, &G, &U, &D);
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    check[S] = true;
 
    while (!q.empty()) {
        int here = q.front();
        q.pop();
 
        int next = here + U;
        if (next <= F && !check[next]) {
            check[next] = true;
            dist[next] = dist[here] + 1;
            q.push(next);
        }
        
        next = here - D;
        if (1 <= next && !check[next]) {
            check[next] = true;
            dist[next] = dist[here] + 1;
            q.push(next);
        }
    }
    if (check[G]) printf("%d\n", dist[G]);
    else puts("use the stairs");
}
