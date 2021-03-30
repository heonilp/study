//16926 배열 돌리기1
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <map>

using namespace std;
int N, M, R, S;
int m[301][301];

void spin()
{
	for (int s = 0; s < S; s++) 
	{
		int T = s;
		int B = N - 1 - s;
		int R = M - 1 - s;
		int L = s;

		int tmp = m[s][s];

		for (int i = L; i < R; i++)    m[T][i] = m[T][i + 1];
		for (int i = T; i < B; i++)    m[i][R] = m[i + 1][R];
		for (int i = R; i > L; i--)    m[B][i] = m[B][i - 1];
		for (int i = B; i > T; i--)    m[i][L] = m[i - 1][L];

		m[T + 1][L] = tmp;

	}
}


int main(void)
{

	cin >> N >> M >> R;

	S = min(N, M) / 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> m[i][j];
		}
	}


	for (int i = 0; i < R; i++)
	{
		spin();
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout<< m[i][j] << " ";
		}

		cout << "\n";
	}

	
	return 0;
}



//추가적 준비 , 오른쪽도 돌리기
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <map>

using namespace std;
int N, M, R, S;
int m[301][301];

void spin(int dir)
{
	for (int s = 0; s < S; s++) 
	{


		if (dir == 0) // 왼쪽
		{
			int T = s;
			int B = N - 1 - s;

			int R = M - 1 - s;
			int L = s;

			int tmp = m[s][s];
			for (int i = L; i < R; i++)    m[T][i] = m[T][i + 1];
			for (int i = T; i < B; i++)    m[i][R] = m[i + 1][R];

			for (int i = R; i > L; i--)    m[B][i] = m[B][i - 1];
			for (int i = B; i > T; i--)    m[i][L] = m[i - 1][L];

			m[T + 1][L] = tmp;
		}

		if (dir == 1) // 오른쪽
		{
			int T = M - 1 - s; // s;
			int B = s;

			int R = s;// N - 1 - s;
			int L = N - 1 - s;


			int tmp = m[s][s];

			for (int i = R; i < L; i++)   m[i][B] = m[i+1][B];
			for (int i = B; i < T; i++)   m[L][i] = m[L][i +1];

			for (int i = L; i > R; i--)   m[i][T] = m[i -1][T];
			for (int i = T; i > B; i--)   m[R][i] = m[R][i - 1];

			m[R][B +1] = tmp;
		}

	}
}


int main(void)
{

	cin >> N >> M >> R;

	int dir;
	cin >> dir; // 왼쪽 오른쪽

	S = min(N, M) / 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> m[i][j];
		}
	}




	for (int i = 0; i < R; i++)
	{
		spin(dir); // 왼쪽 오른쪽
	}

	cout << "\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout<< m[i][j] << " ";
		}

		cout << "\n";
	}

	
	return 0;
}

