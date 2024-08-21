#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
const int N=9e8+10;
const int ans=12348765;
short st[N],idx;
char str[100][100];
struct Node
{
    int step,value;
};
queue<Node>que;
int A(int x)
{
    int value[9];
    for(int i=8;i>=1;--i)
    {
        value[i]=x%10;
        x/=10;
    }
    int res=0;
    for(int i=5;i<=8;++i) res=res*10+value[i];
    for(int i=1;i<=4;++i) res=res*10+value[i];
    return res;
}
int B(int x)
{
    int value[9];
    for(int i=8;i>=1;--i)
    {
        value[i]=x%10;
        x/=10;
    }
    int tmp4=value[4];
    int tmp8=value[8];
    for(int i=4;i>=2;--i)
    {
        value[i]=value[i-1];
        value[i+4]=value[i+3];
    }
    value[1]=tmp4;
    value[5]=tmp8;
    int res=0;
    for(int i=1;i<=8;++i) res=res*10+value[i];
    return res;
}
int C(int x)
{
    int value[9];
    for(int i=8;i>=1;--i)
    {
        value[i]=x%10;
        x/=10;
    }
    int tmp2=value[2];
    value[2]=value[6];
    value[6]=value[7];
    value[7]=value[3];
    value[3]=tmp2;
    int res=0;
    for(int i=1;i<=8;++i) res=res*10+value[i];
    return res;
}
int main()
{
    int input=0;
    for(int i=1;i<=4;++i)
    {
        int a;
        scanf("%d",&a);
        input=input*10+a;
    }
    stack<int>in;
    for(int i=1;i<=4;++i)
    {
        int a;
        scanf("%d",&a);
        in.push(a);
    }
    for(int i=1;i<=4;++i)
    {
        auto a=in.top();
        in.pop();
        input=input*10+a;
    }
    que.push({0,input});
    st[input]=1;
    while(!que.empty())
    {
        auto output=que.front();
        que.pop();
        int a=A(output.value);
        int b=B(output.value);
        int c=C(output.value);
        if(!st[a])
        {
            st[a]=1;
            que.push({output.step+1,a});
            if(a==ans)
            {
                printf("%d\n",output.step+1);
                return 0;
            }
        }
        if(!st[b])
        {
            st[b]=1;
            que.push({output.step+1,b});
            if(b==ans)
            {
                printf("%d\n",output.step+1);
                return 0;
            }
        }
        if(!st[c])
        {
            st[c]=1;
            que.push({output.step+1,c});
            if(c==ans)
            {
                printf("%d\n",output.step+1);
                return 0;
            }
        }
    }
    return 0;
}