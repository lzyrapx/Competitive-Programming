#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in freopen("in.txt","r",stdin)
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--) 
const int maxn = 1010;
const int mod = 1e9+7;
const ll INF =1000000000LL*100000000LL;
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int dp[maxn][maxn], sum[maxn][maxn];
int val[maxn], w[maxn];
bool vis[maxn];
int ans[maxn];
int n, cost;
int main()
{
    int t;
    int cas=0;
    t=read();
    while(t--)
    {
        cost=read(),n=read();
        for (int i=0; i<n; i++)
        {
            scanf("%d%d", &val[i], &w[i]);
        }      
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<w[i]; ++j)
            {
                dp[i+1][j] = dp[i][j];
                sum[i+1][j] = sum[i][j];
            }
            
            for(int j=w[i]; j<=cost; j++)
            {
                int temp = dp[i][j-w[i]]+val[i];
                if (dp[i][j] > temp)
                {
                    dp[i+1][j] = dp[i][j];
                    sum[i+1][j] = sum[i][j];
                }
                else if (dp[i][j] < temp)
                {
                    dp[i+1][j] = temp;
                    sum[i+1][j] = sum[i][j-w[i]]+i+1;
                }
                else
                {
                    dp[i+1][j] = dp[i][j];
                    if (sum[i][j] <= sum[i][j-w[i]]+i+1)
                    {
                            sum[i+1][j] = sum[i][j];
                    }    
                    else sum[i+1][j] = sum[i][j-w[i]]+i+1;
                }
            }
        }
        for (int i=n-1; i>=0; --i)
        {
            if (dp[i][cost]==dp[i+1][cost] && sum[i][cost]==sum[i+1][cost])
                vis[i] = false;
            else {
                vis[i] = true;
                cost -= w[i];
            }
        }
        int Ans=0, Res=0;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==true)
            {
                Ans += val[i];
                Res += w[i];
                ans[cnt++] = i+1;
            }
        }    
        printf("Case #%d:\n", ++cas);
        printf("%d %d\n", Ans, Res);
        for (int i=0; i<cnt; i++)
        {
            printf("%d%c", ans[i]," \n"[i==cnt-1]);    
        }           
    }
    return 0;
}