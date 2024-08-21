#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
const int N=2010;
struct Node
{
    int a,b,len;
    bool operator < (const Node &W) const
    {
        return len>W.len;
    }
};
priority_queue<Node>que;
int n,m,ans,p[N];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    for(int i=1;i<=2009;++i) p[i]=i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b,c,q;
        scanf("%d%d%d%d",&q,&a,&b,&c);
        if(q==1)
        {
            ans+=c;
            p[find(a)]=find(p[b]);
        }
        else que.push({a,b,c});
    }
    
    while(!que.empty())
    {
        auto out=que.top();
        que.pop();
        
        if(find(out.a)==find(out.b)) continue;
        p[find(out.a)]=find(out.b);
        ans+=out.len;
    }
    printf("%d",ans);
    return 0;
}