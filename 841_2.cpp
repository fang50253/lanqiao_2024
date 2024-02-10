#include<iostream>
using namespace std;
const int N=1e5,P=131;
int n,m;
unsigned long long p[N],h[N];
void init()
{
	p[0]=1;
	char read;
	for(int i=1;i<=n;i++) p[i]=P*p[i-1];
	for(int i=1;i<=n;i++)
	{
		cin>>read;
		h[i]=h[i-1]*P+int(read);
	}
}
unsigned long long get(int l,int r)
{
	return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
	cin>>n>>m;
	init();
	int l1,r1,l2,r2;
	while(m--)
	{
		cin>>l1>>r1>>l2>>r2;
		if(get(l1,r1)==get(l2,r2)) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
	return 0;
 } 
