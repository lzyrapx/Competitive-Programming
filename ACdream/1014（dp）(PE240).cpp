/*
* this code is made by LzyRapx
* Problem: 1014
* Verdict: Accepted
* Submission Date: 2017-07-04 11:23:55
* Time: 20MS
* Memory: 6144KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[21][13][21][100];
//dp[n][m][k][p]表示考虑有 n 个骰子时，选 k个骰子中的 m个面的和为 p的方案数 
int main()
{
   ll n,m,k,p;
   while(cin>>n>>m>>k>>p)//20 12 10 70
   {
  		memset(dp,0,sizeof(dp));
  		dp[0][m][0][0] = 1;
  		for(int i=1;i<=n;i++)
		{
    		for(int j=1;j<=m;j++)
			{
      			for(int s=0;s<=i;s++)
				{
        			for(int x=0; x<=p; x++)
					{
        				if(dp[i-1][j][s][x]==0) continue;
        				for(int l=1;l<=j;l++)
						{
							int sum;
							if(i<=k){
								sum = x+l;
							}
							else sum = x;
							
        					int new_k = 0;
        					if(l==j){
        						new_k = s + 1;
							}
							else{
								new_k = 1;
							}
								
        					if (sum <= p)
							{
            					dp[i][l][new_k][sum] += dp[i-1][j][s][x] * i / new_k;
            				}
          				}
        			}
      			}
    		}
  		}
  		ll ans = 0;
  		for(int i=1;i<=m; i++)
	  	{
    		for(int j=1;j<=n;j++)
			{
      			ans += dp[n][i][j][p];
    		}
  		}
  		cout<<ans<<endl;
   }
  	return 0;
}