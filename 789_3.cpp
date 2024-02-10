#include<iostream>
using namespace std;
int n,q,k,num[100010],ansl,ansr;
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<=q;i++)
	{
		cin>>k;
		int l=1,r=n;
		while(l<r)
		{
			int mid=l+r>>1;
			if(num[mid]>=k) r=mid;
			else l=mid+1;
		}
		ansl=l;
		l=1;r=n;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(num[mid]<=k) l=mid;
			else r=mid-1;
		}
		ansr=r;
		if(num[ansl]!=k)cout<<"-1 -1"<<endl;
		else cout<<ansl-1<<" "<<ansr-1<<endl;
	}
 } 
