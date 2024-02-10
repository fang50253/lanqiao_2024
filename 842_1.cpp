#include<iostream>
using namespace std;
int n;
int ans[9]={0};
int *p=&ans[1];
void dfs(int x)
{
	if(x==n)
	{
		for(int i=1;ans[i]!=0;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i=x+1;i<=n;i++)
	    {
		    *p=i;
		    p++;
		    dfs(i);
		    *p=0;
		    p--;
	    }
    } 
}
	
int main()
{
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		*p=i;
		p++;
		dfs(i);
		*p=0;
		p--;
	}
	return 0;
 } 
