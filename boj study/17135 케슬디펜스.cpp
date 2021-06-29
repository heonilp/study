#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
 
struct str{
    int y;
    int x;
    str(int y,int x): y(y),x(x){};
};
 
int N,M,D;
int ans=0;
vector<str> archor; //궁수 위치
vector<vector<int>> map; //격자판
 
void solve(){
    
    vector<vector<int>> tmp_map=map;
    vector<str> tmp_archor=archor;
    vector<vector<int>> visit(N+1,vector<int> (M,0)); //적 발견시 이전에 발견 유무
    
    int cnt=0;
    for(int i=0;i<N;i++){
        
        queue<pair<int,int>> q;
        for(int j=0;j<3;j++){
            
            bool check=false;
            for(int distance=1;distance<=D;distance++){
                
                int dy=-1;
                int dx=(distance-1)*(-1);
                
                for(int k=1;k<2*distance;k++){
                    
                    int ny=tmp_archor[j].y+dy;
                    int nx=tmp_archor[j].x+dx;
                    
                    //y,x좌표 갱신
                    dy=(k>=distance)? dy+1:dy-1;
                    dx+=1;
                    
                    if(ny<0 || nx<0 || nx>=M)
                        continue;
                    
                    //적 발견시
                    if(tmp_map[ny][nx]==1){
                        
                        //동시에 맞힌 적은 1명만 잡도록 하기 위해
                        if(visit[ny][nx]==0){
                            cnt++;
                            visit[ny][nx]=1;
                            q.push(make_pair(ny,nx));
 
                        }
                        
                        check=true;
                        break;
                    }
                    
                }
                if(check)
                    break;
            }
            
            tmp_archor[j].y--; // 궁수 y좌표 위로
        }
        
        //잡은 적 0으로 갱신
        while(!q.empty()){
            int ny=q.front().first;
            int nx=q.front().second;
            q.pop();
            
            tmp_map[ny][nx]=0;
        }
        
    }
    
    ans=max(ans,cnt);
}
 
void dfs(int location_x,int cnt){
    if(cnt==3){
        solve();
        return;
    }
    
    //나머지 모두 궁수 배치해도 3명 안되거나 범위 넘을때
    if(location_x>=M || cnt+(M-location_x)<3)
        return;
    
    archor.push_back(str(N,location_x));
    dfs(location_x+1,cnt+1);
    
    archor.pop_back();
    dfs(location_x+1,cnt);
}
 
int main() {
    
    cin>>N>>M>>D;
    
    map=vector<vector<int>> (N+1,vector<int> (M,0));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>map[i][j];
    
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}