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
	 if(x>1) primes[x]++;
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
	for (auto p : primes)
    {
        LL a = p.first, b = p.second;
        LL t = 1;
        while (b -- ) t = (t * a + 1) % N;
        res = res * t % N;
    }
	cout<<res<<endl;
	return 0;
}
