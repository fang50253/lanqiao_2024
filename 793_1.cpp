#include<iostream>
using namespace std;
int A[100010]={0},B[100010]={0},C[100010];
int main()
{
	//���ȶ�����������a��b 
	string a,b;
	cin>>a>>b;
	//���������������� 
	for(int i=a.length()-1,j=1;i>=0;i--,j++) A[j]=a[i]-'0';
	for(int i=b.length()-1,j=1;i>=0;i--,j++) B[j]=b[i]-'0';
	//���������� 
    for(int i=1;i<=a.length();i++)
    {
    	for(int j=1;j<=b.length();j++)
    	{
    		C[i+j-1]+=A[i]*B[j];
		}
	}
	//���洦���λ
	int tmp=1;
	for(int i=1;i<=100005;i++)
	{
		C[tmp+1]+=C[tmp]/10;
		C[tmp]%=10;
		tmp++;
	 } 
	 //����������
	 bool out=0;
	 for(int i=100005;i>=1;i--)
	 {
	 	if(C[i]) out=1;
	 	if(out) cout<<C[i];
	  } 
	  if(!out) cout<<0;
    return 0;
} 
