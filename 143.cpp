#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
const int M=3000010;
int a[N],son[M][2],idx=0;
void insert(int x)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		if(son[p][x>>i&1]) p=son[p][x>>i&1];
		else
		{
			son[p][x>>i&1]=++idx;
			p=idx;
		}
	}
}
int query(int x)
{
	int p=0,res=0;
	for(int i=30;i>=0;i--)
	{
		if(son[p][!(x>>i&1)])
		{
			p=son[p][!(x>>i&1)];
			res+=1<<i;
		}
		else p=son[p][x>>i&1];
	}
	return res;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		insert(a[i]);
	}
	int res=0;
	for(int i=0;i<n;i++) res=max(res,query(a[i]));
	printf("%d\n",res);
	return 0;
}
