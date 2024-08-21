#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
const int dx[5]={0,1,0,-1,0};
const int dy[5]={0,0,1,0,-1};
int map[6][6];
void turn(int a,int b)
{
    for(int i=0;i<5;++i)
    {
        int x=a+dx[i],y=b+dy[i];
        if(x>=1&&x<=5&&y>=1&&y<=5) map[x][y]=1-map[x][y];
        else continue;
    }
}
void out_map()
{
    for(int i=1;i<=5;++i)
    {
        for(int j=1;j<=5;++j)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}
void fun()
{
    int step=0;
    memset(map,0,sizeof map);
    for(int i=1;i<=5;++i)
    {
        string str;
        char in[10];
        cin>>str;
        for(int j=1;j<=5;++j) map[i][j]=str[j-1]-'0';
        //for(int j=1;j<=5;++j) printf("%d ",map[i][j]);printf("\n");
    }
    out_map();
    for(int i=1;i<=3;++i)
        if(map[1][i]==0&&map[1][i+1]==0&&map[1][i+2]==0)
        {
            turn(1,i+1);
            ++step;
        }
    for(int i=1;i<=4;++i)
        if(map[1][i]==0&&map[1][i+1]==0&&map[2][i]==0)
        {
            turn(1,i);
            ++step;
        }
    for(int i=1;i<=4;++i)
        if(map[1][i]==0&&map[1][i+1]==0&&map[2][i+1]==0)
        {
            turn(1,i+1);
            ++step;
        }
    for(int i=1;i<=4;++i)
    {
        for(int j=1;j<=5;++j)
            if(map[i][j]==0)
            {
                turn(i+1,j);
                ++step;
            }
    }
    bool if_success=1;
    for(int i=1;i<=5;++i)
    {
        if(map[5][i]==0) if_success=0;
    }
    if(step>=7||if_success==0) printf("-1\n");
    else printf("%d\n",step);
    out_map();
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) fun();
    return 0;
}