#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

int graph[MAX][MAX];
int nation[MAX];

vector<int> ans;

int N = 0;
int cnt = 0;

void initfuc()
{
	cnt = 0;
	for (int m = 0; m<MAX; m++)
	{
		for (int n = 0; n<MAX; n++)
		{
			graph[m][n] = 0;
		}
	}

	for (int k = 0; k<MAX; k++)
	{
		nation[k] = 0;
	}

}

void bfs(int n, int start)
{

	queue<int> q;

	int node;
	nation[start] = 1;
	q.push(start);

	while (!q.empty()) {
		node = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (graph[node][i] == 1 && nation[i] == 0)
			{
				q.push(i);
				cnt++;
				nation[i] = 1;
			}
		}

	}
	ans.push_back(cnt);
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int x, y;
		int a, b;
		initfuc();
		scanf("%d %d", &a, &b);

		for (int j = 1; j <= b; j++)
		{
			scanf("%d %d", &x, &y);
			graph[x][y] = 1;
			graph[y][x] = 1;
		}

		bfs(a, 1);
	}

	int sumsize = (int)ans.size();

	for (int s = 0; s<sumsize;s++)
	{
		
		cout << ans[s] << "\n";
	}

	return 0;
}