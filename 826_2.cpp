#include<iostream>
using namespace std;
const int N=1e5+10;
int e[N],ne[N],idx,head;
//e[N]存储了整个链表的数据
//ne[N]数组写入了整个链表的next指针
//idx表示再以上两个数组当中，最新的一个可用位置
//head表示了链表表头所在的位置
void ini()//初始化链表操作
{
	head=-1;
	idx=0;
 } 
void print()//作用是输出整个链表 
{
	int last=head;
	while(last!=-1)
	{
		cout<<e[last]<<" ";
		last=ne[last];
	}
//	cout<<endl;
}
void H(int x)//在表头插入一个数字x
{
	e[idx]=x;
	ne[idx]=head;
	head=idx;
	idx++;
 } 
void I(int k,int x) //在第 k个插入的数后面插入一个数 x（此操作中 k均大于 0）
{
	e[idx]=x;
	ne[idx]=ne[k-1];
	ne[k-1]=idx;
	idx++;
}
void D(int x)//删除删除第 k个插入的数后面的数（当 k为 0时，表示删除头结点）
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
