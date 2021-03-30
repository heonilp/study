
//파일 입출력 공부 예제... 복습
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <map>

using namespace std;
#define N 100

struct _item
{
	string s;
	int cnt;
};

bool cmp(const struct _item& a, const struct _item& b)
{
	return a.cnt > b.cnt;
}

int main(void)
{
	
	vector<struct _item> v;
	map<string, int > m;

	FILE* in = freopen("data.txt", "r", stdin);


	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			string a;
			cin >> a;

			if (a != "")
			{
				m[a]++;
			}
		}
	}

	for (auto it = m.begin(); it != m.end(); it++)
	{
		struct _item item;
		item.cnt = it->second;
		item.s = it->first;
		v.push_back(item);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		std::cout<< v[i].s <<" ";
	}

	fclose(in);

	return 0;
}

