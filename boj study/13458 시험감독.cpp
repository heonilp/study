#include<iostream>
#include<cstdio>
 
using namespace std;
int arr[1000001];

int main()
{
 
    int n;      //시험장 수
    cin >> n;
 
 
 
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    int major;  //총감독관이 감독할 수 있는 응시자의 수
    int sub;    //보조감독이 감독할 수 있는 응시자의 수
 
    cin >> major;
    cin >> sub;
 
    long long cnt=0;  //count.
 
    for(int i=0; i<n; i++)
    {
        arr[i] -= major;    //각 방에서 총 감독이 감독할 수를 뺸다
        cnt++;
 
        if(arr[i] > 0) 
        {//총감독이 감독할 수를 뺴면, 보조감독이 몇명 들어갈지 센다.
            if(arr[i] % sub == 0) 
            { //딱 맞는 경우
                cnt += (arr[i] / sub);
            }else{
                cnt += (arr[i] / sub)+1;
            }
        }
    }
 
 
    cout << cnt;
 
    return 0;
}