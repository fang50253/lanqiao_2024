#include<iostream>
using namespace std;
const int N=100010;
int n,num[N],tmp[N];
long long merge_sort(int l,int r)
{
	if(l>=r) return 0;
	int mid=(l+r)/2,i=l,j=mid+1,k=1;
	long long res=merge_sort(l,mid)+merge_sort(mid+1,r);
	while(i<=mid&&j<=r)
	{
		if(num[i]<=num[j]) tmp[k++]=num[i++];
		else
		{
			tmp[k++]=num[j++];
			res+=mid-i+1;
		}
	}
	while(i<=mid) tmp[k++]=num[i++];
	while(j<=r) tmp[k++]=num[j++];
	for(i=1,j=l;j<=r;i++,j++) num[j]=tmp[i];
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	cout<<merge_sort(1,n);
	return 0;
}
