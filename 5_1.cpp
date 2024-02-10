#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<math.h>
using namespace std;
const int N=12010;
int f[N],p[N],idx;
struct bag
{
	int v,w,s;
};
void print()
{
	for(int i=1;i<=idx-1;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	bag f[N];
	int n,m;
	cin>>n>>m;
	idx=n+1;
	for(int i=1;i<=n;i++) cin>>f[i].v>>f[i].w>>f[i].s;
	//Ô¤´¦Àí
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=f[i].s;j*=2)
	    {
	    	f[idx].v=f[i].v*j;
	    	f[idx].w=f[i].w*j;
		    f[i].s-=j;
		    idx++;
	    }
	    if(f[i].s>0)
	    {
	    	f[i].v=f[i].v*f[i].s;
	    	f[i].w=f[i].w*f[i].s;
		}
		else
		{
			f[i].v=0;
			f[i].w=0;
		}
	}
	//01±³°ü 
	memset(p,0,sizeof p);
	for(int i=1;i<=idx-1;i++)
	{
		for(int j=m;j>=f[i].v;j--)
		{
			p[j]=max(p[j-f[i].v]+f[i].w,p[j]);
		}
	}
	cout<<p[m]<<endl;
	//print();
	return 0;
}
