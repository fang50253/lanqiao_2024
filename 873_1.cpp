#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	int n,q,re;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		unordered_map<int,int>a;
		cin>>q;re=q;
		for(int j=2;j<=q/j;j++)
	    {
		    while(q%j==0)
		    {
			    a[j]++;
			    q/=j;
		    }
	    }
	    if(q>1) a[q]++;
	    double res=1.0;
	    for(auto tmp:a) res=res-res/tmp.first;
	    cout<<res*re<<endl;
	}
}
