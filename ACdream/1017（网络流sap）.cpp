#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n,m,K,s,t,S,T,N;
int head[50010],h[50010],vh[50010];
int idx;
bool vis[50010],mp[120][120];

struct Edge
{
    int v, f, next;
    
}edge[501010];

void addEdge(int u,int v,int f)
{
    edge[idx].v = v; edge[idx].f = f;
    edge[idx].next = head[u]; head[u] = idx++;
    edge[idx].v = u; edge[idx].f = 0;
    edge[idx].next = head[v]; head[v] = idx++;
}
void CreateGraph(int d)
{
    memset( head, 0xff, sizeof(head)); 
	idx = 0;
    S = 0; 
	T = (d+1)*n+1; 
	N = (d+1)*n+2;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(mp[i][j])
                for(int c = 1; c <= d; c++)
                    addEdge( (c-1)*n+i,c*n+j, 1 );    
                    
    for(int i = 1; i <= n; i++)
        for(int c = 1; c <= d; c++)
            addEdge( (c-1)*n+i, c*n+i, inf );
            
    addEdge( S, s, K );
    for(int c = 1; c <= d; c++)
        addEdge( c*n+t, T, inf );
}  
int DFS( int u, int flow )
{
    if( u == T ) return flow;
    int tmp = h[u]+1, remain = flow;
    for(int i = head[u]; ~i; i = edge[i].next )
    {
        int v = edge[i].v;
        if( edge[i].f && h[u] == h[v]+1 )
        {
            int p = DFS( v, min( remain, edge[i].f ) ); //取修改后的可流动流量递归,部分优化
            edge[i].f -= p; 
			edge[i^1].f += p; 
			remain -= p;
            if( !remain || h[S] == N ) return flow - remain; //若流量为0或者无增广路则退出
        }
    }
    for(int i = head[u]; ~i; i = edge[i].next )
    {
    	if( edge[i].f )  
		tmp = min( tmp, h[ edge[i].v ] );
	}
        
    if( !( --vh[ h[u] ] ) ) h[S] = N; //更新完顶点u后,v[u]层节点数减少一个
    else  vh[ h[u]=tmp+1 ]++; //间隙优化,若出现断层,即可判定无增广路
    return flow - remain;
}
bool sap()
{
    int maxflow = 0;
    memset( h, 0, sizeof(h)); // 层次网络
    memset( vh, 0, sizeof(vh)); // 当前层节点数量
    vh[0] = N;  // 0层节点数量初始化为 总结数N个
    while( h[S] < N ) // 起点层次大于等于N时无增广路
        maxflow += DFS( S, inf );  // 从源点S 开始找增广路,初始流量为inf
    return (maxflow == K);
}
  
int main()
{
	while(~scanf("%d%d%d%d%d",&n,&m,&K,&s,&t))
	{
		memset(mp,0,sizeof(mp));
		int u,v;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			mp[u][v]=mp[v][u]=true;
		}
		 int l=0, r=n*K;
		 while(r>l)
		 {
		 	int mid=(l+r)>>1;
		 	CreateGraph(mid);
		 	if(sap()) r=mid;
		 	else l=mid+1;
		 }
		 printf("%d\n",l);
	}
	return 0;
}