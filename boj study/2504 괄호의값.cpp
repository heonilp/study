//2504 괄호의 값
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

char a[32];
stack<int> s;
int b[129], res;

int main()
 {
	b['('] = b[')'] = -2;
	b['['] = b[']'] = -3;
	
	scanf("%s", &a)
		;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (a[i] == '(' || a[i] == '[')
			s.push(b[a[i]]);
		else if (a[i] == ')' || a[i] == ']') {
			int sum = 0;
			while (!s.empty() && s.top() != b[a[i]]) {
				sum += s.top();
				s.pop();
			}
			if (s.empty()) {
				res = -1;
				break;
			}
			s.pop();
			sum *= -b[a[i]];
			if (!sum) sum = -b[a[i]];
			if (s.empty()) res += sum;
			else s.push(sum);
		}
	}
	printf("%d", (res > 0 && s.empty()) ? res : 0);
	return 0;
}