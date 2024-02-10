#include<iostream>
#include<math.h>
using namespace std;
const int N=1e5+10,M=2*N;
int e[M],ne[M],idx=1,first[N],n,ans=0x3f3f3f;
bool visit[N];
void insert(int a,int b)
{
	if(first[a])
	{
		int p=first[a];
		do
		{
			p=ne[p];
		}while(p);
		ne[p]=idx;
		e[idx]=b;
	}
	else
	{
		first[a]=idx;
		e[idx]=b;
	}
	idx++;
}
/*int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}*/
int dfs(int u)
{
	visit[u]=1;
	int sum=1,s,size=0;
	for(int i=first[u];i;i=ne[i])
	{
		if(!visit[e[i]])
		{
			s=dfs(e[i]);
			sum+=s;
			size=max(size,s);
		}
	}
	ans=min(ans,max(size,n-sum));
	//visit[u]=0;
	return sum;
}
int main()
{
	int a,b;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		insert(a,b);
		insert(b,a);
	}
	dfs(1);
	cout<<ceil(1.0*ans/2);
	return 0;
 } 
