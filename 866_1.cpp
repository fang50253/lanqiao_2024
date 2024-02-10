#include<iostream>
#include<math.h>
using namespace std;
const int N=1e6+10;
int n,q,a[N],idx=0,qnum[110];
void out()
{
	for(int i=0;i<idx;i++) cout<<a[i]<<" ";
}
int qm()
{
	int ans=0;
	for(int i=0;i<n;i++) if(ans<qnum[i]) ans=qnum[i];
	return ans;
}
void is(int x)
{
	if(x%2==0) return;
	for(int i=0;x/a[i]>=a[i];i++)
	{
		if(x%a[i]==0) return;
	}
	a[++idx]=x;
}
bool b_search(int x)
{
	int l=0,r=idx,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	if(a[l]==x) return 1;
	else return 0;
}
int main()
{
	cin>>n;
	a[0]=2;
	for(int i=0;i<n;i++) cin>>qnum[i];
	int max_=qm();
	for(int i=3;i<=max_+1;i++) is(i);
	for(int i=0;i<n;i++)
	{
		q=qnum[i];
		if(b_search(q)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	//out();
	return 0;
 } 
