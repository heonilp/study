//전형적인 BFS 문제, DFS로 다시풀기(시간초과 시간복잡도 100x100이므로 시간초과)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

#define MAX 101
#define DIR 4

int dx[DIR] = { 1, -1 ,0, 0 };
int dy[DIR] = { 0 , 0 , 1, -1 };
int N, M;

int map[MAX][MAX];
int isVist[MAX][MAX] = { 0, };
struct st_xy
{
	int ix;
	int iy;
};

queue <st_xy> que;


//int cnt = 1;

int cnt = 99999999;

void dfs(int x, int y)
{
	if (x == (N - 1) && y == (M - 1))
	{
		cnt = min(cnt, map[x][y]);
		//printf("%d\n", cnt);
		return;
	}

	//isVist[x][y] = 1;

	for (int i = 0; i < DIR; i++)
	{
		int ix = x + dx[i];
		int iy = y + dy[i];

		if (ix >= 0 && iy >= 0 && ix < N && iy < M && map[ix][iy] >= 1 && isVist[ix][iy]==0)
		{

			map[ix][iy] = map[x][y] + 1;
			isVist[ix][iy] = 1;
			
			dfs(ix, iy);	

			map[ix][iy] = map[x][y] - 1;
			isVist[ix][iy] = 0;
		}

	}



}

void bfs(int a, int b)
{
	st_xy input;
	input.ix = a;
	input.iy = b;
	que.push(input);


	while (!que.empty())
	{

		st_xy newnode = que.front();

        que.pop();
        
		for (int i = 0; i < DIR; i++)
		{
			int ix = newnode.ix + dx[i];
			int iy = newnode.iy + dy[i];

			if (ix < 0 || iy < 0 || ix >= N || iy >= M)
			{
				continue;
			}



			if (map[ix][iy] == 0)
			{
				continue;
			}

			else if (map[ix][iy] == 1)
			{
				st_xy now;
				now.ix = ix;
				now.iy = iy;
				que.push(now);

				map[ix][iy] = map[newnode.ix][newnode.iy] + 1;
			}

		}

		


	}


}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	
	bfs(0, 0);

	//dfs(0,0);

	cout << map[N - 1][M - 1]<<"\n";

	//cout << cnt<< "\n";


	return 0;
}