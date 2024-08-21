#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
const int N=110;
struct Node
{
    int x,y,len;
    bool operator < (const Node &W) const
    {
        return len>W.len;
    }
};
priority_queue<Node>que;
int n,qu[N],k;//qu是一个并查集
void ini()
{
    for(int i=1;i<=100;++i) qu[i]=i;
}
int find(int x)
{
    if(qu[x]!=x) qu[x]=find(qu[x]);
    return qu[x];
}
int main()
{
    ini();
    scanf("%d%d",&n,&k);
    int cnt=0;
    for(int i=1;i<=k;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        que.push({a,b,c});
        que.push({b,a,c});
        cnt+=c;
    }
    int ans=0;
    while(!que.empty())
    {
        auto out=que.top();
        que.pop();
        if(find(out.x)==find(out.y)) continue;
        qu[find(out.y)]=out.x;
        ans+=out.len;
        //cout<<"lianjie:"<<out.x<<" "<<out.y<<endl;
        //cout<<"find"<<find(out.x)<<" "<<find(out.y)<<endl;
    }
    printf("%d",cnt-ans);
    return 0;
}