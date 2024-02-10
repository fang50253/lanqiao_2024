#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const int N=1e5+10;
int x[N],c[N],r[N],s[N];
int n,m;
void quick_sort(int l,int r)
{
	if(l>=r) return;
	int mid=(x[l]+x[r])/2;
	int i=l-1,j=r+1;
	while(i<j)
	{
		do i++;while(x[i]<mid);
		do j--;while(x[j]>mid);
		if(i<j)
		{
			swap(x[i],x[j]);
			swap(c[i],c[j]);
		}
	}
	quick_sort(l,i-1);
	quick_sort(j+1,r);
}
int b_search(int t)
{
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(x[mid]>t) r=mid-1;
		else l=mid;
	}
	return r;
}
int main()
{
	//首先读入数据 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i]>>c[i];
	//第二步，预处理，对原数组进行排序
	quick_sort(1,n);
	//第三步，计数 
	int l,r,count=0;
    while(m--)
    {
    	count=0;
    	scanf("%d%d",&l,&r);
    	for(int i=b_search(l)-1;i<=b_search(r)+1;i++)
		{
			if(x[i]>=l&&x[i]<=r) count+=c[i];
		}
    	cout<<count<<endl;
	}
	return 0;
}
