
/*

팀원 풀이방법

     idx | 0 1 2 3 4 5 6 7 8
     arr | 1 2 3 4 5 6 7 8 9

정상적이라면 위와 같이 들어있다.
만약, 2가 missing number가 된다면

     idx | 0 1 2 3 4 5 6 7 8
     arr | 1 3 4 5 6 7 8 9 10

위와 같이 된다.
2가 있어야 하는 1번 idx에 missing number가 생겼으므로,
missing number가 생긴 1번 인덱스 부터 arr[idx] - (idx+1) 가 1이 된 것을 볼 수 있다.

만약, 5,6,7 도 msissing number라고 한다면, 
     idx | 0 1 2 3 4 5  6  7  8
     arr | 1 3 4 8 9 10 11 12 13

위와 같이 된다.
여기서, missing number는 2, 5,6,7이 되는데,
idx 0 에는 1이 있어야 하고, 1까지는 missing number가 없어서 1이 그대로 있다.
idx 2에는 원래 3이 있어야 하고, 4가 들어있으므로 missing number가 1개임을 알 수 있다.
idx 3에는 4가 있어야 하고, 현재 8이 있으므로, missing number는 4개임을 알 수 있다.
이를 통해 2번째 missing number는 idx 3에 있다는 것을 알 수 있고, 이는 3+2 = 5이다.

이를 일반화 하면, missing number가 X개면 arr[idx] - (idx+1) >= X가 되는 idx를 찾아서 k를
더하면 된다는 것을 알 수 있다. 이는 이분 매칭으로 찾을 수 있다.
*/


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0, e = arr.size();
        if(arr[0] > k) return k;
        while(s<e){
            int m = (s+e)/2;
            if(arr[m] < m+k+1){
                s = m+1;
            }
            else e= m;
        }
        return e+k;
    }
};




class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k)
        {
             return k;
        }
           
        int n = arr.size();
        int u = n+k;
        
        if(arr[n-1] < u)
        {
            return u;
        }
        
        int left = 0;
        int right = n-1;
        
        while(left < right)
        {
            int mid = (left+right)/2;
            int tmp = arr[mid]-mid-1;
            if(tmp < k)
            {
                left = mid+1;
            }
                
            else
            {
                right = mid;
            }
                
        }
        
        int ans = k+left;
        return ans;
    }
};