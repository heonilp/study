#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
int go[20][20];
int map[7];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int main()
{
	int n, m, x, y, l;
	cin >> n >> m >> x >> y >> l;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cin >> go[i][j];
		}
	}
	while (l--)
	{
		int k;
		cin >> k;
		k -= 1;
		int nx, ny;
		nx = x + dx[k];
		ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			// 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 함, 출력도 하면 안됨
			continue;
		}
		if (k == 0) { // right
			int temp = map[1];
			map[1] = map[4];
			map[4] = map[6];
			map[6] = map[3];
			map[3] = temp;
		}
		else if (k == 1) { // left
			int temp = map[1];
			map[1] = map[3];
			map[3] = map[6];
			map[6] = map[4];
			map[4] = temp;
		}
		else if (k == 2) { // up
			int temp = map[1];
			map[1] = map[5];
			map[5] = map[6];
			map[6] = map[2];
			map[2] = temp;
		}
		else { // down
			int temp = map[1];
			map[1] = map[2];
			map[2] = map[6];
			map[6] = map[5];
			map[5] = temp;
		}
		x = nx;
		y = ny;
		if (go[x][y] == 0) {
			// 주사위를 굴렸을 때, 이동한 칸에 써 있는 수가 0이면, 주사위의 바닥면에 써 있는 수가 칸에 복사됨
			go[x][y] = map[6];
		}
		else {
			// 0이 아닌 경우에는 칸에 써 있는 수가 주사위의 바닥면으로 복사되며,
			map[6] = go[x][y];
			// 칸에 써 있는 수는 0이 복사됨
			go[x][y] = 0;
		}
		cout << map[1] << '\n';
	}
	return 0;
}