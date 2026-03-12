#include<bits/stdc++.h>
using namespace std;
vector<int> tree[100005];
int n;
int ans;
bool vis[100005];
int k[100005],fa[100005];
int dfs(int x)
{
    int now=0;
    for(int i=0;i<tree[x].size();i++)
    {
    	int Fa = tree[x][i];
    	if(Fa==x)continue;
        if(vis[tree[x][i]]) continue;
        vis[tree[x][i]] = true;
        now = max(now, dfs(tree[x][i]));
    }
   // cout<<"now="<<now<<endl;
    if(now<=1)
    {
        ans++;
        return k[x];
    }
    k[fa[x]] = max(k[fa[x]] , k[x]-1);
    return now-1;
}
int main()
{
    int a;
    ans = 0;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>a;
        fa[i]=a;
        tree[a].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
    }
    vis[1] = true;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}