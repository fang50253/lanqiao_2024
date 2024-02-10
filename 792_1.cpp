#include<iostream>
#include<string>
using namespace std;
int A[100010]={0},B[100010]={0},C[100010]={0};
string a,b;
int big()
{
	bool ans;
	for(int i=0;i<=a.length()-1;i++)
	{
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return 0;
	 } 
	 return -1;
}
int main()
{
	//首先读入两个数字a，b 
	cin>>a>>b;
	//下面对数组进行逆序 
	bool sign;
	if(a.length()>b.length()) sign=1;
	else if(a.length()<b.length()) sign=0;
	else if(big()==-1) {cout<<0;return 0;}
	else sign=big();
	
	if(sign)
	{
		for(int i=a.length()-1,j=1;i>=0;i--,j++) A[j]=a[i]-'0';
	    for(int i=b.length()-1,j=1;i>=0;i--,j++) B[j]=b[i]-'0';
	}
	else
	{
		for(int i=a.length()-1,j=1;i>=0;i--,j++) B[j]=a[i]-'0';
	    for(int i=b.length()-1,j=1;i>=0;i--,j++) A[j]=b[i]-'0';
	}
	//下面进行求差 
    for(int i=1;i<=max(a.length(),b.length());i++)
	{
		if(A[i]-B[i]<0)
		{
			A[i]+=10;A[i+1]--;
		}
		C[i]=A[i]-B[i];
	 } 
	 //下面是输出部分
	 bool out=0;
	 if(!sign) cout<<"-";
	 for(int i=max(a.length(),b.length());i>=1;i--)
	 {
	 	if(C[i]) out=1;
	 	if(out) cout<<C[i];
	 }
	 return 0;
}
