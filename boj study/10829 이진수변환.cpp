#include <iostream>
#include <algorithm>

using namespace std;
int arr[100];
int cnt=0;

void go(long long a)
{
    if(a==1)
    {
        arr[cnt] =a;
    }
    else
    {
        arr[cnt] = a%2;
        cnt++;
        go(a/2);
    }
    
}

int main()
{
    long long a;
    cin >>a;
    go(a);
    
    reverse(arr, arr+cnt+1);
    for(int  i =0; i<=cnt; i++)
    {
        cout <<arr[i];
    }
    
    return 0;
}