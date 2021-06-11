#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

#define MAX 10
#define MAXMAX 100
using namespace std;

struct st_point
{
	int x;
	int y;
};


int N, M, land_cnt, ans = 2e9;
int imap[MAX][MAX] = { 0 }; // 맵 저장                 

int gnumbering[MAX][MAX] = { 0 };//섬번호 저장    
int dist_buffer[MAX][MAX] = { 0 };//거리 저장
									
int visited[MAX][MAX] = { 0 };
int inininin[MAX][MAX] = { 0 };  //연결
int ininininIsland[MAX]; //연결된섬
int ckckckckckplusckckck[MAXMAX] = { 0 }; //중복제외하기위해   
vector<st_point>v;                   //all  
vector<st_point> land_v[MAX + 1];   //섬좌표만
vector<pair<st_point,int>> bl; //섬과 거리 저장

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


bool ckckckckckckck(int nx, int ny)
{
	return nx >= 0 && ny >= 0 && nx < N && ny < M;
}

void dfs(int x, int y, int dir, int onesizeckckckck, int go1, int go2)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (!ckckckckckckck(nx, ny))
	{
		return;
	}

	if (imap[nx][ny] == 0) dfs(nx, ny, dir, onesizeckckckck + 1, go1, go2);

	else if (imap[nx][ny] == 1)
	{
		if (gnumbering[nx][ny] == go2)
		{
			if (onesizeckckckck > 1)
			{
				if (dist_buffer[go1][go2] > onesizeckckckck)
				{
					dist_buffer[go1][go2] = onesizeckckckck;
					dist_buffer[go2][go1] = onesizeckckckck;
				}
			}
		}
	}
}

void bfs(int a, int b, int cnt)
{

	queue<st_point> q;
	q.push({ a,b });
	land_v[cnt].push_back({ a,b });
	visited[a][b] = 1;
	gnumbering[a][b] = cnt;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ckckckckckckck(nx,ny))
			{
				if (visited[nx][ny]==0 && imap[nx][ny] == 1)
				{
					visited[nx][ny] = 1;
					gnumbering[nx][ny] = cnt;
					q.push({nx, ny});
					land_v[cnt].push_back({ nx,ny });
				}
			}
		}
	}
}

//섬 이동되는지 검색
void gogogo(int go1, int go2)
{
	//go1 ->go2
	int landsize = land_v[go1].size();
	for (int i = 0; i < landsize; i++)
	{
		int x = land_v[go1][i].x;
		int y = land_v[go1][i].y;

		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (ckckckckckckck(nx, ny) == 1)
			{
				if (imap[nx][ny] == 0)
				{
					dfs(x, y, j, 0, go1, go2);
				}
			}
		}
	}
}








bool ckcksum()
{
	memset(inininin , 0, sizeof(inininin));
	memset(ininininIsland, 0, sizeof(ininininIsland));

	for (int i = 0; i < bl.size(); i++)
	{
		if (ckckckckckplusckckck[i] == 1)
		{
			int x = bl[i].first.x;
			int y = bl[i].first.y;

			inininin[x][y] = 1;
			inininin[y][x] = 1;
		}
	}

	queue<int> countq;
	countq.push(1);
	ininininIsland[1] = 1;

	int land_count = 1;
	bool retf = 0;
	while (!countq.empty())
	{
		int c = countq.front();
		countq.pop();

		if (land_count == land_cnt - 1)
		{
			retf = 1;
			break;
		}

		for (int i = 1; i < land_cnt; i++)
		{
			if (c == i) continue;
			if (inininin[c][i] == 1 && ininininIsland[i] == 0)
			{
				ininininIsland[i] = 1;
				countq.push(i);
				land_count++;
			}
		}
	}
	return retf;
}

//길이 dfs
void go(int index, int count, int sumsumsum)
{
	//cout << ckcksum() << endl;

	if (count >= 1)
	{
		if (ckcksum() == true)
		{
			ans =min(ans, sumsumsum);
		//	cout << ans << endl;
		}
	}

	for (int i = index; i < bl.size(); ++i)
	{
		if (ckckckckckplusckckck[i] == 0)
		{
			ckckckckckplusckckck[i] = 1;
			go(i, count + 1, sumsumsum + bl[i].second);
			ckckckckckplusckckck[i] = 0;
		}
	}
}



int main()
{


	cin >> N >> M;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			dist_buffer[i][j] = 2e9;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> imap[i][j];
			//cout << imap[i][j];
			if (imap[i][j] == 1)
			{
				v.push_back({ i,j });
			}
		}
	}
	

	//넘버링
	int num = 1;

	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].x;
		int y = v[i].y;

		if (visited[x][y] == 0) bfs(x, y, num++);
	}
	land_cnt = num;
	
	//섬 이어주기
	for (int i = 1; i < land_cnt; i++)
	{
		for (int j = i + 1; j < land_cnt; j++)
		{
			gogogo(i, j);
			if (dist_buffer[i][j] != 2e9)
			{
				st_point sp;
				sp.x = i;
				sp.y = j;
				int pushdistpoint = dist_buffer[i][j];
				bl.push_back(make_pair(sp, pushdistpoint));
			}
		}
	}

	go(0, 0, 0);      
    //cout << ans <<endl;
	if (ans == 2e9)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << ans << "\n";
	}

	return 0;
}