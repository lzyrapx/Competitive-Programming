#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm> 
using namespace std;
typedef long long LL;
const int mod =998244353;
const int N=100005;
int b[N];
int c[N];
LL dp[N];
//题意:;在由 1 - n 中的数字组成的n个谷堆，假设前 i 个谷堆的最大值是C[i],最小值是B[i]
//现在知道这n堆谷堆前所有前缀的最大值和最小值,问这些谷堆总共有多少种组成方式?
//题解:递推,排除掉5种不可能的情况,1.b[i]>b[i-1] 2,c[i]<c[i-1] 3,b[i]>c[i] 4.c[1]!=b[1] 5.b[i],c[i] < 1 || > n ,
//然后递推,如果当前产生的新的 b[i]或者 c[i] 那么dp[i] = dp[i-1] ，
//如果当前 b[i-1] = b[i] && c[i-1] = c[i] ，那么我们可以在 [b[i],c[i]]中任选一个数,
//但是由于谷堆是互不相同的,所以每次我们的选项都会变少,
//弄个计数器计算一下当前已经选了多少种,减掉之后答案即为 dp[i] = dp[i-1]*(c[i]-b[i]+1-num)
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	int n;
    	scanf("%d",&n);
    	int Min=999999;
    	int Max=-1;
    	int flag=1;
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&b[i]);
    		if(b[i]>Min) flag=0;
    		if(b[i]<1||b[i]>n) flag=0;
    		Min=min(Min,b[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			if(c[i]<Max)flag=0;
			if(c[i]<1||c[i]>n) flag=0;
			if(c[i]<b[i]) flag=0;
			Max=max(Max,c[i]);
			
		}
		if(!flag||c[1]!=b[1]) puts("0"); //前 1个的最大最小值一定相等 ，都是这个数嘛 
		else
		{
			memset(dp,0,sizeof(dp));
			dp[1]=1;
			int num=1;
			for(int i=2;i<=n;i++) //dp核心 
			{
				if(c[i]==c[i-1]&&b[i]==b[i-1]&&b[i]!=c[i])
				{
					dp[i]=dp[i-1]*(c[i]-b[i]+1-num)%mod;
				}
				else if( b[i]<b[i-1]&&c[i-1]==c[i] || b[i]==b[i-1]&&c[i-1]<c[i] )
				{
						//dp[i] = dp[i-1]+1;
						dp[i]=dp[i-1];
				}
					num++; //已经选了多少种
			}
		  printf("%I64d\n",dp[n]);
		}
	}
    return 0;
}