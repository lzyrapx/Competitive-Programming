#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 4e5 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;
const ll mod = 998244353;
const ll g = 3; // MOD的原根,当且仅当 g^(MOD-1) = 1 % MOD
ll Pow(ll a, ll n)
{
    ll ans = 1;
    while(n)
	{
        if(n & 1) ans = ans * a % mod;
		n >>= 1;
        a = a * a % mod;
    }
    return ans;
}
void rader(ll y[], int len)
{
    for(int i = 1, j = len / 2; i < len - 1; i++){
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;
        while(j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
void ntt(ll y[], int len, int on) //NTT
{
    rader(y, len);
    for(int h = 2; h <= len; h <<= 1){
        ll wn = Pow(g, (mod-1)/h);
        if(on == -1) wn = Pow(wn, mod-2);
        for(int j = 0; j < len; j += h) {
            ll w = 1;
            for(int k = j; k < j + h / 2; k++) {
                ll u = y[k];
                ll t = w * y[k + h / 2] % mod;
                y[k] = (u + t) % mod;
                y[k+h/2] = (u - t + mod) % mod;
                w = w * wn % mod;
            }
        }
    }
    if(on == -1) {
        ll t = Pow(len, mod - 2);
        for(int i = 0; i < len; i++)
            y[i] = y[i] * t % mod;
    }
}
ll inv[maxn];
ll fac[maxn];
ll f[maxn];
ll inv2;
ll a[maxn], b[maxn];
ll A[maxn];
int n;
void init()
{
    inv2 = Pow(2, mod - 2);
    inv[1] = inv[0] = 1;
    fac[0] = fac[1] = 1;
    for(ll i = 2; i <= 1e5; i++)
	{
        inv[i] = inv[i-1] * Pow(i, mod - 2) % mod;
        fac[i] = fac[i-1] * i % mod;
    }
}
void solve()
{
	for(int i = 0; i < n; i++)
	{
        a[i] = inv[i] * Pow(2, n-i) % mod;
    }
    for(int i = 1; i <= n; i++)
	{
           b[i] = fac[i-1] * A[i] % mod;
    }
    reverse(b+1, b+1+n);
    for(int i = 0; i < n; i++)
	{
        b[i] = b[i+1];
    }
    b[n] = 0;
}
void Conv()
{
	int len = 1;
    while(len <= 2*n) len <<= 1;
    ntt(a, len, 1);
    ntt(b, len, 1);
    for(int i = 0; i < len; i++)
	{
        a[i] = a[i] * b[i] % mod;
    }
    ntt(a, len, -1);
}
void gao()
{
	ll r = inv2;
    for(int i = 1; i <= n; i++)
	{
        f[i] = r * inv[i-1] % mod * a[n-i] % mod;
        f[i] = (f[i-1] + f[i]) % mod;
        printf("%lld ", f[i]);
        r = r * inv2 % mod;
    }
    puts(""); //最后一个数后也有空格..... 
}

int main()
{

    int t;
    scanf("%d", &t);
    init();
    while(t--)
	{ 
        scanf("%d", &n);
        memset(A, 0, sizeof(A));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= n; i++)
		{
            scanf("%lld", &A[i]);
        }
        sort(A+1, A+n+1, greater<ll>()); 
		solve();     
        Conv();        
        gao();
    }
    return 0;
}
