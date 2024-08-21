//一定程度上这题我是抄了yxc的答案，因为我用邻接表和邻接矩阵写了两遍，都是过了9个点，然后有最后2个点都不过，也不知道是什么原因。
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
const int N=2010;
int n,m;
double w[N][N],dist[N];
bool st[N];
int main()
{
    scanf("%d%d",&n,&m);
    memset(w,0,sizeof w);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        w[a][b]=w[b][a]=max(w[a][b],(100-c)/100.0);
    }
    int start;
    scanf("%d",&start);
    dist[start]=1;
    for (int i = 1; i <= n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] < dist[j]))
                t = j;
        st[t] = true;
        for (int j = 1; j <= n; j ++ )
            dist[j] = max(dist[j], dist[t] * w[t][j]);
    }
    int ed;
    scanf("%d",&ed);
    printf("%.8lf",100.0/dist[ed]);
    return 0;
}