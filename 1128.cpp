#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N=410;
int w[N],h[N],e[N],ne[N],idx=1,cnt,dist[N];
const int INF=0x3f3f3f3f;
bool st[N];
struct Node
{
    int node,len;
    bool operator < (const Node &W) const 
    {
        return len>W.len;
    }
};
priority_queue<Node>que;
void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }//创建邻接表
    memset(dist,0x3f,sizeof dist);
    que.push({1,0});
    dist[1]=0;
    while(!que.empty())
    {
        auto out=que.top();
        que.pop();
        st[out.node]=1;
        for(int i=h[out.node];i;i=ne[i])
        {
            dist[e[i]]=min(dist[e[i]],dist[out.node]+w[i]);
            if(!st[e[i]]) que.push({e[i],dist[e[i]]});
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,dist[i]);
    if(ans==INF) printf("-1");
    else printf("%d",ans);
    return 0;
}