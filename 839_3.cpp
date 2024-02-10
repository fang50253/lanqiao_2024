#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
using namespace std;
const int N=1e5+10;
int heap[N],hp[N],ph[N],size_;
void heap_swap(int a,int b)
{
	swap(ph[hp[a]],ph[hp[b]]);
	swap(hp[a],hp[b]);
	swap(heap[a],heap[b]);
}
void down(int u)
{
	int t=u;
	if(heap[t]>heap[2*u]&&2*u<=size_) t=2*t;
	if(heap[t]>heap[2*u+1]&&2*u+1<=size_) t=2*u+1;
	if(t!=u)
	{
		heap_swap(u,t);
		down(t);
	}
}
void  up(int u)
{
	while(u/2&&heap[u]<heap[u/2])
	{
		heap_swap(u,u/2);
		u/=2;
	}
}
void insert(int x)
{
	heap[++size_]=x;
	ph[size_]=size_;
	up(size_);
}
int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n -- )
    {
        char op[5];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            size_ ++ ;
            m ++ ;
            ph[m] = size_, hp[size_] = m;
            heap[size_] = x;
            up(size_);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", heap[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, size_);
            size_ -- ;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
        	int k;
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, size_);
            size_ -- ;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            heap[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}
