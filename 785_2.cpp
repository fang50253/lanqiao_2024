#include<bits/stdc++.h>
using namespace std;
int num[100010]={0}; 
int n;
void quick_sort(int l,int r)
{

	if(l>=r)return;
	int i=l-1,j=r+1;
	int x=(num[l]+num[r])/2;
	while(i<j)
	{
		do i++;while(num[i]<x);
	    do j--;while(num[j]>x);
	    if(i<j) swap(num[i],num[j]);
	}
	quick_sort(j+1,r);
	quick_sort(l,i-1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	quick_sort(1,n);
	for(int i=1;i<=n;i++) cout<<num[i]<<" ";
	return 0;
}
