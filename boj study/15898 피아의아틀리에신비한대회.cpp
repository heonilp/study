#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Material
{
    int val;
    char col;
};

Material mat[10][5][5];
Material gama[10][10];

int n,ans;
int arr[3];
int dx[] = {0,1,0,1}, dy[] = {0,0,1,1};
int rate[100];

void check (void)
{
    int i,j,value = 0;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            value += rate[gama[i][j].col] * gama[i][j].val;

    ans = max(ans, value);

    return ;
}
void addMaterial (int idx,int x,int y)
{
    int i,j;
    Material *ptr, cur;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            ptr = &gama[i+x][j+y];
            cur = mat[idx][i][j];
            ptr->val += cur.val;
            ptr->val = min(ptr->val, 9);
            ptr->val = max(ptr->val, 0);

            ptr->col = (cur.col != 'W' ? cur.col : ptr->col);
        }
    }

    return ;
}
void Rotation (int idx)
{
    int i,j;
    Material tmp[5][5];

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            tmp[j][3-i] = mat[idx][i][j];

    memcpy(mat[idx],tmp,sizeof(tmp));

    return ;
}
void recursion (int depth)
{
    int i,j;
    Material bak[10][10];

    if(depth == 3){
        check();
        return ;
    }

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            memcpy(bak, gama, sizeof(bak));
            addMaterial(arr[depth],dx[j],dy[j]);
            recursion(depth + 1);
            memcpy(gama, bak, sizeof(bak));
        }
        Rotation(arr[depth]);
    }

    return ;
}
void func (int a,int b,int c)
{
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    do{
        recursion(0);
    }while(next_permutation(arr,arr+3));

    return ;
}
int main (void)
{
    int i,j,k;

    scanf("%d",&n);

    rate['R'] = 7;
    rate['B'] = 5;
    rate['G'] = 3;
    rate['Y'] = 2;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            gama[i][j].col = 'W';

    for(i=0;i<n;i++){
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                scanf("%d",&mat[i][j][k].val);

        scanf("%*c");
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                scanf("%c%*c",&mat[i][j][k].col);
    }

    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
            for(k=j+1;k<n;k++)
                func(i,j,k);

    printf("%d\n",ans);

    return 0;
}
