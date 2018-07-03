#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=0x7fffffff;
const int maxn=400;
const int maxm=15000;
int n,m,s,t,Maxflow=0,Mincost=0;
int tot=-1,head[maxn+1];
struct node
{
    int p,next,flow,cost;
}edge[maxm<<1];
void addedge(int u, int v, int w1, int w2)
{
    edge[++tot]=(node){v,head[u],w1,w2};
    head[u]=tot;
}
int dis[maxn+1],num[maxn+1],Minflow[maxn+1];
queue<int> q;
bool vis[maxn+1];
bool SPFA(int &Mincost, int &Maxflow)
{
    fill(dis + 1, dis + n + 1, INF);
    memset(vis,0,sizeof(vis));
    dis[s]=0;
	Minflow[s]=INF;
    q.push(s);
	vis[s]=1;
    while (!q.empty())
    {
        int u=q.front();
		q.pop();
		vis[u]=0;
        for (int i=head[u]; ~i; i=edge[i].next)
        {
            int v=edge[i].p,w=edge[i].cost;
            if (edge[i].flow&&dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                num[v]=i;
                Minflow[v]=min(Minflow[u],edge[i].flow);
                if (!vis[v])
                {
                    q.push(v);
					vis[v]=1;
                }
            }
        }
    }
    if (dis[t]==INF) return 0;
    Maxflow+=Minflow[t];
    Mincost+=dis[t]*Minflow[t];
    for (int i=t; i!=s; i=edge[num[i]^1].p)
    {
        edge[num[i]].flow-=Minflow[t];
        edge[num[i]^1].flow+=Minflow[t];
    }
    return 1;
}
void MCMF(int &Mincost, int &Maxflow)
{
    while (SPFA(Mincost,Maxflow));
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    s = 1;
    t = n;
    memset(head,-1,sizeof(head));
    for (int i=1; i<=m; i++)
    {
        int u,v,w1,w2;
        scanf("%d%d%d%d",&u,&v,&w1,&w2);
        addedge(u,v,w1,w2);
		addedge(v,u,0,-w2);
    }
    MCMF(Mincost,Maxflow);
    // Mincost =  最大流
	// Maxflow = 最小费用 
    printf("%d %d\n",Maxflow,Mincost);
    return 0;
}