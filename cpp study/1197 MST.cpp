/*
최소 스패닝 트리(Minimum Spanning Tree, MST)란?
최소 스패닝 트리의 정의는 그래프에서 그래프의 모든 정점을 연결하되, 
사이클이 존재하지 않도록 모든 정점을 간선으로 연결하는 것을 의미한다. 
이때, 간선의 가중치 합을 최소로 하며 연결하여야 한다.
이때 생성되는 최소 스패닝 트리는 무조건 하나의 그래프에서 하나만 생성된다고는 보장하지 못한다.
EX_ 크루스칼, 프림 알고리즘
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef struct kruskal 
{
    int from;
    int to;
    int val;
}KS;
 
vector<KS> edge;
 
int chk[10002];
int res;
 
bool comp(KS d1, KS d2)
{
    return d1.val < d2.val;
}
 //유니온파인트
int getfind(int num)
{
    if (num == chk[num])
        return num;
 
    return chk[num] = getfind(chk[num]);
}
int main()
{
    int V, E;
 
    scanf("%d %d", &V, &E);
 
    for (int i = 1; i <= V; i++)
        chk[i] = i;
 
    // 그래프 형성
    for (int i = 0; i < E; i++)
    {
        KS ks;
        scanf("%d %d %d", &ks.from, &ks.to, &ks.val);
        edge.push_back(ks);
    }
 
    // 크루스칼 알고리즘에 의해 간선을 오름차순 정렬
    sort(edge.begin(), edge.end(), comp);
 
    // 유니온 파인드의 유니온 방식
    for (int i = 0; i < E; i++)
    {
        int nv = getfind(edge[i].from);
        int nw = getfind(edge[i].to);
 
        if (nv == nw)
            continue;
 
        chk[nv] = nw;
 
        res += edge[i].val;
    }
 
    printf("%d\n", res);
 
    return 0;
}