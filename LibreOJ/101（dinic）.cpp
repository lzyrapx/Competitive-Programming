#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005;
const int M = 4000005;
const int INF = 2147483647;
struct edge
{
	int go,next,val;
} e[M<<1]; 
int cnt=1,last[N]; 
void ins(int u,int v,int w)
{
	e[++cnt].go=v; e[cnt].next=last[u]; 
	e[cnt].val=w; last[u]=cnt;
}
void addedge(int u,int v,int w)
{
	ins(u,v,w); 
	ins(v,u,0);
}

int n,m;
int S,T;

int dis[N],cur[N];
int q[N];
bool bfs()
{
	int head=0,tail=0; 
	q[tail++]=S;
	for(int i=1;i<=n;i++)
	{
		dis[i]=-1; 
		dis[S]=0;
	}	
	while (head<tail)
	{
		int now=q[head++];
		for (int i=last[now];i;i=e[i].next)
		{
			if (e[i].val&&dis[e[i].go]==-1)
			{
				dis[e[i].go]=dis[now]+1;
				q[tail++]=e[i].go;
				if (e[i].go==T) return 1;
			}
		}
	}
	return 0;
} 

int dfs(int x,int f)
{
	if (x==T) return f;
	int used=0;
	for (int i=cur[x];i;i=e[i].next)
	{
		if (e[i].val&&dis[e[i].go]==dis[x]+1)
		{
			int w=dfs(e[i].go,min(f-used,e[i].val));
			used+=w; 
			e[i].val-=w; 
			e[i^1].val+=w;
			if (used==f) return f;
		}
		cur[x]=i;
	}
	if (used) dis[x]=-1;
	return used;
}
int maxflow;
void dinic()
{

	while (bfs())
	{
		for(int i=1;i<=n;i++)cur[i]=last[i];
		maxflow+=dfs(S,INF);
	}
}  
int main()
{
	int u,v,w;
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	dinic();
	printf("%d\n",maxflow);	
	return 0;
}