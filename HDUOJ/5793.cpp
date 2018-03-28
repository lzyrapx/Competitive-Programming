#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

ll q_mod(ll a,ll n)
{
    ll ans=1;
    while(n){
        if(n&1)ans=ans*a%mod;
        n>>=1;
        a=a*a%mod;  
    }
    return ans;
}
int main()
{
    int t;
	scanf("%d",&t);
    while(t--){
        ll n,m;
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",(q_mod(m,n+1)-1)*q_mod(m-1,mod-2)%mod);
    }
    return 0;
}