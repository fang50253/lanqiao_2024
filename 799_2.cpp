#include<iostream>
using namespace std;
const int N=1e5+10;
int n,num[N],j=1,tmp,ans=0;
bool check_range()
{
	for(int i=2;i<=n;i++)
	{
		if(num[i]<=num[i-1]) return 0;
	}
	return 1;
 } 
int check(int l,int r,int x)
{
	for(int i=l;i<r;i++) if(num[i]==x) return i;
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	if(check_range()) cout<<n;
	else
	{
		for(int i=1;i<=n;i++)
        {
	  	    tmp=check(j,i,num[i]);
	  	    if(tmp==0) ans=max(ans,i-j+1);
	  	    else j=tmp+1;
        }
	cout<<ans;
	}
	return 0;
}
//ÌâÄ¿µØÖ·:https://www.acwing.com/problem/content/description/801/ 
