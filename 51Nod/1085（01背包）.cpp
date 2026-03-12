#include <bits/stdc++.h>
using namespace std;
int dp[123][12345];
int w[123];
int v[123];
int main()
{
	int n,V;
	cin>>n>>V;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=V;j++)
		{
			if(j>=w[i])
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][V]<<endl;
	return 0;
}
