#include<iostream>
using namespace std;
int lowbit(int x)
{
	return x & -x;
}
int main()
{
	int n,x;
	cin>>n;
	while(n--)
	{
		cin>>x;
		int count=0;
		while(x)
		{
			x-=lowbit(x);
			count++;
		}
		cout<<count<<" ";
	}
	return 0;
 } 
