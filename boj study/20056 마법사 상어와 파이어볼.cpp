#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,M,K;
const int dy[8]={-1,-1,0,1,1,1,0,-1};
const int dx[8]={0,1,1,1,0,-1,-1,-1};

struct Fireball{
	int r,c,m,s,d;
	Fireball(int r,int c,int m,int s,int d):r(r),c(c),m(m),s(s),d(d){}
};

vector<Fireball> board[50][50];

Fireball move(Fireball f){
	for(int i=0;i<f.s;i++){
		f.r += dy[f.d];
		if(f.r==N) f.r=0;
		else if(f.r==-1) f.r=N-1;

		f.c += dx[f.d];
		if(f.c==N) f.c=0;
		else if(f.c==-1) f.c=N-1;
	}
	return f;
}

void moveFireballs(){
	vector<Fireball> newBoard[50][50];

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(Fireball f:board[i][j]){
				Fireball next = move(f);
				newBoard[next.r][next.c].push_back(next);
			}
		}
	}

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			board[i][j]=newBoard[i][j];
}

void unionFireballs(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j].size()<2) continue;

			int totN=board[i][j].size();
			int totM=0, totS=0, chk=0;

			for(Fireball f:board[i][j]){
				totM += f.m;
				totS += f.s;
				if(f.d%2==0) ++chk;
				else --chk;
			}

			board[i][j].clear();

			if(totM/5==0) continue;

			for(int k=0;k<4;k++){
				if(abs(chk)==totN)
					board[i][j].push_back(Fireball(i,j,totM/5,totS/totN,k*2));
				else
					board[i][j].push_back(Fireball(i,j,totM/5,totS/totN,k*2+1));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M>>K;

	for(int i=0;i<M;i++){
		int r,c,m,s,d;
		cin>>r>>c>>m>>s>>d;
		board[r-1][c-1].push_back(Fireball(r-1,c-1,m,s,d));
	}

	while(K--){
		moveFireballs();
		unionFireballs();
	}

	int ans=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(Fireball f:board[i][j])
				ans+=f.m;

	cout<<ans;

	return 0;
}