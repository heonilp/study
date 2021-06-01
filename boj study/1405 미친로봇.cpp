#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
int inputN; // N값은 0
int E; //동
int W; //서
int N; //북
int S; //남

int v[29][29]; //방문체크

double result; // 확률

void dfs(int y, int x, int cnt, double total)
{

	v[y][x] = 1;

	if (cnt == inputN)
	{
		result += total;
		//return;
	}

	//동서남북 이동
	if (cnt < inputN && v[y][x + 1] != 1)
		dfs(y, x + 1, cnt + 1, total * E / 100); //동

	if (cnt < inputN && v[y][x - 1] != 1)
		dfs(y, x - 1, cnt + 1, total * W / 100); //서

	if (cnt <  inputN && v[y - 1][x] != 1)
		dfs(y - 1, x, cnt + 1, total * N / 100); //북

	if (cnt < inputN && v[y + 1][x] != 1)
		dfs(y + 1, x, cnt + 1, total * S / 100); //남



	v[y][x] = 0;


}



int main()
{

	scanf("%d", &inputN);

	scanf("%d %d %d %d", &E, &W, &N, &S);


	//N은 14보다 작거나 같은 자연수이고
	//모든 확률은 100보다 작거나 같은 자연수 또는 0이다.
	dfs(inputN, inputN, 0, 1.0);

	printf("%.10lf", result);

	return 0;
}