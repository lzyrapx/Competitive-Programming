#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef long long LL;
const long long mod=1000000007;
LL dp[N][N],sum1[N][N],sum2[N][N];
int a[N],b[N];
int main()
{
	int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) dp[i][j]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                if(a[i]==b[j]) dp[i][j]+=dp[i-1][j-1]+1;
                if(dp[i][j]<0) dp[i][j]+=mod; //注意要加 mod，因为上面的dp有可能会减成负数 
                if(dp[i][j]>=mod) dp[i][j]%=mod;
            }
        }
       printf("%I64d\n",dp[n][m]);
    }
    return 0;
}