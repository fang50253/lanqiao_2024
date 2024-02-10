#include<iostream>
using namespace std;
const int N=1e5+10;
int e[N],nel[N],ner[N],idx=0,head,tail;
void out_ner()
{
	cout<<"ner:";
	for(int i=0;i<=5;i++) cout<<ner[i]<<" ";cout<<endl<<"e:";
	for(int i=0;i<=5;i++) cout<<e[i]<<" ";cout<<endl;
}
void ini()//初始化链表 
{
	head=-1;tail=-1;
	idx=0;
}
void print()//作用是输出整个链表 
{
	int last=head;
	while(last!=-1)
	{
		cout<<e[last]<<" ";
		last=ner[last];
	}
//	cout<<endl;
}
void L(int x)//链表的最左端插入数 x
{
	e[idx]=x;
	//更新原来的head
	nel[head]=idx; 
	//更新新的head 
	nel[idx]=-1;
	ner[idx]=head;
	head=idx;
	idx++; 
	out_ner();
 } 
void R(int x)//链表的最右端插入数 x
{
	e[idx]=x;
	//更新原来的tail
	nel[tail]=idx; 
	//更新新的head 
	nel[idx]=-1;
	ner[idx]=tail;
	tail=idx;
	idx++; 
	out_ner();
 } 
int main()
{
	ini();
	//L(1);L(2);L(3);
	R(1);R(2);R(3);
	print();
	return 0;
}
