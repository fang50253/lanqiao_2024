#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int n,q1,q2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q1>>q2;
		cout<<gcd(q1,q2)<<endl;
	}
	return 0;
}
