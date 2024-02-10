#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
bool sc[11]={0};
int n,pr[11];
int jue(int x)
{
	if(x>=0) return x;
	else return -x;
}
void map_out()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(pr[i]==j) cout<<"Q";
			else cout<<".";
		}
		cout<<endl;
	}
	cout<<endl;
}
void out()
{
	bool he[20]={0},cha[20]={0};
	for(int i=1;i<=n;i++)
	{
		if(he[i+pr[i]]) return;
		else
		{
			he[i+pr[i]]=1;
		}
		if(cha[i-pr[i]+10]) return;
		else
		{
			cha[i-pr[i]+10]=1;
		}
	}
	map_out();
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
