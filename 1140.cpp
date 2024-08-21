#include<bits/stdc++.h>
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
int n,qu[N];//qu是一个并查集
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
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int input;
            scanf("%d",&input);
            que.push({i,j,input});
        }
    }
    int ans=0;
    while(!que.empty())
    {
        auto out=que.top();
        que.pop();
        if(find(out.x)==find(out.y)) continue;
        qu[find(out.y)]=out.x;
        ans+=out.len;
    }
    printf("%d",ans);
    return 0;
}