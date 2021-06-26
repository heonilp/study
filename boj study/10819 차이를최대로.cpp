#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int buf[8];

int N;
int sum = 0;
int bigsum = 0;
int main(void)
{

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &buf[i]);
		
	}


	sort(buf, buf+N);

	/*

	for (int i = N-1; i >= 0; i--)
	{
		
		cpbufone[swd] = buf[i];
		swd++;
	}

	for (int i = 0; i <N; i++)
	{
		cpbuf[2* i] = cpbufone[i];
	}

	

	for (int i = 1; i <N; i++)
	{
		cpbuf[2 * i -1] = buf[i-1];
	}
	*/
	while (next_permutation(buf, buf + N))
	{
		sum = 0;

		for (int i = 0; i < N-1; i++)
		{

			sum = sum + abs(buf[i] - buf[i + 1]);
		}

		bigsum = max(bigsum, sum);

	}





	printf("%d\n", bigsum);


	return 0;
}