#include<iostream>
using namespace std;
unsigned long long ans;
const int N=1e9+7;
long long jc(int x)
{
	long long ans=1;
	for(int i=1;i<=x;i++) ans*=i%N;
	return ans;
}
int main()
{
	int a,b,n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		cout<<jc(a)/jc(b)/jc(a-b)<<endl;
	}
    return 0;
}
