#include<iostream>
using namespace std;
int main()
{
	int n,m,l,r,num[100010]={0},sum[100010]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+num[i];
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<endl;
	}
}
