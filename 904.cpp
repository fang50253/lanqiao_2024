#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int MAXN=1e4+10;
int e[MAXN],ne[MAXN],h[MAXN],dist[MAXN],w[MAXN],cnt[MAXN],idx=1,N,M,F,W,S,E,T;
bool st[MAXN];
void add(int a,int b,int c)
{
    w[idx]=c;
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int main()
{
    scanf("%d",&F);
    while(F--)
    {
        memset(h,0,sizeof h);
        memset(dist,0x3f,sizeof dist);
        memset(st,0,sizeof st);
        memset(cnt,0,sizeof cnt);
        idx=1;
        scanf("%d%d%d",&N,&M,&W);
        for(int i=1;i<=M;++i)
        {
            scanf("%d%d%d",&S,&E,&T);
            add(S,E,T);
            add(E,S,T);
        }
        for(int i=1;i<=W;++i)
        {
            scanf("%d%d%d",&S,&E,&T);
            add(S,E,-T);
            //add(E,S,-T);
        }
        queue<int>node;
        for(int i=1;i<=N;++i)
        {
            node.push(i);
            st[i]=1;
        }
        cnt[1]=1;
        bool ans=0;
        while(!node.empty())
        {
            int que=node.front();
            node.pop();
            st[que]=0;
            for(int i=h[que];i;i=ne[i])
            {
                int ori=dist[e[i]];
                int cha=dist[que]+w[i];
                if(ori>cha)
                {
                    cnt[e[i]]=cnt[que]+1;
                    dist[e[i]]=cha;
                    if(cnt[e[i]]>=N) ans=1;
                    if(st[e[i]]==0)
                    {
                        node.push(e[i]);
                        st[e[i]]=1;
                    }
                }
            }
            if(ans) break;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}