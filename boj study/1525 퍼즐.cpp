#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

#define DIR 4
#define MAX 3
int dx[DIR] = { 0,0,1,-1 };        //행축으로 이동
int dy[DIR] = { 1,-1,0,0 };        //열축으로 이동
int main()
{
	int start = 0;
	for (int i = 0; i<MAX; i++)        //퍼즐 숫자 입력받기
	{
		for (int j = 0; j<MAX; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 0)
			{
				temp = MAX * MAX;
			}
			start = start * 10 + temp;    //퍼즐 숫자를 int형 숫자로 저장
		}
	}
	queue<int> q;
	map<int, int> dist;        // 배열 대신 map을 사용한다.
	dist[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		int now_num = q.front();
		string now = to_string(now_num);        //now_num는 int형이므로 string형으로 바꾼다 ('9'를 찾기위해)
		q.pop();
		int nn = now.find('9');        // 9의 위치
		int x = nn / MAX;                // 9의 위치의 행값
		int y = nn % MAX;                // 9의 위치의 열값
		for (int k = 0; k<DIR; k++)    // 4방향으로 이동
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny <3)        //경계를 넘어가지 않았을 때만 유효한 퍼즐이 된다.
			{
				string next = now;
				swap(next[MAX * x + y], next[MAX * nx + ny]);        //일자로 펼쳐진 숫자에서 퍼즐의 4방향에 위치한 숫자와 바꾼다 (실제로 이동하는 작업을 수행하는 부분!)
				int num = stoi(next);                        //다시 int형으로 바꾼다.
				if (dist.count(num) == 0)                    //dist.count(a)는 a라는 key값이 있을 때 1을 return 하고, 없을 때 0을 return한다.
				{                                            //즉, 나오지 않았던 퍼즐(방문하지 않았던 node)만 카운트 한다.
					dist[num] = dist[now_num] + 1;
					q.push(num);
				}
			}
		}
	}
	if (dist.count(123456789) == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dist[123456789] << endl;
	}
	return 0;
}