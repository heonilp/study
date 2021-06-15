#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
using namespace std;

int R = 0;
int C = 0;
char map[21][21];

bool isVisited[100];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt = 0;

void dfs(int depth, int x, int y)
{
	int ix = 0;
	int iy = 0;

	isVisited[map[x][y]] = 1;

	if (cnt > 25)
	{
		return;
	}

	if (cnt < depth)
	{
		cnt = depth;
	}



	//네 방향 검토
	for (int i = 0; i< 4; i++)
	{
		ix = x + dx[i];
		iy = y + dy[i];

		if (ix >= 0 && ix<R && iy >= 0 && iy<C && !isVisited[map[ix][iy]] &&  map[ix][iy])
		{
			
			dfs(depth +1 , ix, iy);
		}
	}

	isVisited[map[x][y]] = 0;
}
int main()
{
	scanf("%d %d", &R, &C);

	for (int t = 0; t < R; t++)
	{
	
		scanf("%s", map[t]);
	}

	dfs(1, 0, 0);

	printf("%d\n",cnt);


}