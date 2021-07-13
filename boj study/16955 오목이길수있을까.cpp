#include<iostream>
using namespace std;

int xrr[8] = { -1,-1,-1,0,0,1,1,1};
int yrr[8] = {-1,0,1,-1,1,-1,0,1};

char map[502][502];

int go(int x, int y)
{

	//cout << x << " " << y << endl;
	for (int i = 0; i < 8; i++)
	{

		int cx = x;
		int cy = y;  

		int cnt = 1; //구사과 돌 개수
		int empty = 0;//빈공간

		for (int j = 0; j < 4; j++)

		{

			int curx = cx + xrr[i];
			int cury = cy + yrr[i];

			if (0 <= curx&&curx < 10 && 0 <= cury&&cury < 10)
			{

				if (map[curx][cury] == 'X')
					cnt++;

				if (map[curx][cury] == '.')
					empty++;

			
				cx = curx;
				cy = cury;  //해당방향의 그 다음 돌 검색 

			}

			else 
				break;

		}

		if (cnt == 4 && empty == 1)return 1;

	}

	return 0;

}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 'X')
			{
				if (go(i, j))
				{
					cout << 1 << "\n";
					return 0;
				}
			}
		}
	}

	cout << 0 << "\n";
	return 0;
}
