#include<iostream>
#include<math.h>
using namespace std;
const int N=1010;
int v[N],w[N],f[N][N];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=v[i])
			{
				for(int k=1;k*v[i]<=j;k++)
				{
					f[i][j]=max(f[i-1][j-v[i]*k]+k*w[i],f[i][j]);
				}
			}
		}
	}
	cout<<f[n][m];
	return 0;
}
