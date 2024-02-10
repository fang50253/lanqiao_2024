#include<iostream>
using namespace std;
const int N=1e3+10;
int a[N],n,t[N];
int dp(int x)
{
	int ans=0;
	for(int i=1;i<x;i++) if(t[i]+1>ans&&a[i]<a[x]) ans=t[i]+1;
	return ans;
}
int tm()
{
	int ans=0;
	for(int i=1;i<=n;i++) if(t[i]>ans) ans=t[i];
	return ans+1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) t[i]=dp(i);
	cout<<tm();
	return 0;
}
