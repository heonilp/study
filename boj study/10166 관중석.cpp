//gcd문제
#include <stdio.h>

int seat[2000][2001];

int gcd(int a, int b)
{
    return (b) ? gcd(b, a%b) : (a);
}

int main()
{

    int ret =0;
    int from, to;
    
    scanf("%d %d", &from, &to);
    
    for(int i= from ; i<=to; i++)
    {
        for(int j=0; j<i ; j++)
        {
            int g = gcd(i,j);
            int up = j/g;
            int down =i/g;
            if(seat[up][down] ==0)
            {
                seat[up][down] = 1;
                ret++;
            }
        }
    }
    
    printf("%d\n", ret);
    
    return 0;
}