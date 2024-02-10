#include<iostream>
using namespace std;
int main()
{
	int n,q,k,num[100010];
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<=q;i++)
	{
		cin>>k;
		int l=1,r=n,mid=l+r+1>>1;
		while(!(l==r))
		{
			
			if(num[mid]>k)  r=mid;
			else if(num[mid]<k) l=mid; 
			mid=l+r+1>>1;
		}
		cout<<endl<<l<<endl;
	}
}
