#include<iostream>
using namespace std;
const int N=1e5+10;
int n,m,A[N],B[N],x;
int main()
{
	cin>>n>>m>>x;
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<m;i++) cin>>B[i];
	int i=0,j=m-1;
	for(;i<n;++i)
	{
	//	cout<<i<<" "<<j<<" "<<A[i]+B[j]<<endl;
		for(;A[i]+B[j]>=x&&j>-1;j--)
		{
			if(A[i]+B[j]==x)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}
