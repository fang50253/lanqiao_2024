#include<iostream>
using namespace std;
int main()
{
	int n,m,q,num[1010][1010],sum[1010][1010],tmp[1010][1010],x1,x2,y1,y2;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>num[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			tmp[i][j]=tmp[i][j-1]+num[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sum[i][j]=sum[i-1][j]+tmp[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		cout<<sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
	}
	return 0;
}
