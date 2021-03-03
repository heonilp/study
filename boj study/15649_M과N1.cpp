#include <iostream>
using namespace std;
bool c[10];
int a[10];

//자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
//1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

//한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
//중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
//수열은 사전 순으로 증가하는 순서로 출력해야 한다.
void go(int index, int n, int m) 
{
    if (index == m) 
    {
        for (int i=0; i<m; i++)
        {
            cout << a[i];

            if (i != m-1) cout << ' ';
        }
    
        cout << '\n';
        return;
    }

    for (int i=1; i<=n; i++)
    {
        if (c[i]) continue;
        c[i] = true;
        a[index] = i;

        go(index+1, n, m);
        c[i] = false; // 다시돌려넣는다.
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    
    go(0,n,m);

    return 0;
}