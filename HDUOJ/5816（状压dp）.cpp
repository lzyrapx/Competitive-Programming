#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
ll fact[22]={1};
ll dp[1<<20];
int p,n,m,N,x[22];
 
int main()
{
//	freopen("in.txt","r",stdin);
    for(int i=1; i<22; ++i) fact[i]=fact[i-1]*i; //全排列数 
    int t; 
    t=read();
    while(t--)
	{
        p=read(),n=read(),m=read();
        N=n+m;
        for(int i=n; i<N; ++i)
		{          
            x[i]=read();
        }   
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int s=0; s<(1<<N); ++s)
		{
            if(dp[s]==0) continue;
            
            int A=0,B=0,injure=0;
            for(int i=n; i<N; ++i)
			{
                if((s>>i) & 1)
				{
                    injure+=x[i];   //计算伤害值 
                    ++B;
                }
            }
            if(injure>=p) continue; //不用继续摸牌了

            for(int i=0; i<n; ++i)
			{
                if( (s>>i) & 1) 
				++A;
            }
            
            if(A-B+1<=0) continue; //不用继续摸牌了
            
            for(int i=0; i<N; ++i)
			{
                if((s>>i) & 1) continue;
                dp[s^(1<<i)]+=dp[s];
            }
        }  
             
        ll xx=0, yy=fact[N];
        
        for(int s=0; s<(1<<N); ++s)
		{
            if(dp[s]==0) continue;
            
            int A=0,B=0,injure=0;
            for(int i=n; i<N; ++i)
			{
                if((s>>i) & 1)
				{
                    injure+=x[i];
                    ++B;
                }
            }
            for(int i=0; i<n; ++i)
			{
                if((s>>i) & 1) 
				++A;
            }
            //s能造成的伤害大于等于p
            if(injure>=p)
			{
				//计算贡献
                xx+=dp[s]*fact[N-A-B];
            }
        }
         ll g=__gcd(xx,yy);
        printf("%I64d/%I64d\n",xx/g,yy/g);
    }
    return 0;
}