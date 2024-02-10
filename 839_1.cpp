#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+10;
int p[N],idx;
void up(int u)
{
	int t,tmp;
	if(u==1||u==2) return;
	if(t%2==1) t=(u-1)/2;
	else t=u/2;
	tmp=t;
	if(p[t]>p[2*t]&&2*t<=idx) tmp=2*t;
	if(p[tmp]>p[2*t+1]&&2*t+1<=idx) tmp=2*t+1;
	swap(p[t],p[tmp]);
	up(t);
}
void down(int u)
{
	int t=u;
	if(p[t*2]<p[t]&&2*t<=idx) t=2*t;
	if(p[u*2+1]<p[t]&&2*t+1<=idx) t=2*t+1; 
	if(t!=u)
	{
		swap(p[t],p[u]);
	    down(t);
	}
}
void insert(int x)
{
	p[++idx]=x;
	up(idx);
}
void print_min()
{
	printf("%d",p[1]);
}
void delete_min()
{
	p[1]=p[idx--];
	down(1);
}
void print()
{
	for(int i=1;i<=idx;i++) cout<<p[i]<<" ";
}
int main()
{
	insert(1);insert(4);insert(3);insert(2);down(2);
	print();
}
