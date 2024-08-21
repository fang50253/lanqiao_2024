#include<stdio.h>
#include<string.h>
int map[10][10];
void out()
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
void turn(int a,int b)
{
    const int dx[5]={0,0,0,1,-1};
    const int dy[5]={0,1,-1,0,0};
    for(int i=0;i<5;++i)
    {
        int x=a+dx[i];
        int y=b+dy[i];
        if(x>=1&&x<=5&&y>=1&&y<=5) map[x][y]=1-map[x][y];
    }
}
void fun()
{
    //内容的输入
    int backup[10][10];
    for(int i=1;i<=5;++i)
    {
        char input[10];
        scanf("%s",input);
        for(int j=0;j<5;++j) backup[i][j+1]=input[j]-'0';
    }
    int ans=8;
    for(int ch=0;ch<=31;++ch)
    {
        memcpy(map,backup,sizeof map);
        int res=0;
        //处理第一行
        for(int i=0;i<5;++i) 
            if(ch>>i&1)
            {
                turn(1,i+1);
                ++res;
            }
        //处理除了最后一行以外的几行
        for(int i=1;i<=4;++i)
            for(int j=1;j<=5;++j)
                if(map[i][j]==0)
                {
                    turn(i+1,j);
                    ++res;
                }
        //判断最后一行
        int if_success=1;
        for(int i=1;i<=5;++i) 
            if(map[5][i]==0) if_success=0;
        if(if_success) ans=(ans>res)?res:ans;
    }
    if(ans>=7) printf("-1\n");
    else printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) fun();
    return 0;
}