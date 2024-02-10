#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
bool sc[11]={0};
int n,pr[11];
void out()
{
	for(int i=1;i<=n;i++) cout<<pr[i]<<" ";
	cout<<endl;
}
void dfs(int x)
{
	if(x==n+1) out();
	for(int i=1;i<=n;i++)
	{
		if(!sc[i])
		{
			sc[i]=1;
			pr[x]=i;
			dfs(x+1);
			pr[x]=0;	
			sc[i]=0;
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
