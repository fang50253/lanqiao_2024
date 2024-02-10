#include<iostream>
using namespace std;
const int N=1e5+10,M=2*N;
int e[M],ne[M],h[N],idx=1;
bool al[N];
void add(int a,int b)
{
	if(h[a])
	{
		int p=h[a];
		do
		{
			p=ne[p];
		}while(p);
		ne[p]=idx;
		e[idx]=b;
		idx++;
		p=h[b];
		do
		{
			p=ne[p]
		}while(p);
		ne[p]=idx;
		e[idx]=a;
		idx++;
	}
	else
	{
		h[a]=idx;
		e[idx]=b;
		idx++;
		h[b]=idx;
		e[idx]=a;
		idx++;
	}
}
int main()
{
	
}
