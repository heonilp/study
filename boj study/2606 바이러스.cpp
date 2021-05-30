#include<stdio.h>
#include<queue>

using namespace std;

int nc; //컴퓨터의 수
int cp; //연결된 컴퓨터의 쌍 수 
int vct[101][101]; //연결된 컴퓨터들 
bool c[101]; //컴퓨터의 방문 여부 
int cnt=0;
queue <int> q;

void infect(){
	
	 
	int x;
	q.push(1); //1번 컴퓨터를 큐에 넣고 
	c[1]=true; //방문처리 해준다 
	
	while(!q.empty())
	{
		x=q.front();
		q.pop(); 
		
		for (int j=0; j<=nc; j++)
		{
			if (vct[x][j]==1 &&vct[j][x]==1 && !c[j]) //큐에서 꺼낸 것과 연결되어 있고 아직 방문하지 않은 컴퓨터 
			{
				c[j]=true; //방문처리 해주고  
				q.push(j);cnt++; //그 컴퓨터를 큐에 넣고 카운트 해준다 
				//printf("PUSHED %d, cnt=%d\n",j,cnt);
				
			}
		}
	}
} 

int main (void)
{
	scanf("%d",&nc);
	scanf("%d",&cp);
	int x,y; 
	for(int i=0; i<cp; i++)
	{
		scanf("%d %d",&x,&y);
		vct[x][y]=1; 
		vct[y][x]=1;
		
	}
	
	infect();
	
	printf("%d\n",cnt);
    return 0;
}