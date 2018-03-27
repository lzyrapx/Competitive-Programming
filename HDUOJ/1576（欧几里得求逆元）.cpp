#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;
ll exgcd(int a,int b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int res=exgcd(b,a%b,x,y);
    int t=x;x=y;y=t-(a/b)*y;
    return res;
}
ll mod_inv(ll a,ll mod)
{
	ll x,y;
	ll GCD = exgcd(a,mod,x,y);
	if(GCD==1)return (x%mod+mod)%mod;
	else return -1;
}
//要求(A/B)%9973，但由于A很大，
//我们只给出n(n=A%9973)(我们给定的A必能被B整除，且gcd(B,9973)=1)。

//(a/c)%mod = (a*inv)%mod
int main()
{
	int t;
	int n,B;
	cin>>t;
	while(t--)
	{
		cin>>n>>B;
		int x = mod_inv(B,mod); //x就是逆B的逆元 
		cout<<n*x%mod<<endl;
	}
	return 0;
}