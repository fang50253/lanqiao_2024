#include<iostream>
using namespace std;
int dt[2010][2010];
const int N=1e9+7;
int main()
{
	dt[1][1]=1;
	for(int i=0;i<=2000;i++) dt[i][0]=1;
	for(int i=1;i<=2000;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dt[i][j]=(dt[i-1][j-1]+dt[i-1][j])%N;
		}
	}
	int n,a,b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		cout<<dt[a][b]<<endl;
	}
	return 0;
 } 
