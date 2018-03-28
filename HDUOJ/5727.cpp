#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
vector<int>e[10];
int mp[10][10];
int linker[10];
int vis[10];
int pos[10];
//给你2*n颗宝石，其中n颗阳宝石，n颗阴宝石，
//让你阴阳间隔（阳和阴必须相邻）串在项链上（围成一个环）,还给你了m对x,y，
//表示如果阳宝石x和阴宝石y挨在一起，阳宝石就会受影响，
//让你求出阳宝石受影响的最少数量。 
int dfs(int u)
{
    for (int i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        if (!vis[v])
        {
            vis[v]=1;
            if (linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m,ans;
    while (scanf ("%d%d",&n,&m)!=EOF)
    {
        memset(mp,0,sizeof(mp));
        while (m--)
        {
            int t1,t2;
            scanf ("%d%d",&t1,&t2);
            mp[t1][t2]=1;
        }
        if (n==0)
        {
            printf ("0\n");
        }
        else
        {
            ans=10;
            for (int i=1; i<=n; i++)
                pos[i]=i;
            do
            {
                for (int i=1; i<=n; i++) e[i].clear();
                for (int i=1; i<=n; i++)	//加边,i是阴槽，阳
                {
                    int u=pos[i];
                    int v;
                    if (i==n) v=pos[1];
                    else v=pos[i+1];
                    for (int j=1;j<=n;j++)	//对于每一个阳球，阴
                    {
                        if (mp[j][u]||mp[j][v]) continue;//阳阴不冲突
                        e[j].push_back(i);	//阳球进入阴槽
                    }
                }
                int temp=0;
                memset(linker,-1,sizeof(linker));
                
                for (int i=1; i<=n; i++)//匈牙利最大匹配
                {
                    memset(vis,0,sizeof(vis));
                    if (dfs(i)) temp++;
                }
                ans=min(ans,n-temp);
                if (ans==0) break;
            }while(next_permutation(pos+2,pos+n+1));
            printf ("%d\n",ans);
        }
    }
    return 0;
}