#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=3010;
int e[N],ne[N],w[N],h[N],idx=1,n,p,c,st[N],dist[N],ans=INF;
//bool al[N];
struct Node
{
    int node,len;
    bool operator < (const Node &W) const
    {
        return len>W.len;
    }
};
void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    w[idx++]=c;
}
void fun(int x)
{
    //memset(al,0,sizeof al);
    memset(dist,0x3f,sizeof dist);
    dist[x]=0;
    priority_queue<Node>que;
    que.push({x,0});
    //al[x]=1;
    while(!que.empty())
    {
        auto out=que.top();
        que.pop();
        //al[out.node]=0;
        for(int i=h[out.node];i;i=ne[i])
        {
            if(dist[out.node]+w[i]<dist[e[i]])
            {
                dist[e[i]]=dist[out.node]+w[i];
                //if(al[e[i]]==0)
                //{
                    que.push({e[i],dist[e[i]]});
                    //al[e[i]]=1;
                //}
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;++i)
    {
        if(dist[st[i]]>INF/2) return;
        else res+=dist[st[i]];
        //printf("%d:res=%d\n",st[i],dist[st[i]]);
    }
    ans=min(ans,res);
    //printf("st=%d ans=%d\n",x,ans);
}
int main()
{
    scanf("%d%d%d",&n,&p,&c);
    for(int i=1;i<=n;++i) scanf("%d",&st[i]);
    for(int i=1;i<=c;++i)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w);
        add(b,a,w);
    }
    for(int i=1;i<=p;++i) fun(i);
    printf("%lld",ans);
    return 0;
}