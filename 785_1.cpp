#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l=0,r=1,n,max_num=0;
	cin>>n;
	int num[100010];
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		if(num[i]>max_num) max_num=num[i];
	}
	int tmp;
	for(int i=1;i<=n;i++)
	{
		l=1;r=n;
		for(;num[l]<(num[l]+num[r])/2;l++){}
	    for(;num[r]>(num[l]+num[r])/2;r--){}
	    if(l!=r)
	    {
	    	tmp=num[l];
	        num[l]=num[r];
	        num[r]=tmp;
		}
	}
	for(int i=1;i<=n;i++) cout<<num[i]<<" ";
	return 0;
 } 
