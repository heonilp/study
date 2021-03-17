#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
bool check[8];
vector<int> v;
void go(int cnt) {
	if (cnt == M) {
		for (int i = 0; i <(int) v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}
	bool used[10002] = { false, };
	for (int i = 0; i < N ; ++i) {
		if (!used[arr[i]] && !check[i]) {
			check[i] = true;
			used[arr[i]] = true;
			v.push_back(arr[i]);
			go(cnt + 1);
			v.pop_back();
			check[i] = false;
		}
	}
}
int main() {

	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	sort(arr, arr + N);
	go(0);
	
	return 0;
}