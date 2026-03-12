#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll A[1<<20],B[1<<20];
void rader(ll A[], int len)
{
    for(int i = 1, j = len / 2; i < len - 1; i++){
        if(i < j) swap(A[i], A[j]);
        int k = len / 2;
        while(j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
void ntt(ll A[], int len, int on) //NTT
{
    rader(A, len);
    for(int h = 2; h <= len; h <<= 1){
        ll wn = Pow(g, (mod-1)/h);
        if(on == -1) wn = Pow(wn, mod-2);
        for(int j = 0; j < len; j += h) {
            ll w = 1;
            for(int k = j; k < j + h / 2; k++) {
                ll u = A[k];
                ll t = w * A[k + h / 2] % mod;
                A[k] = (u + t) % mod;
                A[k+h/2] = (u - t + mod) % mod;
                w = w * wn % mod;
            }
        }
    }
    if(on == -1) {
        ll t = Pow(len, mod - 2);
        for(int i = 0; i < len; i++)
            A[i] = A[i] * t % mod;
    }
}
int n,m;
void Conv()
{
	int len = 1;
    while(len <= 2*n) len <<= 1;
    ntt(A, len, 1);
    ntt(B, len, 1);
    for(int i = 0; i < len; i++)
	{
        A[i] = A[i] * B[i] % mod;
    }
    ntt(A, len, -1);
}
//输入两个多项式，输出这两个多项式的乘积。

/*
输入： 
第一行两个整数 n 和 m ，分别表示两个多项式的次数。
第二行 n+1个整数，分别表示第一个多项式的 0到 n次项前的系数。
第三行 m+1个整数，分别表示第二个多项式的 0到 m次项前的系数
输出：
一行 n+m+1个整数，分别表示乘起来后的多项式的 0到n+m次项前的系数。 
*/
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)scanf("%lld",&A[i]);
	for(int i=0;i<=m;i++)scanf("%lld",&B[i]);
	Conv();
	for(int i=0;i<=n+m;i++){
		printf("%lld ",A[i]);
	}
	puts("");
	return 0;
}