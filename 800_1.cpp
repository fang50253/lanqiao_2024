#include<iostream>
using namespace std;
const int N=1e5+10;
int A[N],B[N],x,n,m;
int b_search(int t)
{
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(A[mid]>t) r=mid;
		else l=mid+1;
	}
	if(A[mid]==t) return l;
	else return 0;
}
int main()
{
	int tmp;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=m;i++) cin>>B[i];
	for(int i=1;i<=m;i++)
	{
		tmp=b_search(x-B[i]);
		if(tmp!=0) cout<<tmp-2<<" "<<i-1;
	}
	return 0;
}
