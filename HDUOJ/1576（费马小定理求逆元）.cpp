#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;

//要求(A/B)%9973，但由于A很大，
//我们只给出n(n=A%9973)(我们给定的A必能被B整除，且gcd(B,9973)=1)。

//(a/c)%mod = (a*inv)%mod

ll q_mod(ll a,ll n)
{
	ll ans=1;
	while(n)
	{
		if(n&1)ans=ans*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans;
}
//x*x^(p-2)≡1(mod p)，x^(p-2)即为逆元，p为素数
int main()
{
	int t;
	int n,B;
	cin>>t;
	while(t--)
	{
		cin>>n>>B;
		ll x = q_mod(B,mod-2);//x为逆元 
		printf("%lld\n",n*x%mod); 
	}
	return 0;
}