#include<iostream>
using namespace std;
int num[1010][1010],n,m,q,x1,x2,y1,y2,c,cf[1010][1010];
void chafen(int x1,int y1,int x2,int y2,int c)
{
    cf[x1][y1]+=c;
	cf[x2+1][y1]-=c;
	cf[x1][y2+1]-=c;
	cf[x2+1][y2+1]+=c;
}
int main()
{
	//读入前缀和矩阵 
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cin>>num[i][j];
	}
	//拆分 
	//cf[1][1]=num[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            chafen(i,j,i,j,num[i][j]);
        }
    }
	for(int i=1;i<=q;i++)
	{
		cin>>x1>>y1>>x2>>y2>>c;
		chafen(x1,y1,x2,y2,c);
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
