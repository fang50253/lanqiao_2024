#include<bits/stdc++.h>
using namespace std;
const int N=510;
long long n,m,f[N][N],step[N];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		long long a,b,l;
		scanf("%lld%lld%lld",&a,&b,&l);
		if(f[a][b]==0) f[a][b]=l;
		else f[a][b]=min(f[a][b],l);
	}
	memset(step,0x3f,sizeof step);
	step[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]!=0) step[j]=min(step[j],step[i]+f[i][j]);
		}
	}
	if(step[n]==0x3f) printf("-1");
	else printf("%d",step[n]);
	return 0;
}
