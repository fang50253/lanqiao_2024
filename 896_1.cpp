#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10,M=1e9+10;
int a[N],n,t[N],min_a[N],max_min=1;
void ini()
{
	for(int i=1;i<=N-5;i++) min_a[i]=M;
	min_a[0]=-M;
}
int dp(int x)//·µ»Ø´ð°¸ 
{
	for(int i=max_min;i>=0;i--)
	{
		if(a[x]>min_a[i])
		{
			if(a[x]<min_a[i+1]) min_a[i+1]=a[x];
			if(i+1>max_min) max_min=i+1;
			return i+1;
		}
	}
	return 0;
}
int tm()
{
	int ans=0;
	for(int i=1;i<=n;i++) if(t[i]>ans) ans=t[i];
	return ans;
}
void out()
{
	cout<<"t=";
	for(int i=1;i<=n;i++) cout<<t[i]<<" ";
	cout<<endl<<"min_a=";
	for(int i=1;i<=n;i++) cout<<min_a[i]<<" ";
	cout<<endl;
}
int main()
{
	cin>>n;
	ini();
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {t[i]=dp(i);}
	cout<<tm();
	return 0;
}
