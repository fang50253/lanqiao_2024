#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;
queue<string>a;
unordered_map<string,int>d;
bool in_map(int x,int y)
{
	if(x>=0&&x<=2&&y>=0&&y<=2) return 1;
	else return 0;
}
void bfs()
{
	if(d.count("12345678x")) return;
	char cz[3][3];
	string if_swap,bai;
	if(a.empty())
	{
		cout<<"-1";
		return;
	}
	string read=a.front();
	//cout<<endl<<"read="<<read<<endl;
	a.pop();
	for(int i=0;i<9;i++) cz[i/3][i%3]=read[i];
	int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
	for(int i=0;i<4;i++)
	{
		int x=read.find("x")/3+dx[i],y=read.find("x")%3+dy[i];
		if(in_map(x,y))
		{
			if_swap=bai;
			swap(cz[read.find("x")/3][read.find("x")%3],cz[x][y]);
			for(int i=0;i<9;i++) if_swap+=cz[i/3][i%3];
			swap(cz[read.find("x")/3][read.find("x")%3],cz[x][y]);
			if(!d.count(if_swap))
			{
				a.push(if_swap);
				d[if_swap]=d[read]+1;
				//cout<<if_swap<<" "<<d[if_swap]<<" "<<a.size()<<endl;
			}
		}
	}
	bfs();
}
int main()
{
	string start;
	char sr;
	for(int i=0;i<9;i++)
	{
		cin>>sr;
		start+=sr;
	}
	d[start]=0;
	a.push(start);
    bfs();
    if(d["12345678x"]!=0) cout<<d["12345678x"];
    if(start=="12345678x") cout<<0;
	return 0;
}
