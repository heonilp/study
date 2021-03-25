#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define DIR 8
#define MAXSIZE 1001
#define MAX(x, y) x>y ? x : y
//8방향
int dx[DIR] = { -1,-1,-1,0,1,1,1,0 };
int dy[DIR] = { -1,0,1,1,1,0,-1,-1 };
int H, W;
char map[MAXSIZE][MAXSIZE];
int cnt[MAXSIZE][MAXSIZE];
int solans = -1;


struct sol
{
	int i;
	int j;
};


queue<sol> q;

void bfs()
{
	while (!q.empty()) {
		//모래성이 쓸린 값 빼넣음
		sol sl = q.front();
		int cx = sl.i;
		int cy = sl.j;

		q.pop();
		// 쓸린 것으로 체크
		map[cx][cy] = '.';


		// 8방향 체크
		for (int i = 0; i< DIR; i++)
		{
			//8방향 좌표
			int nx = cx + dx[i];
			int ny = cy + dy[i];


			//범위 체크
			if (0 <= nx && nx<H && 0 <= ny && ny<W) 
			{
				//체크
				if (map[nx][ny] != '.' && cnt[nx][ny]==0)
				{
					int count = 0;
					//반복 체크 쓸렸으면 체크
					for (int j = 0; j< DIR; ++j)
					{
						int xn = nx + dx[j];
						int yn = ny + dy[j];
						if (0 <= xn && xn < H && 0 <= yn && yn < W && map[xn][yn] == '.')
						{
							//. 개수 증가
							count++;
						}
					}
					if (map[nx][ny] - '0'<=count) // .개수와 숫자비교
					{
						sol sl;
						sl.i = nx, sl.j = ny;
						q.push(sl);
						//1증가해줌
						cnt[nx][ny] = cnt[cx][cy] + 1;
					}
				}
			}
		}
	}


}


int main()
{

	scanf("%d %d", &H, &W);
	
	for (int i = 0; i<H; i++)
	{
		scanf("%s", map[i]);
	}

	// 처음에 8방향 모래가 자기수보다 크면 큐에 넣음 
	for (int i = 0; i<H; i++) 
	{
		for (int j = 0; j<W; j++)
		{
			int count = 0;

			if (map[i][j] == '.')
			{
				continue;
			}
			

			for (int k = 0; k<DIR; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				// 범위 체크
				if (0 <= nx && nx<H && 0 <= ny && ny<W)
				{
					if (map[nx][ny] == '.')
					{
						count++;
					}
				}
			}
			if (map[i][j] - '0'<=count) // .개수와 숫자비교
			{
				sol sl;
				sl.i = i, sl.j = j;
				q.push(sl);
				//처음 카운트 1번넣어줌 
				cnt[i][j] = 1;
			}
		}
	}

	bfs();



	//검색해서 가장 큰값해주고 카운트
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			solans = MAX(solans, cnt[i][j]);
		}
	}

	printf("%d\n", solans);
	return 0;
}