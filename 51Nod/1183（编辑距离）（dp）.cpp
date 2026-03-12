#include <bits/stdc++.h>
using namespace std;
int dp[1234][1234];
int main()
{
	string s,t;
	cin>>s>>t;
	int lena=s.length();
	int lenb=t.length();
	for(int i=0;i<=lena;i++)
	{
		dp[0][i] = i;
	}
	for(int i=0;i<=lenb;i++)
	{
		dp[i][0]=i;
	}
	for(int i=1;i<=lena;i++)
	{
		for(int j=1;j<=lenb;j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=min( min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1] )+1;
			}
		}
	}
	cout<<dp[lena][lenb]<<endl;
	return 0;
}