#include<iostream>
//#include<stdio.h>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int next_[N],value[N],new_w=1,start=1,end;
//w代表操作的位置，v代表了操作所指示的值的大小 
//next数组写0代表该链表元素已被删除
//next数组写-1代表链表结束
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
