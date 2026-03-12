#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<iterator>
#include<stack>

using namespace std;

#define ll  __int64
#define MAXN  1010
#define inf  1000000007

int n,m,s,t;
int w[MAXN];
struct node
{
    int u,v,w,next;
}edge[251000];
int cnt;
int head[MAXN];
deque<int>q1;

void add(int u,int v,int w)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int d[MAXN],f[MAXN];
bool vis[MAXN];

void spfa()
{
    for(int i=0;i<n;i++)
        d[i]=inf;
    d[s]=0;
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    q1.push_back(s);
    vis[s]=1;
    while(!q1.empty())
    {
        int now=q1.front();
        q1.pop_front();
        vis[now]=0;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(d[v]>d[now]+edge[i].w)
            {
                d[v]=d[now]+edge[i].w;
                f[v]=f[now]+w[v];
                if(!vis[v])
                {
                    vis[v]=1;
                    if(!q1.empty())
                    {
                        if(d[v]>d[q1.front()])
                            q1.push_back(v);
                        else
                            q1.push_front(v);
                    }
                    else
                        q1.push_back(v);
                }
            }
            else if((d[v]==d[now]+edge[i].w)&&f[v]<=f[now]+w[v])
            {
                 f[v]=f[now]+w[v];
                 if(!vis[v])
                 {
                    vis[v]=1;
                    if(!q1.empty())
                    {
                        if(d[v]>d[q1.front()])
                            q1.push_back(v);
                        else
                            q1.push_front(v);
                    }
                    else
                        q1.push_back(v);
                 }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    memset(head,-1,sizeof(head));
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
    cnt=0;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    spfa();
    printf("%d %d\n",d[t],f[t]+w[s]);
    return 0;
}