#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <iostream>

#define SZ(x) ((int)(x.size()))
#define fi first
#define se second

using namespace std;
typedef long long lli;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;
typedef pair<int,int> pii;

int a[2][4],n;
char str[10];
char res[33][33]=
{
"..----..----..----..----..----..",
"..    ..    ..    ..    ..    ..",
"| \\                          / |",
"|  \\                        /  |",
"|   \\                      /   |",
"|    ..                  ..    |",
"..   ..                  ..   ..",
"..     \\                /     ..",
"|       \\              /       |",
"|        \\            /        |",
"|         ..        ..         |",
"|         ..        ..         |",
"..          \\      /          ..",
"..           \\    /           ..",
"|             \\  /             |",
"|              ..              |",
"|              ..              |",
"|             /  \\             |",
"..           /    \\           ..",
"..          /      \\          ..",
"|         ..        ..         |",
"|         ..        ..         |",
"|        /            \\        |",
"|       /              \\       |",
"..     /                \\     ..",
"..   ..                  ..   ..",
"|    ..                  ..    |",
"|   /                      \\   |",
"|  /                        \\  |",
"| /                          \\ |",
"..    ..    ..    ..    ..    ..",
"..----..----..----..----..----.."
};
int yy[101]=
{
	-1,24,18,12,6,0,0,0,0,0,0,
	6,12,18,24,30,30,30,30,30,30,
	0,0,0,0,0,0,0,0,0,0,
	5,10,15,20,25,30,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	5,10,15,20,25,30,0,0,0
};
int xx[101]=
{
	-1,30,30,30,30,30,24,18,12,6,0,
	0,0,0,0,0,6,12,18,24,30,
	0,0,0,0,0,0,0,0,0,30,
	25,20,15,10,5,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	5,10,15,20,25,30,0,0,0
};


int main()
{
	char p;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++) 
    {
		int t,pi,cnt=0;
		scanf(" %c %s",&p,str);
		for(int i=0;i<4;i++) if(str[i]=='F') cnt++;
		if(cnt==0) cnt=5;
		
		if(p>='A' && p<='D') 
        {
			t=0,pi=p-'A';
		} else {
			t=1; pi=p-'a';
		}
		
		int ci=a[t][pi],ni;
		if(ci==-1) continue;

		if(ci<=20 && ci+cnt>20) ni=-1;
		else if(ci<5 && ci+cnt==5) ni=30;
		else if(ci<10 && ci+cnt==10) ni=50;
		else if(ci<33 && ci+cnt==33) ni=53;
		else if(ci<36 && ci+cnt>=36) ni = 15+(ci+cnt-36);
		else if(ci<56 && ci+cnt>56) ni=-1;
		else if(ci<56 && ci+cnt==56) ni=20;
		else ni=ci+cnt;

		if(ci==0) a[t][pi] = ni;
		else 
        {
			for(int i=0;i<4;i++) if(a[t][i] == ci) a[t][i] = ni;
		}
		for(int i=0;i<4;i++) if(a[t^1][i] == ni) a[t^1][i] = 0;
	}
	
	for(int i=0;i<4;i++) 
    {
		if(a[0][i]>0) 
        {
			int y=yy[a[0][i]],x=xx[a[0][i]];
			if(i==1) x++;
			else if(i==2) y++;
			else if(i==3) x++,y++;
			res[y][x] = i+'A';
		}
	}
	for(int i=0;i<4;i++)
    {
		if(a[1][i]>0)
        {
			int y=yy[a[1][i]],x=xx[a[1][i]];
			if(i==1) x++;
			else if(i==2) y++;
			else if(i==3) x++,y++;
			res[y][x] = i+'a';
		}
	}

	for(int i=0;i<32;i++) printf("%s\n",res[i]);

	return 0;
}