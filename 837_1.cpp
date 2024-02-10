#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N],size_[N];
int find(int x)
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		size_[i]=1;
	}
	while(m--)
	{
		string read;int a,b;
		cin>>read;
		if(read=="C")
		{
			cin>>a>>b;
			a=find(a);b=find(b);
			if(a!=b)
			{
			    p[a]=b;
			    size_[b]+=size_[a];
			}
		}
		else if(read=="Q1")
		{
			cin>>a>>b;
		   	if(find(a)==find(b)) cout<<"Yes";
		    else cout<<"No";
		   	cout<<endl;
		}
		else if(read=="Q2")
	    {
		    cin>>a;
		    cout<<size_[find(a)]<<endl;
	   	}
	}
	return 0;
}
