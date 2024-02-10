#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<string,int>a;
void I(string x)
{
	if(a.count(x)) a[x]++;
	else a[x]=1;
}
void Q(string x)
{
	if(a.count(x)) cout<<a[x]<<endl;
	else cout<<0<<endl;
}
int main()
{
	int n;char op;
	cin>>n;
	string cz;
	for(int i=1;i<=n;i++)
	{
		cin>>op>>cz;
		if(op=='I') I(cz);
		else if(op=='Q') Q(cz);
	}
	return 0;
}
