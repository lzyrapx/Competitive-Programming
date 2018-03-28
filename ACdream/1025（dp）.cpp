#include <bits/stdc++.h>
using namespace std;
int dp[1234567];
int main()
{
	int a,b;
	cin>>a>>b;
	if(a>b)return 0*puts("-1");
	memset(dp,63,sizeof(dp));
    dp[a] = 0;
    for(int i=a;i<=b;i++)
    {
    	for(int j=1;j*j<=i;j++)
    	{
    		if(i%j==0)
    		{
    			dp[i + j] = min (dp[i + j],dp[ i ] + 1);
    			dp[i + i/j] = min( dp[i + i/j] , dp[i] + 1);
			}
		}
	}
	cout<<dp[b]<<endl;
	return 0;
}