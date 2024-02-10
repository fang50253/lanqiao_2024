#include<iostream>
using namespace std;
double pow(double x)
{
	return x*x*x;
}
int main()
{
	double n;
	cin>>n;
	double l=-30.0000000,r=30.0000000;
	while(!(r-l<=0.0000001))
	{
		double mid=(l+r)/2.0;
		if(pow(mid)>=n) r=mid;
		else l=mid;
	}
	printf("%.6f",l);
	return 0;
}
