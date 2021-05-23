#include <stdio.h>
 
int n, m;
int memory[101];
int cost[101];
int dp[10001][100];
int list[10001];
 
void init()
{
    int i, j;
 
    for (i = 0; i < 10001; i++) {
        for (j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }
}
int process()
{
    int i, j, t;
    int c, mem;
 
    dp[0][0] = 0;
 
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 10000; j++) {
            if (dp[j][i - 1] >= 0) {
                c = j;
                mem = 0;
                for (t = 0; t < 2; t++) {
                    if (dp[j][i - 1] + mem> dp[c][i])    dp[c][i] = dp[j][i - 1] + mem;
                    c = j + cost[i];
                    mem = memory[i];
                }
            }
        }
    }
 
    j = 0;
    while (j <= 10000 && dp[j][n] < m)    j++;
    return j;
}
 
int main() {
    int i;
 
    scanf("%d %d", &n, &m);
 
    init();
 
    for (i = 1; i <= n; i++)        scanf("%d", &memory[i]);
    for (i = 1; i <= n; i++)         scanf("%d", &cost[i]);
 
    printf("%d\n", process());
 
    return 0;
}