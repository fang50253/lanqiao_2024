#include<iostream>
using namespace std;
const int N =1e6+10;
int a[N],head=0,tail=0;
void push(int x)
{
	a[tail++]=x;
}
void pop()
{
	head++;
}
void empty()
{
	if(head==tail) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}
void query()
{
	cout<<a[head]<<endl;
}
int main()
{
	string op;
	int M;
	cin>>M;
	for(int i=1;i<=M;i++)
	{
		cin>>op;
		if(op=="push")
		{
			int x;
			cin>>x;
			push(x);
		}
		else if(op=="pop") pop();
		else if(op=="query") query();
		else if(op=="empty") empty();
	}
	return 0;
}
