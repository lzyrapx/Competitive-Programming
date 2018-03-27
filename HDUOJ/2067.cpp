#include<stdio.h>
typedef long long ll;
int main()
{
	ll n,dp[36][36],cas=1;;
	dp[0][0]=0;
	dp[1][1]=1;
	for(int i=1;i<=35;i++)
	{
		dp[0][i]=1;
	}
	for(int i=1;i<=35;i++)
	{
		dp[i][i]=dp[i-1][i];
		for(int j=i+1;j<=35;j++)
		{
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
		}
	}
	while(~scanf("%I64d",&n)&&n!=-1)
	{
		printf("%I64d %I64d %I64d\n",cas++, n, 2*dp[n][n]);
	}
	return 0;
}