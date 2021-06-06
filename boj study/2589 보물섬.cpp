#include <cstdio>
#include <queue>
using namespace std;
 
int height, width;
char map[51][51];
 
int bfs(int starty, int startx)
{
    int visit[51][51] = { 0, };
    int mx = 0;
    int dy[4] = { -1, 0, 0, 1 };
    int dx[4] = { 0, -1, 1, 0 };
 
    queue<pair<int, int> > que;
    visit[starty][startx] = 1;
    que.push(make_pair(starty, startx));
 
    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
 
        if (visit[y][x] > mx)    mx = visit[y][x];
 
        for (int i = 0; i < 4; i++) {
            int nexty = y + dy[i];
            int nextx = x + dx[i];
 
            if (nexty >= 0 && nexty < height && nextx >= 0 && nextx < width) {
                if (map[nexty][nextx] == 'L' && visit[nexty][nextx] == 0) {
                    que.push(make_pair(nexty, nextx));
                    visit[nexty][nextx] = visit[y][x] + 1;
                }
            }
        }
    }
 
    return mx - 1;
}
 
int solve()
{
    int mx = 0, val;
 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 'L') {
                val = bfs(i, j);
                if (val > mx)    mx = val;
            }
        }
    }
 
    return mx;
}
 
int main()
{
    scanf("%d %d", &height, &width);
 
    for (int i = 0; i < height; i++) {
        scanf("%s", map[i]);
    }
 
    printf("%d\n", solve());
 
    return 0;
}