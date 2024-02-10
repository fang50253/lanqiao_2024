#include<iostream>
using namespace std;
int n,num[100010]={0},tmp[100010]={0};
void print()
{
	for(int i=1;i<=n;i++)
	{
		cout<<num[i]<<" ";
	}
}
void merge_sort(int l,int r)
{
	print();cout<<endl;
	if(l>=r) return;
	int mid=(l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int k=0,i=l-1,j=mid;
	while(i<mid&&j<r)
	{
		if(num[i]<num[j])
		{
			tmp[k++]=num[i++];
		}
		else
		{
			tmp[k++]=num[j++];
		}
	}
	for(;i<=mid;)
	{
		tmp[k++]=num[i++];
	}
	for(;j<=r;)
	{
		tmp[k++]=num[j++];
	}
	for(int m=1;m<=k-1;m++)
	{
		num[l+m-1]=tmp[m];
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	merge_sort(1,n);
	print();
	return 0;
 } 
