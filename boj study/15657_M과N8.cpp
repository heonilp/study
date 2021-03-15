#include <iostream>
#include <algorithm> 
using namespace std; 

int N, M; 
int arr[8]; 
int df[8];

void go(int idx, int start, int cnt) 
{ 
    if (cnt == M) 
    { 
        for (int i = 0; i < M; i++)
        {
             cout << arr[df[i]] << " ";
        }
         cout << "\n"; 
         return; 

    }

    if (idx == N) 
    { 
        return; 
    }

    for (int i = start; i < N; i++) 
    { 
        df[idx] = i;
        go(idx + 1, i, cnt + 1);
    } 
} 

int main(void) 
{ 
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    { 
        cin >> arr[i];
    } 
    sort(arr, arr + N);

    go(0, 0, 0);

    return 0; 
}

