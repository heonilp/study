
#include <iostream>
using namespace std;

int board[1001][1001];

int find_num, find_nx, find_ny;
int n, cnt;

void num_check(int nx, int ny)
{
	if (cnt == find_num)
    {
		find_nx = nx;
		find_ny = ny;
	}
}

void output() 
{
	for (int i = 1; i <= n; ++i) 
    {
		for (int j = 1; j <= n; ++j) 
        {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << find_nx << " " << find_ny << "\n";
}

void go() 
{

	int nx = 0, ny = 1;
	int dir = 1;
	int move_cnt = n;

	while (1) 
    {
		for (int i = 0; i < move_cnt; ++i) 
        {
			nx = nx + dir;
			num_check(nx, ny);
			board[nx][ny] = cnt--;
		}
        
		move_cnt--;
        
		if (move_cnt == 0)
        {
            break;
        }
        
		for (int i = 0; i < move_cnt; ++i) 
        {
			ny = ny + dir;
			num_check(nx, ny);
			board[nx][ny] = cnt--;
		}
		dir = -dir;
	}
}

void input() 
{
	cin >> n >> find_num;
	cnt = n * n;
}

int main()
{
	input();
	go();
	output();

	return 0;
}