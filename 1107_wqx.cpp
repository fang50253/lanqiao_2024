#include<iostream>
#include<stdio.h>
using namespace std;

int a[100005];
int ac(int b)
{
	int s=0;
	int c=b%10000;
	b=b/10000;
	s=c*10000;
	s+=b;
	return s;
}
int bc(int b)
{
	int p[9];
	int i=8,s=0;
	while (i>=1)
	{
		p[i]=b%10;
		b/=10;
		i--;
	}
	s=p[4]*10000000+p[1]*1000000+p[2]*100000+p[3]*10000+p[8]*1000+p[5]*100+p[6]*10+p[7];
	return s;
}
int cc(int b)
{
        int p[9];
		int i=8,s=0;
		while (i>=1)
		{
			p[i]=b%10;
			b/=10;
			i--;
		}
		s=p[1]*10000000+p[6]*1000000+p[2]*100000+p[4]*10000+p[5]*1000+p[7]*100+p[3]*10+p[8];
		return s;	
}
int main()
{
    int b[9],s=0;
    for (int i=1;i<=4;i++) {
		cin>>b[i];
		s=s*10+b[i];
	}
	for (int i=8;i>=5;i--)
	{
		cin>>b[i];}
	s=s*10+b[5];
	s=s*10+b[6];
	s=s*10+b[7];
	s=s*10+b[8];
	a[0]=12348765;
    int i=0;
    while (a[i]!=s)
    {
    	i++;
		if (i%3==1) a[i]=ac(a[i/3]);
		if (i%3==2) a[i]=bc(a[i/3]);
		if (i%3==0) a[i]=cc(a[i/3]);
    }
    string l;
    while (i)
    {
		if (i%3==0) l='C'+l;
		if (i%3==1) l='A'+l;
		if (i%3==2) l='B'+l;
		i/=3;
	}
	cout<<l<<endl;
	return 0;
}