#include<iostream>
#include<cmath>
using namespace std;
const int N=310;
int f[N][N],s[N],n;
//f[i][j]代表了从i到j所有合并方案的代价的最小值。
//s[i]是前缀和
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	for(int i=2;i<=n;i++) s[i]+=s[i-1];
	for(int len=2;len<=n;len++)//len代表着步长
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			f[i][j]=1e8;
			for(int k=i;k<=i+len-1;k++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
			}
		}
	 } 
	 cout<<f[1][n];
	 return 0;
 } 
