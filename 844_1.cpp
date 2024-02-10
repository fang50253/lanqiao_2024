#include<iostream>
using namespace std;
int tu[110][110]={0},n,m,head=1,tail=1,min_[110][110]={0},que[3][N];
const int N=1e4+10;
bool in_pic(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m) return 1;
	else return 0;
}
bool if_0(int x,int y)
{
	if(min_[x][y]==0&&in_pic(x,y)&&!tu[x][y]) return 1;
	else return 0;
}
void bfs()
{
	int x=que[1][head],y=que[2][head];
	if(x==n&&y==m) return;
	head++;
	const int tx[4]={0,0,1,-1},ty[4]={1,-1,0,0};
	for(int i=0;i<4;i++)
	{
		if(if_0(x+tx[i],y+ty[i]))
		{
			min_[x+tx[i]][y+ty[i]]=min_[x][y]+1;
			que[1][tail+1]=x+tx[i];
			que[2][tail+1]=y+ty[i];
			tail++;
		}
	}
	bfs();
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>tu[i][j];
	que[1][1]=1;
	que[2][1]=1;
	min_[1][1]=1;
    bfs();
    cout<<min_[n][m]-1;
	return 0;
}
