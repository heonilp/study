#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>


using namespace std;


struct st_XY
{
	int y;
	int x;
	int cnt;
};

char str[1001][1001];
int visit[1001][1001];
int n, m;
queue<st_XY> q; //불의큐
int jx, jy;

void F_bfs()
{
	// 불이 번지는 위치에 걸린 시간을 기입.
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;

		q.pop();

		if (visit[y][x])
			continue;

		visit[y][x] = cnt;

		if (x - 1 >= 1 && !visit[y][x - 1] && (str[y][x - 1] == '.' || str[y][x - 1] == 'J'))
			q.push(st_XY{ y, x - 1, cnt + 1 });

		if (x + 1 <= m && !visit[y][x + 1] && (str[y][x + 1] == '.' || str[y][x + 1] == 'J'))
			q.push(st_XY{ y, x + 1, cnt + 1 });


		if (y - 1 >= 1 && !visit[y - 1][x] && (str[y - 1][x] == '.' || str[y - 1][x] == 'J'))
			q.push(st_XY{ y - 1, x, cnt + 1 });

		if (y + 1 <= n && !visit[y + 1][x] && (str[y + 1][x] == '.' || str[y + 1][x] == 'J'))
			q.push(st_XY{ y + 1, x, cnt + 1 });


	}

	q.push(st_XY{ jy,jx,1 });

}

void J_bfs()
{

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;

		q.pop();

		if (str[y + 1][x] == 'X' || str[y - 1][x] == 'X' || str[y][x - 1] == 'X' || str[y][x + 1] == 'X')
		{
			printf("%d\n", cnt);
			return;
		}

		if (visit[y][x] <= cnt && visit[y][x] != 0)
		{
			continue;
		}

		visit[y][x] = -2;

		//네방향
		if (y - 1 >= 1 && (visit[y - 1][x] > cnt + 1 || visit[y - 1][x] == 0))
			q.push(st_XY{ y - 1, x, cnt + 1 });

		if (y + 1 <= n && (visit[y + 1][x] > cnt + 1 || visit[y + 1][x] == 0))
			q.push(st_XY{ y + 1, x, cnt + 1 });

		if (x - 1 >= 1 && (visit[y][x - 1] > cnt + 1 || visit[y][x - 1] == 0))
			q.push(st_XY{ y, x - 1, cnt + 1 });

		if (x + 1 <= m && (visit[y][x + 1] > cnt + 1 || visit[y][x + 1] == 0))
			q.push(st_XY{ y, x + 1, cnt + 1 });
	}


	//없는 경우
	printf("IMPOSSIBLE");


}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			str[i][j] = 'X';
		}
			
	}
		
	getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%c", &str[i][j]);

		getchar();
	}

	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] == '#') //#인부분을 1로 체크
				visit[i][j] = -1;

			else if (str[i][j] == 'J') //J의 좌표 넣기
			{
				jx = j;
				jy = i;
			}
			else if (str[i][j] == 'F') //불의 좌표를 넣기
				q.push(st_XY{ i,j,1 });
		}
	}

	
	F_bfs();
	J_bfs();

	
	

	return 0;


}