#include<bits/stdc++.h>
using namespace std;
const int N = 89;
char num[67][N];
char dp[62][62][62][N];

//设函数dp[i][j][k]表示该序列中有i个A，j个B，k个C组成的方案数 
//则dp[i][j][k]是有dp[i-1][j][k]，dp[i][j-1][k]，dp[i][j][k-1]这三个添加过来的，所以动态转移方程式:
//dp[i][j][k]=dp[i-1][j][k]+dp[i][j-1][k]+dp[i][j][k-1]；
//同时注意，dp的结果很大，要用到大数。

void sum(char a[N],char b[N])
{
	int n = a[0];//a的位数 
	int m = b[0];//b的位数 
	int k = 0;
	a[0] = k = max(n,m);
	for(int i=1;i<=k;i++)
	{
		a[i] += b[i];
		if(a[i] > 9)
		{
			a[i+1]++;
			a[i] %= 10;
			if(i+1>k)
			{
				k++;
				a[0]++;//位数 
			}
		}
	}
} 
void Copy(char a[N],char b[N])
{
	for(int i=0;i<=b[0];i++)
	{
		a[i]=b[i];
	}
}
int main()
{	
	memset(dp,0,sizeof dp);
	dp[0][0][0][0] = dp[0][0][0][1] = 1;
	for(int i=1;i<=60;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=j;k++)
			{
				//dp[i][j][k]=dp[i-1][j][k]+dp[i][j-1][k]+dp[i][j][k-1], i>=j>=k 
				if(i-1>=0 && i-1>=j && j>=k)
				{
					sum(dp[i][j][k],dp[i-1][j][k]);  
				}
				if(j-1>=0 && i>=j-1 && j-1>=k)
				{
					sum(dp[i][j][k],dp[i][j-1][k]);
				}
				if(k-1>=0 && i>=j && j>=k-1)
				{
					sum(dp[i][j][k],dp[i][j][k-1]);
				}
	     		if(i==j && j==k)
	     		{
	     			//设num[i]表示当n为i时的结果，即当i==j==k时的结果。
					//(注意：把dp和num都定义成char型数组，否则会超存)。
	     			Copy(num[i],dp[i][j][k]);
				}
			}
		}
	}
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=num[n][0];i>0;--i)
		{
			printf("%d",num[n][i]);
		}
		puts("\n");
	}
	return 0;
} 