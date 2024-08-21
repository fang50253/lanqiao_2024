#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
const int N=2e5+10;
int idx=1,ne[N],e[N],h[N],n,m,st,ed;
double dist[N],w[N];
bool state[N];
struct Node
{
    int node;
    double len;
    bool operator < (const Node &W) const 
    {
        return len<W.len;
    }
};
void add(int a,int b,int c)
{
    w[idx]=(100-c)/100.0;
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void out_dist()
{
    for(int i=1;i<=3;++i)
    printf("%lf ",dist[i]);
}
int main()
{
    memset(dist,0x3f,sizeof dist);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    scanf("%d%d",&st,&ed);
    dist[st]=1.0;
    priority_queue<Node>que;
    state[st]=1;
    que.push({st,1.0});
    while(!que.empty())
    {
        auto out=que.top();
        que.pop();
        for(int i=h[out.node];i;i=ne[i])
        {
            if(dist[e[i]]<dist[out.node]*w[i])
                dist[e[i]]=dist[out.node]*w[i];
                //cout<<dist[out]*(100-w[i])/100<<endl;
            if(!state[e[i]])
            {
                que.push({e[i],dist[e[i]]});
                state[e[i]]=1;
            }
        }
    }
    printf("%.8lf\n",100.0/dist[ed]);
    //out_dist();
    return 0;
}