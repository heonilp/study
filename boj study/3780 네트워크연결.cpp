#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>

using namespace std;

int N, M;
int p[20001] = { 0, };
int dist[20001] = { 0, };
int T = 0;

void init()
{
	for (int i = 1; i <= N; i++)
	{
		p[i] = i;
		dist[i] = 0;
	}
}

int getfind(int n) 
{
	if (n == p[n])
	{
		return n;
	}
	else 
	{
		int tmep = getfind(p[n]);
		dist[n] += dist[p[n]];
		p[n] = tmep;
		return tmep;
	}
}

void getUnion(int x, int y) 
{
	// 라인의 길이는 |I – J|(mod 1000)이다.
	dist[x] = abs(x - y) % 1000;
	p[x] = y;
}

int main() 
{
	scanf("%d", &T);

	char inputch = '0';

	while (T--) 
	{
		int a, b;
		scanf("%d", &N);
		a = 0, b = 0;
		init();
		
		while (true) 
		{
			scanf("%c",&inputch);

			if (inputch == 'O')
			{
				break;
			}

			else if (inputch == 'E')
			{
				scanf("%d", &a);	
				getfind(a);
				printf("%d\n", dist[a]);
			}
			else if (inputch == 'I')
			{
				scanf("%d %d",&a,&b);
				getUnion(a, b);
			}
		}
	}
	return 0;
}