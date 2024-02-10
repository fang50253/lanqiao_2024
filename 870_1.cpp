#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long LL;
unordered_map<int,int>primes;
const int N=1e9+7;
void divide(int x)
{
    int tmp;
	for(int i=2;i<=x/i;i++)
	{
		tmp=0;
		while(x%i==0)
		{
			x/=i;
			tmp++;
		}
		primes[i]+=tmp;
	 } 
	 primes[x]++;
}
int main()
{
	int n,x;
	cin>>n;
	while(n--)
	{
		cin>>x;
		divide(x);
	}
	LL res=1;
	for(auto prime:primes) res=res*(prime.second+1)%N;
	cout<<res<<endl;
	return 0;
}
