#include<iostream>
using namespace std;
long long ol(int x)
{
    long long res=x;
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0) res=res*(i-1)/i;
        while(x%i==0) x/=i;
    }
    if(x>1) res=res*(x-1)/x;
    return res;
}
int main()
{
    int n;
    long long res=0;
    cin>>n;
    for(int i=1;i<=n;i++) res+=ol(i);
    cout<<res;
    return 0;
}
