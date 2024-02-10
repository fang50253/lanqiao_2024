#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N],head=1,tail=0;
void sc()
{
	cout<<endl<<"quque:";
	for(int i=head;i<=tail;i++) cout<<a[i]<<" ";cout<<endl;
}
int main()
{
	int n,k;
	cin>>n>>k;
	head=0;tail=-1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	while(tail<n)
	{
		tail++;
		if(tail-head>=k) head++;
		for(int i=head;i<=tail;i++)
		if(a[head]>=a[i]) head=i;
		if(tail>=k) printf("%d ",a[head]);
	}
	head=0;tail=-1;
	printf("\n");
	while(tail<n)
	{
		tail++;
		if(tail-head>=k) head++;
		for(int i=head;i<=tail;i++)
		if(a[head]<=a[i]) {head=i;}
		if(tail>=k) printf("%d ",a[head]);
	}
	return 0;
}
