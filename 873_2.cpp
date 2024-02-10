#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	while(n--)
	{
		long long q;
		cin>>q;
		long long res=q;
		for(long long i=2;i<=q/i;i++)
		{
			if(q%i==0) res=res*(i-1)/i;
			while(q%i==0) q/=i;
		}
		if(q>1) res=res*(q-1)/q;
		cout<<res<<endl;
	}
	return 0;
}
