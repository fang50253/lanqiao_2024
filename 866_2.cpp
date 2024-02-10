#include<iostream>
using namespace std;
bool is_p(int x)
{
    if(x==1) return 0;
    if(x%2==0&&x!=2) return 0;
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q;
		if(is_p(q)) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
	return 0;
 } 
