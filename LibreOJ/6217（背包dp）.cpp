#include<bits/stdc++.h>
using namespace std;
int a[1234],b[1234];
int dp[1234];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=0;i<=n;i++)dp[i] = 0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=a[i];--j)
		{
			dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}