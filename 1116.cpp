#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
const int N=30;
bool tt[N][N];
int m,n,cnt;
const int dx[]={1,1,-1,-1,2,2,-2,-2};
const int dy[]={2,-2,2,-2,1,-1,1,-1};
struct Node
{
    int x,y;
};
bool check()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(tt[i][j]==0) return 0;
    return 1;
}
bool in_map(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<m) return 1;
    else return 0;
}
void dfs(int x,int y)
{
    if(check())
    {
        ++cnt;
        return;
    }
    for(int i=0;i<8;++i)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(in_map(xx,yy)&&tt[xx][yy]==0)
        {
            tt[xx][yy]=1;
            dfs(xx,yy);
            tt[xx][yy]=0;
        }
    }
}
int fun(int stx,int sty)
{
    cnt=0;
    memset(tt,0,sizeof tt);
    tt[stx][sty]=1;
    dfs(stx,sty);
    return cnt;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int stx,sty;
        scanf("%d%d%d%d",&n,&m,&stx,&sty);
        printf("%d\n",fun(stx,sty));
    }
    return 0;
}