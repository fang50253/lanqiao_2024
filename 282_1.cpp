#include<iostream>
#include<cmath>
using namespace std;
const int N=310;
int f[N][N],d[N];//f[i][j]代表了从i到j所有合并方案的代价的最小值。
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i][i]);
	for(int i=1;i<=n;i++) f[i][i]/=2;
	for(int i=1;i<=n-1;i++)//i代表步长 
	{
		for(int j=1;i+j<=n;j++)
		{
			//f[j][j+i]=f[j][j+i-1]+f[j+i][j+i];
			int tmp=(f[j][j+i-1]+f[j+i][j+i]);
			for(int k=j;k<i+j;k++)
			{
				//f[j][j+i]=min(f[j][j+i],f[j][k]+f[k+1][j+i]);
				tmp=min(tmp,(f[j][k]+f[k+1][j+i]));
			}
			f[j][j+i]+=tmp*2;
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<f[1][n];
	return 0;
}
