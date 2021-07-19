#include<iostream>
 
typedef long long ll;
#define endl "\n"
#define MAX 33
using namespace std;
 
int N;
int MAP[MAX][MAX];
long long DP[MAX][MAX][3]; 
//3가지 방향에 대해서 동, 남, 대 해당 좌표까지 올 수 있는 경우의 수를 저장
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void Solution()
{
    DP[0][1][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j == 0) continue;
            if (MAP[i][j] == 1) continue;
 
            if (MAP[i][j + 1] == 0) DP[i][j + 1][0] = DP[i][j][2] + DP[i][j][0];
            if (MAP[i + 1][j] == 0) DP[i + 1][j][1] = DP[i][j][2] + DP[i][j][1];
            if (i + 1 < N && j + 1 < N)
            {
                if (MAP[i + 1][j] == 0 && MAP[i][j + 1] == 0 && MAP[i + 1][j + 1] == 0) DP[i + 1][j + 1][2] = DP[i][j][0] + DP[i][j][1] + DP[i][j][2];
            }
        }
    }
 
    cout << DP[N - 1][N - 1][0] + DP[N - 1][N - 1][1] + DP[N - 1][N - 1][2] << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{

    Solve();
 
    return 0;
}