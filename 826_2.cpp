#include<iostream>
using namespace std;
const int N=1e5+10;
int e[N],ne[N],idx,head;
//e[N]�洢���������������
//ne[N]����д�������������nextָ��
//idx��ʾ�������������鵱�У����µ�һ������λ��
//head��ʾ�������ͷ���ڵ�λ��
void ini()//��ʼ���������
{
	head=-1;
	idx=0;
 } 
void print()//����������������� 
{
	int last=head;
	while(last!=-1)
	{
		cout<<e[last]<<" ";
		last=ne[last];
	}
//	cout<<endl;
}
void H(int x)//�ڱ�ͷ����һ������x
{
	e[idx]=x;
	ne[idx]=head;
	head=idx;
	idx++;
 } 
void I(int k,int x) //�ڵ� k����������������һ���� x���˲����� k������ 0��
{
	e[idx]=x;
	ne[idx]=ne[k-1];
	ne[k-1]=idx;
	idx++;
}
void D(int x)//ɾ��ɾ���� k�������������������� kΪ 0ʱ����ʾɾ��ͷ��㣩
{
	if(x==0) head=ne[head];
	else ne[x-1]=ne[ne[x-1]];
}
void tiaoshi()
{
	for(int i=1;i<=10;i++) H(i);
	D(0);
}
int main()
{
	ini();
	char in;
	int x,k,n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>in;
	    if(in=='H')
	    {
		    cin>>x;
		    H(x);
	    }
	    else if(in=='D')
	    {
		    cin>>x;
		    D(x);
    	}
	    else if(in=='I')
	    {
	    	cin>>k>>x;
	    	I(k,x);
    	}
    	//print();
	}
	//tiaoshi();
//	cout<<endl;
	print();
	return 0;
}
