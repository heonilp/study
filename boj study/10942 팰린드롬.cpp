#include <stdio.h>

int DPbuf[2001][2001];
int main()
{
 
    int N;
    int room[2001] = {0,};
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &room[i]);
 
    int questNum;
    scanf("%d", &questNum);
 
    for (int i = 1; i <= N; i++){
        DPbuf[1][i] = 1;
        DPbuf[0][i] = 1;
    }
    for (int i = 2; i <= N; i++){
        for (int j = 1; j <= N-i+1; j++){
            if (room[j] == room[j + i - 1] && DPbuf[i - 2][j + 1] == 1)
                DPbuf[i][j] = 1;
        }
    }
    while (questNum--){
        int S, E;
        scanf("%d %d", &S, &E);
        printf("%d\n", DPbuf[E-S+1+0][S+0]);
    }
    
    return 0;
}