#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;
int head=1,tail=1;
void bfs()
{
	if(rec.count('12345678x')) return;
	char ph[3][3];
	string last=a.back();
	a.pop();
	auto wz=last.find('x');
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		    ph[i][j]=last[3*i+j];
	
}
int main()
{
	string start;
	cin>>start;
	queue<string>a;
	unordered_map<string,int>rec; 
	a.push(start);
	bfs();
	return 0;
}
