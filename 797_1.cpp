#include<iostream>
using namespace std;
int main()
{
	int n,m,num[100010],l,r,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>c;
		for(int j=l;j<=r;j++)
		{
			num[j]+=c;
		}
	}
	for(int i=1;i<=n;i++) cout<<num[i]<<" ";
	return 0;
 } 
