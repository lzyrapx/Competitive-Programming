#include<bits/stdc++.h>
using namespace std;
const int MAXN=40;
const int mod=1e9+7;
long long  fact[MAXN*MAXN],C[MAXN][MAXN],dp[MAXN][MAXN];

void init()
{
	fact[0]=1;
	for(int i=1;i<=110;++i) fact[i]=fact[i-1]*3%mod;
	C[0][0]=1;
	for(int i=1;i<MAXN;++i)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=1;i<=10;++i)
	{
		for(int j=0;j<=10;++j)
		{
			dp[i][j]=fact[i*j];
			if(i==1&&j==0) dp[i][j]=1;
			for(int n=1;n<=i;++n)
			{
				for(int m=0;m<=j;++m)
				{
					if(i==n&&j==m) continue;
					dp[i][j]-=C[i-1][n-1]*C[j][m]%mod*dp[n][m]%mod*fact[(i-n)*(j-m)]%mod;
					dp[i][j]=(dp[i][j]%mod+mod)%mod;
				}
			}
		}
	}
	
}
int main()
{
	int m,n;
	init();
	while(~scanf("%d%d",&n,&m)) 
		printf("%I64d\n",dp[n][m]);
	return 0;
}