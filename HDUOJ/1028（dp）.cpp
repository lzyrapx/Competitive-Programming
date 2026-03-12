#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int dp[122][122]={0};
	int n;
	for(int i=0;i<121;i++)
    {
    	dp[i][0]=1;
		dp[i][1]=1;
		dp[0][i]=1;
		dp[1][i]=1;
	}
    for(int i=2;i<121;i++)
		for(int j=2;j<121;j++){
			if(i>=j)
			 	dp[i][j]=dp[i][j-1]+dp[i-j][j];
		   else   
		 		dp[i][j]=dp[i][i];
		}
 		
		while(scanf("%d",&n)==1)
		printf("%d\n",dp[n][n]);
 
	return 0;
}