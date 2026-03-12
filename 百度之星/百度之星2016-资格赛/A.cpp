#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
typedef long long LL;
using namespace std;
const LL maxn=1e5+10;
const LL mod =9973;
LL dp[maxn];
string s;
LL q_mod(LL a,LL b)
{
	LL sum=1;
	while(b)
	{
		if(b&1)
		sum=(sum*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return sum;
}
int main()
{
	LL n;
	LL l,r; 
	while(~scanf("%I64d",&n))
	{
		cin>>s;
		dp[0]=1;
		for(LL i=1;i<=s.length();i++) //懵逼写了1，结果WA 了2次... 
		{
			dp[i]=(dp[i-1]*(s[i-1]-28))%mod;
		}		 
        for(LL i=0; i<n; i++)  
        {  
            scanf("%I64d%I64d",&l,&r);  
            if(l>r)  
            {  
                swap(l,r);  
            }  
            printf("%I64d\n",(dp[r]*(q_mod(dp[l-1],mod-2)%mod))%mod); 
        }  
	}
	return 0;
}