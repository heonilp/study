//Brainf**k 인터프리터

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int MOD = 256;
const int INF = 987654321;
const int MAX = 5 * 1e7;
const int DATA_MAX = 1e5 + 100;

int main(void)
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int sm, sc, si;
		cin >> sm >> sc >> si;

		string program, input;
		cin >> program >> input;

		int datas[DATA_MAX] = { 0, };
		map<int, int> loopPair;

		vector<int> v;

		for (int i = 0; i < program.length(); i++)
		{
			if (program[i] == '[')
			{
				v.push_back(i);
			}
			else if (program[i] == ']')
			{
				int temp = v.size() - 1;
				loopPair[v[temp]] = i;
				loopPair[i] = v[temp];

				v.pop_back();
			}
		}

		int idx = 0;
		int programIdx = 0;
		int inputIdx = 0;
		int loopStartIdx = INF;
		bool isTerminated = true;

		for (int i = 0; i < program.length(); i++)
		{
			switch (program[i])
			{
			case '+':
				datas[idx] = (datas[idx] + 1) % MOD;

				break;
			case '-':
				datas[idx] = (datas[idx] + MOD - 1) % MOD;

				break;
			case '<':
				idx = (idx + sm - 1) % sm;

				break;
			case '>':
				idx = (idx + 1) % sm;

				break;
			case '[':
				if (datas[idx] == 0)
				{
					i = loopPair[i];
				}

				break;
			case ']':
				if (datas[idx])
				{
					i = loopPair[i];
				}

				break;
			case '.':
				// cout << datas[idx] << "\n";

				break;
			case ',':
				datas[idx] = (inputIdx == si) ? MOD - 1 : (int)input[inputIdx++];

				break;
			}

			if (++programIdx > MAX)
			{
				loopStartIdx = min(loopStartIdx, i);
			}

			if (programIdx > MAX * 2)
			{
				isTerminated = false;

				break;
			}
		}

		if (isTerminated == false)
		{
			cout << "Loops " << loopStartIdx << " " << loopPair[loopStartIdx] << "\n";
		}
		else
		{
			cout << "Terminates\n";
		}
	}

	return 0;
}