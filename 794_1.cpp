#include<iostream>
using namespace std;
int A[100010],B,C[100010];
int main()
{
	string a;
	cin>>a>>B;
	for(int i=a.length()-1,j=1;i>=0;i--,j++) A[j]=a[i]-'0';
	bool out=0;
	for(int i=a.length();i>=1;i--)
	{
		C[i]=A[i]/B;
		A[i-1]+=(A[i]%B)*10;
	 } 
	for(int i=100005;i>=1;i--)
	{
	 	if(C[i]) out=1;
	 	if(out) cout<<C[i];
    } 
    if(!out) cout<<0;
    cout<<endl<<A[0]/10;
    return 0;
}
