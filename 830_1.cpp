#include<iostream>
#include<stack>
using namespace std;
stack<int>a;
void c(int t)
{
	stack<int>b;
	while(1)
	{
		int last=a.top();
		if(last<t)
		{
			cout<<last<<" ";
			break;
		}
		else
		{
			b.push(last);
			a.pop();
		}
	}
	while(!b.empty())
	{
	    a.push(b.top());
        b.pop();	
	}
	while(a.top()>=t) a.pop();
	a.push(t);
}
int main()
{
	a.push(-1); 
	int n,num;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		c(num);
	}
	return 0;
}
