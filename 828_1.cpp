#include<iostream>
#include<string>
using namespace std;
const int N=1e5+10;
int z[N],idx=1;
void push(int x)
{
	z[idx]=x;
	idx++;
}
void query()
{
	cout<<z[idx-1]<<endl;
}
void pop()
{
	idx--;
}
void empty()
{
	if(idx==1) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}
int main()
{
	int M,x;
	string op;
	cin>>M;
	for(int i=1;i<=M;i++)
	{
		cin>>op;
		if(op=="push")
		{
			cin>>x;
			push(x);
		}
		else if(op=="query") query();
		else if(op=="pop") pop();
		else if(op=="empty") empty();
	}
	return 0;
}
