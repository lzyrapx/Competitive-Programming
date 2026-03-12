#include <bits/stdc++.h>
using namespace std;
int dp[123456];//dp[i]表示长度为i的上升子序列的最小结尾
int a[123456];
int main()
{
	int n,len=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>dp[len]) dp[++len]=a[i];
		else{
			int pos=lower_bound(dp+1,dp+len,a[i])-dp;
			dp[pos]=a[i];
			
		}
	}
	cout<<len<<endl;
	return 0;
}