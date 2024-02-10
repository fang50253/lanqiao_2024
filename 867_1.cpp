#include<iostream>
using namespace std;
void divide(int x)
{
	int tmp;
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0)
		{
			tmp=0;
			while(x%i==0)
			{
				x/=i;
				tmp++;
			}
			cout<<i<<" "<<tmp<<endl;
		}
	}
	if(x!=1) cout<<x<<" "<<1<<endl;
	cout<<endl;
}
int main()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q;
		divide(q);
	}
	return 0;
}
