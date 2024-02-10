#include<iostream>
#include<math.h>
#include<queue>
#include <cstring>
using namespace std;
const int N=1e6+10,M=2*N;
int e[M],ne[M],head[N],idx=1,min_step[N],n;
queue<int>a;
void insert(int a,int b)
{
	e[idx]=b;
	ne[idx]=head[a];
	head[a]=idx++;
}
void bfs()
{
	int u=a.front();
	//cout<<"out"<<u<<endl;
	a.pop();
	if(min_step[n]!=-1)
	{
		cout<<min_step[n];
		return;
	}
	for(int i=head[u];i!=-1;i=ne[i])
	{
		if(min_step[e[i]]==-1)
		{
			min_step[e[i]]=min_step[u]+1;
			a.push(e[i]);
		}
	 } 
	 if(a.empty())
	{
		cout<<"-1";
		return;
	}
	
	 bfs();
	 
}
void print()
{
    cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    cout<<min_step[i]<<" ";
    cout<<endl;
}
int main()
{
    memset(min_step,-1,sizeof min_step);
    memset(head,-1,sizeof head);
	int m,a1,b1;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a1>>b1;
		insert(a1,b1);
		//insert(b1,a1);
	}
	a.push(1);
	min_step[1]=0;
	bfs();
	//print();
	return 0;
}
