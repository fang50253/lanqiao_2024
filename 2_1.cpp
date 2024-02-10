#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
const int N=1010;
int v[N],w[N],f[N][N];
int main()
{
	int n,V;
	cin>>n>>V;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=V;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=v[i]) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
		}
	}
	cout<<f[n][V];
	return 0; 
}
