/*
* this code is made by LzyRapx
* Problem: 1007
* Verdict: Accepted
* Submission Date: 2017-06-22 17:43:18
* Time: 176MS
* Memory: 1664KB
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 10000000007LL;
//快速幂的乘法会爆longlong ，用快速乘即可。
ll Multi(ll a, ll b)//a*b
{
    ll ans = 0;
    while(b)
    {
        if(b&1){
            ans = (ans + a) % mod ;
        }
        a = (a<<1) % mod;
        b>>=1;    
    }
    return ans%mod ;
}
 
ll BigMulti(ll ans , ll K)
{
    if(ans == 0 && K ==0)return 1;
    if(ans == 0)return 0;
     
    ll res = 1;
    while(K)
    {
        if(K&1){
            res = Multi(ans,res);
        }
        ans = Multi(ans , ans);
        K >>= 1; 
    }
    return res%mod ;
}
ll N,K;
int main()
{
    int t ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&N,&K);
        ll res = 0, ans;
        for(int i=1;i<=N;i++)
        {
            scanf("%lld",&ans);
            ans %= mod;
            ans = (ans + mod ) % mod;
            res = (res + BigMulti(ans,K)%mod + mod) % mod; 
        }
        printf("%lld\n",res); 
    }
    return 0;
 }