/*
문제
가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서,
i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

입력

첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다. 
둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다. 
i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다. 
i번째 줄의 i번째 숫자는 항상 0이다.


출력
총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다.
정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.


*/

//3가지 방법
//DFS, BFS, 플로이드 와샬 알고리즘 

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 101
int N = 0;

int map[MAX][MAX]; //주어진 테케의 맵
int answer[MAX][MAX];//인접행렬방식으로 출력 넣기
int isVisited[MAX][MAX]; // 방문처리

struct st_ij
{
	int start;
	int target;

};

void initfuc()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			isVisited[i][j] = 0;
		}
	}

}


void dfs(int target, int start) 
{
	for (int  i= 0; i < N; i++) 
	{
		//i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고,
		//0인 경우는 없다는 뜻이다. i번째 줄의 i번째 숫자는 항상 0이다.
		//정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.
		if (map[start][i] == 1 && isVisited[start][i] == 0)
		{
			isVisited[start][i] = 1;
			answer[target][i] = 1;
			dfs(target, i);
		}
	}
}

void bfs(int target, int start)
{

	queue <st_ij> q;
	
	struct st_ij ij;

	ij.start = start;
	ij.target = target;

	q.push(ij);

	while (!q.empty())
	{
		struct st_ij nownode = q.front();

		q.pop();

		for (int i = 0; i < N; i++)
		{
			//i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고,
			//0인 경우는 없다는 뜻이다. i번째 줄의 i번째 숫자는 항상 0이다.
			//정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.
			if (map[nownode.start][i] == 1 && isVisited[nownode.start][i] == 0)
			{
				isVisited[nownode.start][i] = 1;
				answer[nownode.target][i] = 1;
				
				struct st_ij newnode;

				newnode.target = nownode.target;
				newnode.start = i;
				q.push(newnode);

			}
		}

	}
}




int main()
{

	cin >> N;

	initfuc();


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	

	for (int i = 0; i < N; i++)
	{
		initfuc();
		//dfs(i, i);
		bfs(i, i);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << answer[i][j] << ' ';
		}
		cout << "\n";

	}

	return 0;
}


/*

//방법 3
/*
이 문제는 플로이드-워셜 알고리즘 을 사용하면 풀 수 있다.
i에서 j로 가는 방법은 다음과 같은 방법이 존재한다.
•i에서 j로 곧장 가는 방법
•i에서 임의의 정점 k를 거쳐 j로 가는 방법

문제의 입력을 받을 때 i에서 j로 가는길을 입력받기 때문에 i에서 임의의 점점 k를 거쳐 j로 가는 방법들을 추가해주면 된다.

*/
/*
#include <cstdio>

#define MAX 101
#define DIR 4
int N;

int map[MAX][MAX];

int main(){
	int temp;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(int k = 0 ; k < N ; k++){
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				if( map[i][k] && map[k][j]){
					map[i][j] = 1;
				}
			}
		}
	}

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
 
*/
