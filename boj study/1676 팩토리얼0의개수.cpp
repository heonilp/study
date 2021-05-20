//우린 N!의 소인수 중 5의 개수가 0의 개수란 사실을 알고 있다.
//N의 값에서 5를 나눈 몫이 N ~ 1까지의 범위에서 5가 나올 개수를 의미한다.

#include <iostream>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int cnt =0;
    
    while(N>=5)
    {
        cnt += N/5;
        N/=5;
    }
    
    
    cout << cnt <<"\n";
    return 0;
    
}