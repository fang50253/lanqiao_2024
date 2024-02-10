#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N];
int find(int x)
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	while(m--)
	{
		char read;
		int a,b;
		cin>>read>>a>>b;
		if(read=='M') p[find(a)]=find(b);
		else if(read=='Q')
		{
			if(find(p[a])==find(p[b])) cout<<"Yes";
			else cout<<"No";
			cout<<endl;
		}
	}
	return 0;
	
}
