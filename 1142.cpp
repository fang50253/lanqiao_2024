#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
const int N=310;
const int MAX=1e4+10;
struct Node
{
    int a,b,len;
    bool operator < (const Node &W) const
    {
        return len>W.len;
    }
};
priority_queue<Node>que;
int n,m,p[MAX],cnt;
bool st[N];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    for(int i=1;i<=1e4;++i) p[i]=i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        que.push({a,b,c});
    }
    int last;
    while(!que.empty())
    {
        auto out=que.top();
        que.pop();
        if(find(out.a)==find(out.b)) continue;
        p[find(out.a)]=find(out.b);
        ++cnt;
        last=out.len;
        //cout<<last<<endl;
    }
    printf("%d %d",cnt,last);
    return 0;
}