#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N=6300;
const int INF=0x3f3f3f3f;
int h[N],w[2*N],ne[2*N],e[2*N],idx=1,dist[N];
struct Node
{
    int node,value;
    bool operator < (const Node &W) const
    {
        return value>W.value;
    }
};
priority_queue<Node>que;
bool state[N];
void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
int main()
{
    int n,k,st,ed;
    scanf("%d%d%d%d",&n,&k,&st,&ed);
    for(int i=1;i<=k;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }//使用邻接表创建一个无向图
    memset(dist,0x3f,sizeof dist);
    dist[st]=0;
    que.push({st,0});
    while(!que.empty())
    {
        auto out=que.top();
        que.pop();
        //if(state[out.node]) continue;
        state[out.node]=1;
        for(int i=h[out.node];i;i=ne[i])
        {
            dist[e[i]]=min(dist[out.node]+w[i],dist[e[i]]);
            if(!state[e[i]]) que.push({e[i],dist[e[i]]});
        }
    }
    printf("%d",dist[ed]);
    return 0;
}