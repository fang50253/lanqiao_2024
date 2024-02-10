#include<iostream>
using namespace std;
int num[1010][1010],n,m,q,x1,x2,y1,y2,c,cf[1010][1010];
int main()
{
	//读入前缀和矩阵 
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cin>>num[i][j];
	}
	//拆分 
	cf[1][1]=num[1][1];
	for(int i=2;i<=n;i++) cf[i][1]=num[i][1]-num[i-1][1];
	for(int i=2;i<=m;i++) cf[1][i]=num[1][i]-num[1][i-1];
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++) cf[i][j]=num[i][j]-num[i-1][j]-num[i][j-1]+num[i-1][j-1]; 
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x1>>y1>>x2>>y2>>c;
		cf[x1][y1]+=c;
		cf[x2+1][y1]-=c;
		cf[x1][y2+1]-=c;
		cf[x2+1][y2+1]+=c;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++) cf[i][j]+=cf[i][j-1];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cf[i][j]+=cf[i-1][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cout<<cf[i][j]<<" ";
		cout<<endl;
	}
}
