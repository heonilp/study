#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 100001;

int N,K;
int arr[MAX];
int dp[MAX];
int ans=-987654321;

int main() 
{

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
     {
		cin >> arr[i];
	}
	int sum = 0;
	
    for (int i = 0; i < K; ++i)
     {
		sum = sum + arr[i];
	}

	dp[0] = sum - arr[0];
	ans = sum;
	sum = 0;
	
    for (int i = 0; i < N - K; i++) 
    {
		sum = dp[i] + arr[i + K];
		dp[i + 1] = sum - arr[i + 1];
		ans = max(ans, sum);
		sum = 0;
	}
	
    cout << ans << "\n";
}