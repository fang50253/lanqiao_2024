#include<iostream>
using namespace std;
const int N=1e6+10,mod=131;
int h[N],record[N],ne[N],idx=1;
int ha(int x)
{
	if(x>=0) return x%mod;
	else return (x%mod+mod)%mod;
}
void insert(int x)
{
	int tmp=ha(x);
	if(!h[tmp])
	{
		h[tmp]=idx;
		record[idx++]=x;
	}
	else
	{
		int p=h[tmp];
		while(ne[p]) p=ne[p];
		ne[p]=idx;
		record[idx++]=x;
	}
}
void query(int x)
{
	int tmp=ha(x);
	if(!h[tmp]) cout<<"No"<<endl;
	else
	{
		int p=h[tmp];
		do
		{
			if(record[p]==x)
			{
				cout<<"Yes"<<endl;
				return;
			}
			p=ne[p];
		}while(p);
		cout<<"No"<<endl;
	}
}
int main()
{
	int n,tmp;
	char op;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>op>>tmp;
		if(op=='I') insert(tmp);
		else if(op=='Q') query(tmp);
	}
	return 0;
}
