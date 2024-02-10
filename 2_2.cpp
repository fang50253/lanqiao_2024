#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
const int N=1010;
int v[N],w[N],f[N];
int main()
{
	int n,V;
	cin>>n>>V;
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=V;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	cout<<f[V];
	return 0; 
}
