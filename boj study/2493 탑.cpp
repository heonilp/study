#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int h[500001], map[500001], ans;
stack<int> stk;

int main()
{
    
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
    {
		scanf("%d", &h[i]);
	}

	for (int i = 1; i <= n; ++i)
    {    //왼쪽으로 뻗을 수 있는 정도
		int tmp;

		while (true)
        {

			if (!stk.empty())
            {
				tmp = h[stk.top()];
			}
			else
            {
				tmp = -1;
			}

			if (tmp < h[i] && tmp != -1) stk.pop();
			else
             {

				if (stk.size() == 0)
                {
					map[i] = 0;
					stk.push(i);
					break;
				}

				else
                {
					map[i] = stk.top();
					stk.push(i);
					break;

				}

			}

		}

	}



	for (int i = 1; i <= n; ++i)
    {
		printf("%d ", map[i]);
	}

	return 0;
}