#include<iostream>
#include<cmath>
using namespace std;
const int N=1010;
int f[N],v[N],w[N],T,M;
int main()
{
	cin>>T>>M;//t体积 m数目 
	for(int i=1;i<=M;i++) cin>>v[i]>>w[i];
	for(int i=1;i<=M;i++)
	{
        for(int j=T;j>=v[i];j--)
        {
        	f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	cout<<f[T];
	return 0;
}
