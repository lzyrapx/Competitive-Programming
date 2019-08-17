#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int f[305][305],n,m,i,T,j,dp[350][305],DP[305],b[305],a[305],k;
map <int ,int> mp;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (i=1; i<=n; i++) scanf("%d",&a[i]);
        for (i=1; i<=m; i++)
        {
            scanf("%d",&b[i]);
            mp[b[i]]=1;
        }
        for (i=1; i<=n; i++)
            for (j=i+1; j<=n; j++)
                if (mp[a[j]-a[i]]) f[i][j]=1; else f[i][j]=0;
        for (i=1; i<=n; i++)
          for (j=i; j<=n; j++) dp[i][j]=0;
        for (i=1; i<=n+1; i++) dp[i][i-1]=1;
        for (i=1; i<=n; i++)
            for (j=1; j<=n-i; j++)
        {
            for (k=j; k<j+i; k++)
              dp[j][i+j]|=(dp[j][k]&&dp[k+1][i+j]);
            if (f[j][i+j]) dp[j][i+j]|=dp[j+1][i+j-1];
            for (k=j+1; k<i+j; k++)
                if (f[j][k] &&f[k][i+j] && a[k]+a[k]==a[j]+a[i+j]) dp[j][i+j]|=(dp[j+1][k-1] &&dp[k+1][i+j-1]);
        }
      //  cout<<f[2][3]<<endl;
        for (i=1; i<=n; i++) DP[i]=0;
        for (i=1; i<=n; i++)
        {
            DP[i]=DP[i-1]+1;
            for (j=1; j<i; j++) if (dp[j][i]) DP[i]=min(DP[i],DP[j-1]);
        }
        cout<<n-DP[n]<<endl;
        mp.clear();
    }
    return 0;
}