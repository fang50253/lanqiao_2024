#include<bits/stdc++.h>
using namespace std;
const int N=510;
int f[N][N],n,m,dis[N],st[N];
int main()
{
	//读入数据 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		if(f[a][b]==0) f[a][b]=l;
		else f[a][b]=min(f[a][b],l);
	}
	//初始化distance数组
	memset(st,0,sizeof st);
	dis[1]=0;
	for(int i=2;i<=n;i++) dis[i]=0x3f3f3f3f;
	for(int j=1;j<=n;j++)
	{
		int s_value=0x3f3f3f3f,s_place;
		for(int i=1;i<=n;i++)
		{
			if(!st[i]&&dis[i]<s_value)
			{
				s_value=dis[i];
				s_place=i;
			}
		}
		st[s_place]=1;
		bool b=1;
		for(int i=1;i<=n;i++) 
        {
        	//if(i==s_place) continue;
        	if(f[s_place][i]) dis[i]=min(dis[i],s_value+f[s_place][i]);
		}
	}
	if(dis[n]!=0x3f3f3f3f) printf("%d",dis[n]);
	else printf("-1");
	return 0;
}
