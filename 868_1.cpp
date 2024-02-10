#include<iostream>
#include<math.h>
using namespace std;
const int N=1e6+10;
int n,a[N],idx=0;
void is(int x)
{
	if(x%2==0) return;
	for(int i=0;x/a[i]>=a[i];i++) if(x%a[i]==0) return;
	a[++idx]=x;
}
int main()
{
	cin>>n;
	a[0]=2;
	for(int i=3;i<=n;i++) is(i);
	if(n==1) cout<<0;
	else cout<<idx+1;
	return 0;
 } 
