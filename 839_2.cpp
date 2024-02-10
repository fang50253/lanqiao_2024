#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
using namespace std;
const int N=1e5+10;
int heap[N],hp[N],ph[N],size_;
void heap_swap(int a,int b)
{
	swap(ph[hp[a]],ph[hp[b]]);
	swap(hp[a],hp[b]);
	swap(heap[a],heap[b]);
}
void down(int u)
{
	int t=u;
	if(heap[t]>heap[2*u]&&2*u<=size_) t=2*t;
	if(heap[t]>heap[2*u+1]&&2*u+1<=size_) t=2*u+1;
	if(t!=u)
	{
		heap_swap(u,t);
		down(t);
	}
}
void  up(int u)
{
	while(u/2&&heap[u]<heap[u/2])
	{
		heap_swap(u,u/2);
		u/=2;
	}
}
void insert(int x)
{
	heap[++size_]=x;
	ph[size_]=size_;
	up(size_);
}
int main()
{
	char op[10];
	int n,in;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>op;
		if(!strcmp(op,"I"))
		{
			cin>>in;
			insert(in);
		}
		else if(!strcmp(op,"PM"))
		{
			cout<<heap[1]<<endl;
		}
		else if (!strcmp(op,"DM"))
		{
			heap_swap(1,size_--);
			down(1);
		}
		else if(!strcmp(op,"D"))
		{
			cin>>in;
			in=ph[in];
		    heap_swap(size_--,in);
		    up(in);down(in);
		}
		else
		{
			int in2;
		     cin>>in>>in2;
		     in=ph[in];heap[in]=in2;
             up(in);
		     down(in2);	
		}
	}
	return 0;
}
