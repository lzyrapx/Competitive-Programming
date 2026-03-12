#include<bits/stdc++.h>
using namespace  std;
int dp[100][100];
int main()
{
		int n,m;
        while(scanf("%d",&n)!=EOF)
        {
            while(n--)
            {
                scanf("%d",&m);
                for(int i=0;i<m;i++)
                for(int j=0;j<=i;j++)
                scanf("%d",&dp[i][j]);

                for(int i=m-2;i>=0;i--)
                {
                    for(int j=0;j<=i;j++)
                        dp[i][j]=max(dp[i][j]+dp[i+1][j],dp[i][j]+dp[i+1][j+1]);
                }
                printf("%d\n",dp[0][0]);
            }
        }
        return 0;

} 