#include<iostream>
#include<string>
using namespace std;
unsigned int A[100010]={0},B[100010]={0},C[100010]={0};
int main()
{
	//���ȶ�����������a��b 
	string a,b;
	cin>>a>>b;
	//���������������� 
	for(int i=a.length()-1,j=1;i>=0;i--,j++) A[j]=a[i]-'0';
	for(int i=b.length()-1,j=1;i>=0;i--,j++) B[j]=b[i]-'0';
	//���������� 
    for(int i=1;i<=max(a.length(),b.length());i++)
	{
		C[i]+=(A[i]+B[i])%10;
		if(C[i]>=10)
		{
			C[i+1]=C[i]/10;
			C[i]%=10;
		}
		C[i+1]+=(A[i]+B[i])/10;
	 } 
	 //�������������
	 if(C[max(a.length(),b.length())+1]!=0) cout<<1;
	 for(int i=max(a.length(),b.length());i>=1;i--) cout<<C[i];
	 return 0;
}
