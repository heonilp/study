#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <math.h>
 
using namespace std;
 
#define MAX_SIZE 100
#define INF 0x7fffffff
#define CENDL "\n"
#define ll long long
 
int main() {
 
    cin.tie(0);
    std::ios::sync_with_stdio(false);
 
    int n; cin >> n;
 
    int nextEat[3] = {0,1,2};
    
    int sol = 0;
    int index = 0;
    for(int i=0; i<n; i++) {
        int d; cin >> d;
        if (d == nextEat[index]) {
            sol++;
            if (index == 2) {
                index = 0;
            } else {
                index++;
            }
        }
    }
 
    cout << sol << CENDL;
 
    return 0;
}