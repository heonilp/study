// boj 20055 컨베이어 벨트 위의 로봇
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <map>
#include <unordered_map>
#include <deque>
using namespace std;

int N = 0; // 문제에서 주어진 N, K
int K = 0;
int timer = 0; // 몇단계까지 되었는지 출력
deque <int > v;// Ai 담는 벡터
deque <bool> c; // false , ture 체크


//이동하는 함수
void move()
{
	for (int i = N - 2; i >= 0; i--) 
	{
		if ((!c[i + 1]) && (v[i + 1] > 0) && (c[i])) 
		{
			c[i] = false;
			c[i + 1] = true;
			v[i + 1]--;
		}
	}
	c[N - 1] = false;
}

void put()
{
	if (!c[0] && v[0] > 0)
	{
		c[0] = true;
		v[0]--;
	}
}

//체크해줌
int ck()
{
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) 
	{
		if (v[i] == 0)
		{
			cnt++;
		}
	}
	return cnt;
}

//회전
void rotate()
{
	c.push_front(c.back());
	c.pop_back();

	v.push_front(v.back());
	v.pop_back();
	c[N - 1] = false;
}

int main() 
{
	//횟수
	timer = 1;
	cin >> N >> K;

	for (int i = 0; i < N * 2; i++)
	{
		int input = 0;
		cin >> input;
		v.push_back(input);
		c.push_back(false);
	}
	while (1)
	{
		//1.벨트가 한 칸 회전한다.

		rotate();
		
		//2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.만약 이동할 수 없다면 가만히 있는다.
		// 2.1 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
		move();

		//3. 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
		put();

		int f = ck();
		//4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
		if (f >= K)
		{
			cout << timer << "\n";
			return 0;
		}
		timer++;
	}
	return 0;
}
