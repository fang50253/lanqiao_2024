#include<iostream>
using namespace std;
const int N=1e5+10;
int n,num[N],j=1,ans=0;
bool check(int l,int r)
{
	bool tong[N]={0};
	for(int i=1;i<N;i++) tong[i]=0;
	bool res=0;
	for(int i=l;i<=r;i++)
	{
		if(tong[num[i]]) return 1;
		else tong[num[i]]=1;
	}
	//cout<<l<<"oops!"<<r;
	return 0;
}
int find(int x,int l)
{
	int tmp=l;
	while(1)
	{
		if(num[tmp]==x) return tmp;
		else tmp++;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	int i;
	for(i=1;i<=n;i++)
	{
		if(!check(j,i)) ans=max(ans,i-j+1);
		else j=find(num[i],j)+1;
	}
	cout<<ans;
	return 0;
}
