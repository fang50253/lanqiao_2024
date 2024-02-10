#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
const int N=110;
int v[N],w[N],f[N][N],s[N];
int main()
{
	int n,V;
	cin>>n>>V;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=V;j++)
		{
			for(int k=0;k*v[i]<=j&&k<=s[i];k++)
			{
				f[i][j]=max(f[i-1][j-k*v[i]]+w[i]*k,f[i][j]);
			}
		}
	}
	cout<<f[n][V];
	return 0; 
}
