#include <bits/stdc++.h>
using namespace std;
const int maxn =100010;
int n, ans;
int a[maxn];
map<int, int> mp[maxn];
vector<int> edge[maxn];

void dfs(int u, int fa)
{
	if(a[u] > 1) ++mp[u][a[u]];
	for(int i=0;i<edge[u].size();i++) 
	{
		int v = edge[u][i];
		if(v == fa) continue;
		dfs(v, u);
		for(auto p : mp[u])
		{
			for(auto t : mp[v])
			{
				if(__gcd(p.first, t.first) > 1)
				{
					ans = max(ans, p.second + t.second);
				}
			}
		}	
		for(auto t : mp[v])
		{
			int g = __gcd(t.first, a[u]);
			if(g > 1){
				mp[u][g] = max(mp[u][g], t.second + 1);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}