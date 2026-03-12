#include <bits/stdc++.h>
using namespace std;
const int N = 12345;
const int M = 123456;
const int inf = 0x3f3f3f3f;

struct Edge{
	int from, to, dis, nxt;
}edge[M<<1];

int head[N], edgenum;

void addedge(int u, int v, int d)
{
	edge[edgenum].to = v;
	edge[edgenum].dis = d;
	edge[edgenum].nxt = head[u];
	head[u] = edgenum++;
}

int n,m;
int sp[N], in[N];
//dp一定是逆向拓扑序(把所有边反向进行拓扑排序），这样我们在计算u点时，
//通过有向边(u->v)把u点的状态从v点转移过来，能保证v点一定是已计算过的

void topsort()//把图进行拓扑序
{
	queue<int>q;
	for(int i = 0; i < n; i++)
	{
		if(in[i]==0) q.push(i);
	}
	int top = 0;
	while(!q.empty())
	{
		int u = q.front(); 
		q.pop();
		sp[top++] = u;
		for(int i = head[u]; ~i; i = edge[i].nxt)
		{
			if(i&1)
			{
				int v = edge[i].to;
				in[v]--;
				if(!in[v])
				{
					q.push(v);	
				}
			}
		} 
		
	}
} 
int dp[N][2], a[M];
//dp[u][0]表示1到u的最短路 dp[u][1]表示1到u的次小最短路
/*
计算dp[u]：根据定义dp[u] 是删边最短路，则删除的边是在u-终点的路径上，
那么显然有2种情况
1）删除u-v这种与u相连的边
2）删除v-终点上的边
对于2）：那么GG有主动权，
显然是选择edge[i].dis + dp[v] 中最小的,这个最小值为smin
对于1）：军队拥有主动权，军队一定选择删掉一条边，
那么删完以后GG自然还是选择走最短路，
也就是GG只能选择edge[i].dis+dis[v] 中次小值,设这个值为dmin
*/
void solve(int u)
{
	if(u == n-1)
	{ 
		dp[u][0] = dp[u][1] = 0; 
		return ; 
	}
	int top = 0, smin = inf;
	for(int i = head[u]; ~i; i = edge[i].nxt)
	{
		if(!(i&1))
		{
			int v = edge[i].to;
			dp[u][0] = min(dp[u][0], dp[v][0]+edge[i].dis);
			smin = min(smin, dp[v][1]+edge[i].dis);//最短路 
			a[top++] = dp[v][0] + edge[i].dis;
		}
	}
	
	if(top<2)
	{
		dp[u][1] = inf; 
		return ;
	}
	int first = a[0], second = a[1];
	if(first>second) swap(first,second);
	for(int i = 2; i < top; i++)
	{
		if(a[i]<=first) 
		{
			second = first; 
			first = a[i];
		}
		else second = min(second, a[i]);
	}
	int dmin = second;
	//军队拥有的主动权是可以任意选择一条边，所以dp[u]=max(dmin, smin)
	dp[u][1] = max(smin, dmin);
}
int main()
{
	int T, u, v, d;
	scanf("%d",&T);
	while(T--)
	{
		
		memset(head, -1, sizeof head);
		edgenum = 0;
		memset(in, 0, sizeof in);
		scanf("%d %d",&n,&m);
		for(int i =1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&d);
			addedge(u,v,d);
			addedge(v,u,d);
			in[u]++;
		}
		topsort();
		for(int i = 0; i < n; i++)
		{
			dp[i][0] = dp[i][1] = inf;
		}
		
		for(int i = 0; i < n; i++)
		{
			solve(sp[i]);
		}
			
		if(dp[0][1]==inf)dp[0][1] = -1;
		printf("%d\n",dp[0][1]);
	}
	return 0;
}
