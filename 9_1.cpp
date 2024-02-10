#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
const int N=110;
int n,m,p[N],s1,num[N],sum;
struct bag
{
	int v,w,s;
};
void print()
{
	for(int i=1;i<=sum;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	bag f[N][N];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		for(int j=1;j<=num[i];j++) cin>>f[i][j].v>>f[i][j].w;
		sum+=num[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=0,ls;
		for(int j=1;j<=num[i];j++)
		{
			tmp=max(tmp,p[j-f[i][j].v]+f[i][j].w);
			if(p[j-f[i][j].v]+f[i][j].w>tmp) ls=j;
		}
		p[ls]=tmp;
	}
	cout<<p[sum]<<endl;
	print();
	return 0;
 } 
