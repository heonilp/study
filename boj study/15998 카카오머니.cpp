#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
/*
만약 유효한 최소 충전 단위 M(1 ≤ M ≤ 9 * 10^18)이 존재한다면,
첫 번째 줄에 M 을 출력한다. 가능한 값이 여러 가지 있다면,
그중 9 * 10^18 이하인 것을 아무거나 하나 출력한다.
존재하지 않는다면 -1을 출력한다.
*/
struct st_money
{
	ll total;
	ll put;
};
ll ans = 0;
struct st_money one_money[300001];
vector <ll> ver_put;
//최대 공약수 GCD 문제
ll gcd(ll a, ll b) 
{
	while (b != 0) 
	{
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return abs(a);
}
void sol(ll put, ll total, int n)
{
	/*
	2
	-3 6 -> 9충전 나옴
	-7 2
	->3나오고 결과론적으로 -1나와야함
	*/
	
	if (put >= 0)
	{
		return;
	}
	ll pay_total = one_money[n - 1].total;
	
	//음수 , 출금
	if (put < 0)
	{
		ll g_plus = total - pay_total - put;
		//cout << put << " " << total << " " << g_plus << " " << pay_total << endl;
		//save = total;
		if (g_plus == 0)
		{
			return;
		}
		ver_put.push_back(g_plus);
		//sort(ver_put.begin(), ver_put.end());
		//정렬하면 시간초과남 *nlogn 이 곱해져서.. 
	}
}
int main()
{
	int N = 0;
	cin >> N;
	ver_put.push_back(-200000);
	for (int n = 1; n <= N; n++)
	{
		cin >> one_money[n].put >> one_money[n].total;
		sol(one_money[n].put, one_money[n].total, n);
	}
	ll size = ver_put.size();
	for (ll i = 1; i < size; i++)
	{
		ans = gcd(ans, ver_put[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		if ((one_money[i].total - one_money[i - 1].total) == one_money[i].put)
		{
			continue;
		}
		if((ans && ans <= one_money[i].total
			|| one_money[i].put != 0
			 && -one_money[i].put<one_money[i-1].total))
		{
			
			printf("%d\n", -1);
			return 0;
		}
	}
	
    if(ans<=1)
    {
        printf("%d\n",1);
    }
    else 
    {
        printf("%lld\n",ans);
    }
	return 0;
}