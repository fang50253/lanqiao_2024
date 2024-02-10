#include<iostream>
#include<string>
using namespace std;
const int N=1e5+10;
char st[N];
bool check(int l1,int r1,int l2,int r2)
{
	for(int i=l1,j=l2;i<=r1;i++,j++)
	     if(st[i]!=st[j]) return 0;
	     return 1;
}
int main()
{
	int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>st[i];
    for(int i=1;i<=q;i++)
    {
    	int l1,r1,l2,r2;
    	cin>>l1>>r1>>l2>>r2;
    	if(check(l1,r1,l2,r2)) cout<<"Yes";
    	else cout<<"No";
    	cout<<endl;
	}
	return 0;
 } 
