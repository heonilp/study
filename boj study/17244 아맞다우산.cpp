#include <stdio.h>
#include <queue>
#include <deque>
#include <memory.h>
#include <iostream>
#include <algorithm>

using namespace std;

char s[51][51];
int check[6];
int chckckckck[6];
int distance_save[8][8];
int dist[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 2e9;
int N,M;

struct st_xy
{
   int x,y;
};
st_xy g_start;
st_xy g_end;

deque <pair<int, int> > v;
queue <pair<int, int> > q;

void bfs(int r) 
{
    

	while (!q.empty())
	{
		int x= q.front().first;
		int y = q.front().second;
        
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && s[nx][ny] != '#' && dist[nx][ny]==0)
			{
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}

		}

	}
	for (int i = 0; i < v.size(); i++)
	{
		distance_save[r][i] = dist[v[i].first][v[i].second]-1;
	}
    
	memset(dist, 0, sizeof(dist));
}


void dfs(int cnt)
{
	if (cnt == v.size() - 2)
	{
		int sum = 0;
		sum = distance_save[0][check[0]];

		for (int i = 0; i < v.size()-3; i++)
		{
			sum = sum + distance_save[check[i]][check[i + 1]];
		}
	
		sum = sum + distance_save[check[cnt - 1]][v.size() - 1];

        ans =  min(ans, sum);
		sum = 0;
		return;
	}

	for (int i = 1; i <= v.size()-2; i++)
	{
		if (chckckckck[i] == 0)
		{
			chckckckck[i] = 1;
			check[cnt] = i;
			dfs(cnt + 1);
			check[cnt] = 0;
			chckckckck[i] = 0;
		}
	}
}

int main() 
{
    cin >> M >>N;

	for (int i = 0; i < N; i++)
	{
        cin >>s[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (s[i][j] == 'X')
			{
				v.push_back(make_pair(i, j));
			}

			else if (s[i][j] == 'S')
			{
				g_start.x = i, g_start.y = j;
			}
			else if (s[i][j] == 'E')
			{
				g_end.x = i, g_end.y = j;
			}
		}
	}
    
	v.push_front(make_pair(g_start.x, g_start.y));
	v.push_back(make_pair(g_end.x, g_end.y));
	
	for (int i = 0; i < v.size(); i++)
	{
		q.push(make_pair(v[i].first, v[i].second));
		dist[v[i].first][v[i].second] = 1;
		bfs(i);
	}
    
	if (v.size() == 2)
	{
        cout << distance_save[0][1]<<"\n";
		return 0;
	}
    
	dfs(0);

    cout << ans <<"\n";
    return 0;

}