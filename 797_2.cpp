#include<iostream>
using namespace std;
int num[100010],n,m,l,r,c,cf[100010]; 
int main()
{
	//读入前缀和 
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    //计算差分 
	cf[1]=num[1];
    for(int i=2;i<=n+8;i++) cf[i]=num[i]-num[i-1];
    //插入差分值 
    for(int i=1;i<=m;i++)
    {
    	cin>>l>>r>>c;
    	cf[l]+=c;
    	cf[r+1]-=c;
	}
	//重新计算num数组
	for(int i=1;i<=n;i++) num[i]=num[i-1]+cf[i];
	for(int i=1;i<=n;i++) cout<<num[i]<<" ";
	return 0;
}
