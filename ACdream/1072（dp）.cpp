/*
* this code is made by LzyRapx
* Problem: 1072
* Verdict: Accepted
* Submission Date: 2017-07-17 10:46:29
* Time: 528MS
* Memory: 2132KB
*/
//设dp[t][u][i][j]表示在时间 t 时在地图上 u 位置上用了 i 次技能并且这时的技能还需要 j 的冷却时间。 
//注意有坑： 
//会有输入相同的时间和位置。
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int N,M,T,K,B;
const int maxn =55;
int mp[maxn][maxn];
int val[maxn][maxn];
int dp[maxn][maxn][6][6];
int sv[maxn][maxn];
int solve()
{
    memset(dp,0xff,sizeof(dp));
    memset(sv,0,sizeof(sv));
    for(int i=1;i<=T;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                if(mp[j][k] != -1 || j == k)
                {
                    sv[i][j] += val[i][k];
                }
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        dp[1][i][B][0] = val[1][i];
        if(B)
        {
            dp[1][i][B-1][5] = sv[1][i];
        }
    }
    for(int t=1;t<=T;t++)
    {
        for(int u=1;u<=N;u++)
        {
            for(int i=0;i<=B;i++)
            {
                for(int j=0;j<=5;j++)
                {
                    if(dp[t][u][i][j]==-1) continue;
                     
                    dp[t+1][u][i][ max(j-1, 0)] = max(dp[t+1][u][i][ max(j-1, 0)],dp[t][u][i][j] + val[t+1][u]);
                     
                    if(i > 0 && j - 1 <= 0)
                    {
                        dp[t+1][u][i-1][5] = max(dp[t+1][u][i-1][5] , dp[t][u][i][j] + sv[t+1][u]); 
                      
                    }
                    for(int v=1;v<=N;++v)
                    {
                        if(mp[u][v] == -1 || u == v) continue;
                        if(t + mp[u][v] > T) continue;
                        int nt = t + mp[u][v];
                        dp[nt][v][i][max(j - mp[u][v], 0)] = max(dp[nt][v][i][max(j - mp[u][v], 0)],dp[t][u][i][j] + val[nt][v]);
                         
                        if( i > 0 && j - mp[u][v] <= 0)
                        {
                            dp[nt][v][i-1][5] = max(dp[nt][v][i-1][5],dp[t][u][i][j] + sv[nt][v]);
                        }
                             
                    }
                }
            }
        }
    }
    int Max=0;
    for(int u=1;u<=N;u++)
    {
        for(int i=0;i<=B;i++)
        {
            for(int j=0;j<=5;j++)
            {
                if(dp[T][u][i][j] > Max) 
                {
                    Max=dp[T][u][i][j];
                }
            }
        }
    }                 
    return Max;
}
int main()
{
    int t;
     
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&N,&M,&T,&K,&B);
        memset(val,0,sizeof(val));
        memset(mp,999999999,sizeof(mp));
        int u,v,w;
        for(int i=1;i<=M;i++){
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v]=w;
            mp[v][u]=w; 
        }
        for(int i=1;i<=K;i++){
            scanf("%d%d%d",&u,&v,&w);
            val[u][v]+=w;//坑点 
        }
        int ans = solve();
        printf("%d\n",ans);
    } 
    return 0;
}