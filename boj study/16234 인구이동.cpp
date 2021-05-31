#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 51 //범위 MAX값
#define DIR 4 // 방향 4방향
int N, L, R;
int cnt; 
int num;
int ans;
bool isMove= false; //이동을 했는가?
int map[MAX][MAX];
int isVisited[MAX][MAX];
int dx[DIR] = { 0,0,1,-1 };
int dy[DIR] = { 1,-1,0,0 };



struct st_xy
{
	int x;
	int y;
};

vector <st_xy> ver;

void ck_bfs(int x, int y)
{

	queue <st_xy> q;
	struct st_xy nownode;

	nownode.x = x;
	nownode.y = y;

	q.push(nownode);

	while (!q.empty())
	{
		struct st_xy getnode = q.front();

		q.pop();
		
		for (int i = 0; i < DIR; i++)
		{
			//상하좌우 4방향
			int nx = dx[i] +getnode.x;
			int ny = dy[i] +getnode.y;


			//빼서 범위 안에 안들어오면 인구 이동이 불가능하다.
			int diff = abs(map[nx][ny] - map[getnode.x][getnode.y]);

			//범위
			if (nx >= 0 && ny >= 0 && ny < N && nx < N && isVisited[nx][ny]==0 && diff >=L && diff <= R)
			{

				struct st_xy newnode;

				newnode.x = nx;
				newnode.y = ny;
				q.push(newnode);
				isVisited[nx][ny] = 1;
			}

		}

	}


}


//isVisited가 1인경우 움직인경우
void go_bfs(int x, int y)
{
	
	isVisited[x][y] = 0;
	queue <st_xy> q;
	struct st_xy nownode;

	nownode.x = x;
	nownode.y = y;

	q.push(nownode);

	while (!q.empty())
	{
		struct st_xy getnode = q.front();

		q.pop();

		//이동했으니 계산
		ver.push_back(getnode); //이동한 것 벡터에 저장
		cnt = cnt + 1; // 몇명인지 세기 
		num = num +map[getnode.x][getnode.y]; //숫자더하기

		for (int i = 0; i < DIR; i++)
		{
			//상하좌우 4방향
			int nx = dx[i] + getnode.x;
			int ny = dy[i] + getnode.y;


			//빼서 범위 안에 안들어오면 인구 이동이 불가능하다.
			int diff = abs(map[nx][ny] - map[getnode.x][getnode.y]);

			//범위
			if (nx >= 0 && ny >= 0 && ny < N && nx < N && isVisited[nx][ny] == 1 && diff >= L && diff <= R)
			{

				struct st_xy newnode;

				newnode.x = nx;
				newnode.y = ny;
				q.push(newnode);
				isVisited[nx][ny] = 0;

			}

		}

	}


}
//이동후 계산하기
void diff_move() 
{
	int after = num / cnt; //평균구하기
	int isize = ver.size();

	for (int i = 0;  i< isize; i++)
	{
		int ix = ver[i].x;
		int iy = ver[i].y;
		map[ix][iy] = after; //평균구해서 넣기(갱신)
	}
	isMove = true; //(움직임)
}


void initfuc()
{

	isMove = false;


	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			isVisited[r][c] = 0;
		}
		
	}


}

int main()
{

	cin >> N >> L >> R;
	//scanf("%d %d %d", &N, &L, &R);

	//input DATA
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{	
			cin >> map[r][c];
			//scanf("%d", &map[r][c]);
			//cout << map[r][c] << "\n";
		}
	}

	while (1)
	{
		//1. 인구가 이동할 나라들 체크 bfs
		//초기화
		initfuc();

		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (isVisited[r][c] == 0) // 0인것만, 초기화상태
				{
					ck_bfs(r, c);

				}

			}
		}


		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (isVisited[r][c] == 1)// 인구이동이 가능한것
				{
					num = 0;
					cnt = 0;
					ver.clear();
					go_bfs(r, c); //인구 이동
					diff_move(); // 계산

				}

			}
		}

		if (isMove == false) //이동하지 않았으면 멈춤
		{
			break;
		}
		else
		{
			ans++; // 몇번이동
		}

		
	}

		cout << ans << "\n";
		

	return 0;
}