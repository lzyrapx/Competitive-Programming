#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1000000000;
int dp[6200];
int fa[6200];
int a[6200];
int digit[20] ;
int check(ll x)
{
     int num = 0;
     while(x)
	 {
           digit[num++] = x % 10 ;
           x /= 10 ;
     }
     for(int i = num-1 ; i >= 1 ; --i){
          if(digit[i] == 6 && digit[i-1] == 1) 
		  return 1 ;
     }
     return 0 ;
}
void init()
{
	int num = 0;
    fill(dp,dp+6170,inf);
	memset(fa,-1,sizeof(fa));
	for(int i=1;i<=6161;i++)
	{
		if(check(i))
		{
			a[num++] = i;
		}
	}
	dp[0] = 0;
	for(int i=1;i<=6161;i++)
	{
		for(int j=0;j < num && i >= a[j];j++)
		{
			if(dp[i] > dp[i-a[j]] + 1)
			{
				dp[i] = dp[i-a[j]] + 1;
				fa[i] = i - a[j];
			}
		}
	}
}
void print(int x)
{
	if(x)
	{
		print(fa[x]);
		printf(" %d",x-fa[x]);
	}
}
int main()
{
	init();
	int t;
	ll n,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(check(n)) printf("1 %lld\n" , n) ;
		/*
		当n<6100时,可以形成的最少的形式为
		x61x
		xx61
		*/
		else if(n <= 6161)
		{
            if(dp[n] == inf) printf("0") ;
            else 
			{
				printf("%d" , dp[n]);
				print( (int)n ) ;
			}
            puts("") ;
        }
        /*
        当n>=6161时,该数一定可以分解成两个数形式分别是比如说为5位数
		xxx..xxx61
		61xx
		n = xxx..xxx61 + 61xx
        */
        else
		{
            x = 6100 ;
            y = 61 ;
            n -= 6161 ;
            x += (n%100) ;
            y += (n/100*100) ;
            printf("2 %lld %lld\n" , x , y) ;
        }
	} 
	return 0;
}