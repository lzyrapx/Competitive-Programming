#include <bits/stdc++.h>
using namespace std;
long long dp[1001][1001];
int main()
{
	int n,m;
	cin>>n>>m;
	dp[1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}