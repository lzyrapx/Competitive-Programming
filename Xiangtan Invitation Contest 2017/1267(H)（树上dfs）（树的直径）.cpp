#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll INF=0x3f3f3f3f3f3f3f3fLL;

struct node
{
    int v,w;
};

vector<node> G[maxn];
bool vis[maxn];
ll dist=-INF;
int point;
ll res[3][maxn];
int n;

void dfs(int x,ll dis,int index)
{
    if(index) 
	{
		res[index][x]=dis;
	}
    if(dis>dist)
	{
    	dist=dis;
		point=x;
	}
	int size=G[x].size();
    for(int i=0;i<size;i++)
    {
        node &next=G[x][i];
        if(vis[next.v]==true) continue;
        vis[next.v]=true;
        dfs(next.v,next.w+dis,index);
    }
}

void solve()
{
    memset(vis,0,sizeof(vis));
    //假设初始点x是某条直径的端点。
	//那么距离x 最远的y 必然是直径的另一个端点。
    dist=-INF;
    dfs(1,0,0);
    int x=point;
    
    memset(vis,0,sizeof(vis));
    dist=-INF;
    dfs(x,0,1);
    int y=point;
    //因为距离任意点最远的要么是x,要么是y，
	//所以剩下的点只需要连往x 和y 中较远的一个即可。
    memset(vis,0,sizeof(vis));
    dfs(y,0,2);
    ll ans=res[1][y];
    
    for(int i=0;i<=n;i++)
    {
        if(i==x||i==y) continue;
        ans+=max(res[1][i],res[2][i]);
    }
    printf("%I64d\n",ans);
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<maxn;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back({v,w});
            G[v].push_back({u,w});    
        }
        solve();
    }
    return 0;
}