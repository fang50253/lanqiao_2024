#include<iostream>
#include<stack>
using namespace std;
void y(int x)
{
	stack<int>a;
	for(int i=1;i<=x/i;i++)
	{
		if(x%i==0)
		{
			cout<<i<<" ";
			if(i!=x/i) a.push(x/i);
		}
	}
	while(!a.empty())
	{
		cout<<a.top()<<" ";
		a.pop();
	}
    cout<<endl;
}
int main()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q;
		y(q);
	}
	return 0;
}
