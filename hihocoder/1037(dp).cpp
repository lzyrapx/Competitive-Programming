#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()
{
    int t,maxx=0;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        for(int j=1; j<=i; j++)
        {
            scanf("%d",&dp[i][j]);
            dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
            maxx=max(maxx,dp[i][j]);
        }
    }
    printf("%d\n",maxx);
}