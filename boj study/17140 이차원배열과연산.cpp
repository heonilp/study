#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;

int r, c, k, n=3, m=3;
int cnt[101], a[101][101];

void solve() {
    for (int t=0; t<101; t++) {
        if (a[r][c] == k) {
            cout <<t<<"\n";
            return;
        }
        if (n >= m) {
            for (int i=1; i<=n; i++) {
                priority_queue<pair<int, int>> pq;
                memset(cnt, 0, sizeof(cnt));
                for (int j=1; j<=m; j++) {
                    if (a[i][j]) {
                        cnt[a[i][j]] += 1;
                        a[i][j] = 0;
                    }
                }
                for (int j=1; j<=100; j++) {
                    if (cnt[j]) pq.push(make_pair(-cnt[j], -j));
                }
                int len = pq.size()*2;
                m = max(m, len);
                for (int j=1; j<=len; j+=2) {
                    a[i][j] = -pq.top().second;
                    a[i][j+1] = -pq.top().first;
                    pq.pop();
                }
            }
        } else {
            for (int i=1; i<=m; i++) {
                priority_queue<pair<int, int>> pq;
                memset(cnt, 0, sizeof(cnt));
                for (int j=1; j<=n; j++) {
                    if (a[j][i]) {
                        cnt[a[j][i]] += 1;
                        a[j][i] = 0;
                    }
                }
                for (int j=1; j<=100; j++) {
                    if (cnt[j]) pq.push(make_pair(-cnt[j], -j));
                }
                int len = pq.size()*2;
                n = max(n, len);
                for (int j=1; j<=len; j+=2) {
                    a[j][i] = -pq.top().second;
                    a[j+1][i] = -pq.top().first;
                    pq.pop();
                }
            }
        }
        
    }
    cout << "-1" << "\n";
}

int main() 
{
    scanf("%d %d %d", &r, &c, &k);
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    solve();
    return 0;
}