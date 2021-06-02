#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <algorithm>

int T, N, M, ans;
int map[11][11];
bool visit[11][11];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

using namespace std;

void go(int x, int y, int sum, bool flag, bool one)
{
	if (x == N - 1 && y == N - 1)
	{
		ans = min(ans, sum);
		
		return;
	}
	if (ans != 1e9 && ans <= sum) return;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i], k = map[nx][ny];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny]) continue;
		
		visit[nx][ny] = 1;
		
		if (map[nx][ny] == 1) go(nx, ny, sum + 1, false, one);
		else if (map[nx][ny] > 1 && !flag) go(nx, ny, sum + k - (sum % k), true, one);
		else if (!map[nx][ny] && !flag && !one) go(nx, ny, sum + M - (sum % M), true, true);

		visit[nx][ny] = 0;
	}
}


int main()
{

	ans = 1e9, visit[0][0] = 1;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);

	go(0, 0, 0, 0, 0);

	printf("%d\n", ans);

	return 0;

}