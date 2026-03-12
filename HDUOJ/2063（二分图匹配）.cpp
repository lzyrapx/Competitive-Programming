#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
int mp[maxn][maxn];       
int vis[maxn];            
int match[maxn];
int k,m,n;
int find(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(vis[i]==0&& mp[i][x])
        {
            vis[i]=1;
            if(match[i]==-1||find(match[i]))
            {
                match[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    while(~scanf("%d",&k))
    {
        if(k==0)break;
        scanf ("%d%d", &m, &n);
        memset (mp, 0, sizeof (mp));
        memset (match, -1, sizeof (match));
        for(int i=0;i<k;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a][b]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))
            ans++;
        }
        printf("%d\n",ans);
    }
}
