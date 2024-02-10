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
int quchong()
{
	int j=2;
	r[1]=x[1];
	s[1]=c[1];
	for(int i=2;i<=n;i++)
	{
		if(r[j-1]==x[i])
		    s[j-1]+=c[i]; 
		else
		{
			s[j]=c[i];
			r[j]=x[i];
			j++;
		}
	}
	return j-1;
}
int b_search(int t)
{
	int l=1,ri=n,mid;
	while(l<ri)
	{
		mid=l+ri+1>>1;
		if(r[mid]>t) ri=mid-1;
		else l=mid;
	}
	return ri;
}
int main()
{
	//首先读入数据 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i]>>c[i];
	//第二步，预处理，对原数组进行排序
	quick_sort(1,n);
	//第三步，计数 
	int l,ri,count=0;
    while(m--)
    {
    	count=0;
    	scanf("%d%d",&l,&r);
    	for(int i=b_search(l)-1;i<=b_search(ri)+1;i++)
		{
			if(r[i]>=l&&r[i]<=ri) count+=s[i];
		}
    	cout<<count<<endl;
	}
	return 0;
}
