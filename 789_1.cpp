#include<iostream>
using namespace std;
int n,q,num[100010],k; 
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<=q;i++)
	{
		cin>>k;
		int l=1,r=n,mid=1+r>>1;
		for(;!(num[l]==k&&num[r]==k);)
		{
			if(l==r)
			{
				l=-1;r=-1;break;
			}
			else if(num[mid]>k)
		    {
		    	r=mid;
	        }
		    else if(num[mid]<k)
	    	{
		    	l=mid;
	    	}
	    	mid=l+r+1>>1;
		}
		cout<<l<<" "<<r;
	}
	return 0;
 } 
