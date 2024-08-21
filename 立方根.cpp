#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int in;
    cin>>in;
    int l=0,r=1000000;
    while(l<r)
    {
        int mid=(l+r)/2;
        //cout<<mid<<" ";
        if((long long)mid*mid*mid<in) l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}