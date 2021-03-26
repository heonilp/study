#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


char int_to_char(int num)
{
	switch (num)
	{
		case 0:	return '0';
	
		case 1:	return '1';

		case 2:	return '2';

		case 3:	return '3';

		case 4:	return '4';

		case 5:	return '5';

		case 6:	return '6';

		case 7:	return '7';

		case 8:	return '8';

		case 9:	return '9';

		default:
		break;
	}
	return '0';
}

//int 형을 string으로 바꾸는 함수짜기
 std::string hi_to_string(int input)
{
	std::string result;
	int temp = input;

	if (input < 0)
	{
		temp = abs(input);
	}
	do
	{
		result = int_to_char(temp % 10) + result;
		temp /= 10;

	} while (temp != 0);

	if (input < 0)
	{
		result = "-" + result;
	}
	
	return result;

}


int main(void)
{
	std::string a = hi_to_string(-12512);
	cout << a << endl;


	std::string b = hi_to_string(12512);
	cout << b << endl;

	std::string c = hi_to_string(0);
	cout << c << endl;

	return 0;
}