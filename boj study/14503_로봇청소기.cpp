#include <iostream>
using namespace std;
 
#define SIZE 51 
int map[SIZE][SIZE];
int N, M;
int startX, startY, startDir;
int dx[4] = { -1,0,1,0 }; // 북 동 남 서 
int dy[4] = { 0,1,0,-1 };
int x, y, nx, ny, dir;
int ans, cnt;
int index;
 
void Init() {
    cin >> N >> M;
    cin >> startX >> startY >> startDir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %d",&map[i][j]);
        }
    }
}
 
void dfs() {
 
    x = startX;
    y = startY;
    dir = startDir;
    ans = 1;

    while (1) 
    {
        map[x][y] = 2; // 현재 자리를 청소합니다.
        dir = (dir - 1 + 4) % 4;
        cnt++;
 
        nx = x + dx[dir];
        ny = y + dy[dir];
        
        if (nx >= 0 && ny >= 0 && nx < N && ny < M) { // 맵 안에 들면서,
            if (map[nx][ny] == 0) { // 청소할 공간이 있다면,
                ans++;
                x = nx;
                y = ny;
                cnt = 0;
                continue;
            }
            else if (map[nx][ny] != 0) { // 청소할 공간이 없다면,
                // 4바퀴를 돌았다면, 후진
                if (cnt >= 4) {
                    if (dir == 0) {
                        nx = x + dx[2];
                        ny = y + dy[2];
                    }
                    else if (dir == 1) {
                        nx = x + dx[3];
                        ny = y + dy[3];
                    }
                    else if (dir == 2) {
                        nx = x + dx[0];
                        ny = y + dy[0];
                    }
                    else {
                        nx = x + dx[1];
                        ny = y + dy[1];
                    }
 
                    // 후진을 할 곳이 벽이거나, 맵 바깥이면, 중단
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 1) {
                        break;
                    }
                    else { // 후진 할 수 있으면, 합니다.
                        x = nx;
                        y = ny;
                        cnt = 0; // turn 횟수도 리셋
                    }
                }
            }
        }
    }
}
 
int main()
{
    Init();
    dfs();
    printf("%d\n",ans);
    return 0;
}
