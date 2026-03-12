#include <bits/stdc++.h>
using namespace std;
const int mod=2008;
int f[10010];
typedef long long ll;
int q_mod(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int solve(int n)
{
    if(n==1)return 2;
    int ans=q_mod(2,n);
    ans-=2;
    ans%=mod;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i!=0)continue;
        if(i*i==n)
        {
            ans-=solve(i);
            ans%=mod;
        }
        else
        {
            ans-=solve(i);
            ans-=solve(n/i);
            ans%=mod;
        }
    }
    return (ans+mod)%mod;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		cout<<solve(n)<<endl;
	}
	return 0;
}