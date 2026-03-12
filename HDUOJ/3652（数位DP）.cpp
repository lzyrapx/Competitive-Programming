#include<stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[11][3][13],bit[12];
//计算 mod 13 余数为 0 的数位DP 
//dp[i][j][k] : i 表示位数 ，j 表示 是否存在1,3的 3 种情况， k表示 余数 
void init()
{
	int i,j,k;
	bit[1]=1;
	for(i=2;i<11;i++)
	{
		bit[i]=bit[i-1]*10; //m[i]=m[i-1]*10%13; 
	}
	dp[0][0][0]=1;
	for(i=1;i<=11;i++) //位数 
	{
		for(j=0;j<=12;j++) //枚举第 i 位 
		{
			for(k=0;k<10;k++) //枚举第 i-1 位 
			{
				dp[i][0][(j+k*bit[i])%13]+=dp[i-1][0][j];
				dp[i][2][(j+k*bit[i])%13]+=dp[i-1][2][j];
			}
			dp[i][0][(j+bit[i])%13]-=dp[i-1][1][j];
			dp[i][1][(j+bit[i]*3)%13]+=dp[i-1][0][j];
			dp[i][2][(j+bit[i])%13]+=dp[i-1][1][j];
		}
	}
}

int solve(int n)
{
	int digit[15],i,j,ans=0,cnt=0,flag=0,mod=0;
	
	while(n) //计算各位上的数据 
	{
		digit[++cnt]=n%10;
		n/=10;
	}
	
	digit[cnt+1]=0;//让最高前位置0 ，这一步非常重要，
	for(i=cnt;i>=1;mod=(mod+digit[i]*bit[i])%13,--i)
	{
		for(j=0;j<digit[i];j++)
		{
			ans+=dp[i-1][2][(13-(mod+j*bit[i])%13)%13];
		}
		if(flag)
		{
			for(j=0;j<digit[i];j++)
			{
				ans+=dp[i-1][0][(13-(mod+j*bit[i])%13)%13];
			}
		}
		else if(digit[i]>1) //(x+m[i]+mod)%13=0,求x%13
		{
			ans+=dp[i-1][1][(13-(mod+bit[i])%13)%13];
			if(digit[i+1] == 1 && digit[i]>3)
			{
				ans+=dp[i][1][(13-mod)%13];
			}
		}
		if(digit[i] == 3 && digit[i+1] == 1)
		{
			flag=1;
		}
	}
	return ans;
}

int main()
{
	int n;
	init();
	while(~scanf("%d",&n))
	{
		printf("%d\n",solve(n+1)); //0到 n 
	}
	return 0;
}