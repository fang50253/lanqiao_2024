#include<iostream>
using namespace std;
bool bj[9]={0};
int x=0,n,temp;
int ans[9]={0};
int *p=&ans[1];
bool fullcomb()
{
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==0) return 0;
	}
	return 1;
}
void dfs(int x)
{
	temp++;
	if(fullcomb())
	{
	    for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
    }
    else
    {
	    for(int i=1;i<=n;i++)
	    {
	    	if(!bj[i])
			{
	    		bj[i]=1;
	    		*p=i;
				p++;
				dfs(i);
				p--;
				*p=0;
				bj[i]=0;
			}
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
 } 
