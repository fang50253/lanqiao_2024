#include<iostream>
//#include<stdio.h>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int next_[N],value[N],new_w=1,start=1,end;
//w���������λ�ã�v�����˲�����ָʾ��ֵ�Ĵ�С 
//next����д0���������Ԫ���ѱ�ɾ��
//next����д-1�����������
void print()
{
	int next_w=start;
	while(next_w!=-1)
	{
		cout<<value[next_w];
		next_w=next_[next_w];
	}
}
void H(int v)
{
	next_[new_w]=start;
	value[new_w]=v; 
	start=new_w++;
	
}
int main()
{
	int M,w,v;
	cin>>M;
	char z;
	for(int i=1;i<=M;i++)
	{
		if(z=='H')
		{
			cin>>v;
			H(v); 
		}
	}
	print();
	return 0;
}
