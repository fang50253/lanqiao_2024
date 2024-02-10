#include<iostream>
using namespace std;
const int N=1e5+10;
int tree[N],idx;
void down(int x)
{
	int t=x;
	if(2*x<=idx&&tree[2*x]<tree[t]) t=x*2;
	if(2*x+1<=idx&&tree[2*x+1]<tree[t]) t=x*2+1;
	if(x!=t)
	{
		swap(tree[x],tree[t]);
		down(t);
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>tree[i];
	idx=n;
	for(int i=n/2;i;i--) down(i);
	while(m--)
	{
		cout<<tree[1]<<" ";
		tree[1]=tree[idx--];
		down(1);
	}
	return 0;
}
