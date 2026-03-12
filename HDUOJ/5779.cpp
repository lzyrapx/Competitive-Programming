#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=65;
const int mod=1000000007;

int dp[N][N][N];
int p2[N*N];
int pp[N][N];
int C[N][N];

void init(){
	for(int i=0; i < N ; i++)
	{
		C[i][i] = C[i][0] = 1;
		for(int j = 1 ; j < i; j++)
		{
			C[i][j] = ( C[i-1][j-1] + C[i-1][j] )%mod;
		}
	}
	p2[0] = 1;
	for(int i = 1; i < N*N; i++)
	 	p2[i] = p2[i-1] * 2 % mod;
	 	
	 	for(int i = 0; i < N; i++)
	 	{
	 		pp[i][0] =1;
	 		for(int j = 1; j < N; j++)
	 		{
	 			pp[i][j]= 1LL * pp[i][j-1] * ( p2[i]-1 ) % mod;
			 }
		 }
		 dp[1][1][1] = 1;
		 for(int i = 2; i < N; i++){
		 	for(int j = i; j < N; j++){
		 		for(int k = 1; k < j; k++)
		 		{
		 			for(int u=1; u+k <= j; u++)
		 			{
		 				dp[i][j][k] +=1LL*dp[i-1][j-k][u] *pp[u][k] % mod*p2[k*(k-1)/2] %mod * C[j-1][k]%mod;
		 				if(dp[i][j][k] >= mod) dp[i][j][k]-=mod;
					 }
				 }
			 }
		 }
}

int main()
{
    init();
    int n,k;
	int t; 
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int ans=0;
        for(int i = 1; i<=k; i++)
        {
        	for(int d = 1; d <= n; d++)
        	{
        		for(int j = 1; j <= d; j++)
        		{
        			ans+= 1LL*dp[i][d][j]*C[n-1][d-1] % mod * p2[(n-d)*(n-d-1)/2] % mod;
        			if(ans >= mod) ans -= mod;
				}
			}
		 }
		 printf("%d\n",ans); 
    }
    return 0;
}  