#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N][26],b[N],idx=1;
char x[N];
void I(char *x)
{
	int tmp,c=0;
	for(int i=0;x[i];i++)
	{
		tmp=x[i]-'a';
		if(!a[c][tmp]) a[c][tmp]=idx++;
		c=a[c][tmp];
	}
	b[c]++;
}
int Q(char *x)
{
	int tmp,c=0;
	for(int i=0;x[i];i++)
	{
		tmp=x[i]-'a';
		if(!a[c][tmp]) return 0;
		c=a[c][tmp];
	}
	return b[c];
}
int main()
{
	int n;
	char op;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>op>>x;
		if(op=='I') I(x);
		else if(op=='Q') cout<<Q(x)<<endl;
	}
	return 0;
 } 
