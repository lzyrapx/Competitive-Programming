#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1e3+100; // 2^10
const int mod=1e9+7;
const int rev=(mod+1)>>1;
//dp[u][i]表示 u 为根的数，异或后得到 i 的方案数 
int val[N], dp[N][N],ans[N];
int temp[N];
int len;
int n,m;
struct Edge
{
	int from,to;
		
}edge[2*N];

int cnt;
int head[N];
vector<int> V[2*N]; 
//void addedge(int u,int v)
//{
//	edge[cnt].from=v;  edge[cnt].to=head[u];  head[u]=cnt++;
//	edge[cnt].from=u;  edge[cnt].to=head[v];  head[v]=cnt++;
//}

void FWT(int a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
			{
                int x=a[i+j],y=a[i+j+d];
                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
                //xor:a[i+j]=x+y,a[i+j+d]=(x-y+mod)%mod;
                //and:a[i+j]=x+y;
                //or:a[i+j+d]=x+y;
            }
}

void UFWT(int a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
			{
                int x=a[i+j],y=a[i+j+d];
                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
                //and:a[i+j]=x-y;
                //or:a[i+j+d]=y-x;
            }
}
void solve(int a[],int b[],int n)
{
    FWT(a,n);
    FWT(b,n);
    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
    UFWT(a,n);
}
void dfs(int u,int fa)
{	
	dp[u][val[u]]=1;//自己与自己异或后为 0 的方案数 
	for(int i=0;i<V[u].size();i++)
	{
		int v =  V [u][i];
		if(v==fa) continue;
		dfs(v,u);
		for(int i=0;i<m;i++) temp[i]=dp[u][i];
		
		solve(dp[u],dp[v],m); //当前dp[x]的所有值与dp[v]的所有值异或的结果
		
		for(int i=0;i<m;i++) dp[u][i]=(dp[u][i]+temp[i])%mod;
	}
	for(int i=0;i<m;i++) ans[i]=(ans[i]+dp[u][i])%mod;
}
int main()
{
	int t,u,v; 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(ans,0,sizeof(ans));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) V[i].clear(); 
		for(int i=1;i<=n;i++) scanf("%d",&val[i]);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			//addedge(u,v);
			//addedge(v,u);
			V[u].push_back(v);
			V[v].push_back(u);
		}
		dfs(1,0);
		for(int i=0;i<m-1;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[m-1]);
	}	
	return 0;
}