#include<iostream>
using namespace std;
int prime(int x,int y)
{
	int tmp=1;
	for(int i=2;i<=min(x,y);i++)
	{
		while(x%i==0&&y%i==0&&i<=min(x,y))
		{
			tmp*=i;
			x/=i;y/=i;
		}
		if(x==1||y==1) break;
	}
	return tmp;
}
int main()
{
	int n,x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		cout<<prime(min(x,y),max(x,y)%min(x,y))<<endl;
	}
	return 0;
}
