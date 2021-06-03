#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
int t, v, e;
vector<vector<int> > g;
int check[20001];
 
bool bfs(){
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if (check[i] == 0)
        {
            q.push(i);
            check[i] = 1;
 
            while (!q.empty())
            {
                int now = q.front();
                q.pop();
 
                for (int j = 0; j < g[now].size(); j++)
                {
                    if (check[g[now][j]] == 0)
                    {
                        q.push(g[now][j]);
                        check[g[now][j]] = ~check[now] + 1;
                    }
                    else if (check[now] + check[g[now][j]] != 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
 
int main(void){
    cin >> t;
    while (t--){
        cin >> v >> e;
        g = vector<vector<int> >(v + 1);
       
        fill(check, check + 20001, 0); 
        int a, b;
        for (int i = 0; i < e; i++){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
 
        if (bfs()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
