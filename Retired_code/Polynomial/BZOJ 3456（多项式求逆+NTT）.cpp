#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int maxLen = 18, maxm = 1 << maxLen | 1;
const ll maxv = 1e10 + 6; // 1e14, 1e15
const int N = 1000000;
const long double pi = acos(-1.0); // double maybe is not enough
ll mod = 1004535809, nlim, sp, msk;

ll qpower(ll x, ll p) { // x ^ p % mod
	ll ret = 1;
	while (p) {
		if (p & 1) (ret *= x) %=mod;
		(x *= x) %=mod; 
		p >>= 1;
	}
	return ret;
}
int R[N];
int G = 3;
void NTT(int *a,int f,int n,int L)
{
    for(int i = 0;i < n; i++) {
		R[i] = (R[i>>1]>>1)|((i&1)<<(L-1));
	}
    for(int i = 0;i < n;i++) {
        if(i < R[i]) swap(a[i],a[R[i]]);
	}
    for(int i = 1;i < n;i <<= 1) 
    {
        int wn = qpower(G,(mod-1)/(i<<1));
        if(f==-1) wn = qpower(wn,mod-2);
        for(int j = 0;j < n;j += (i<<1))
		{
            int w=1;
            for(int k = 0; k < i; k++,w = 1LL * w * wn % mod)
			{
                int x=a[j+k];
				int y=1LL*a[j+k+i]*w%mod;
                a[j+k]=(x+y)%mod;
                a[j+k+i]=(x-y+mod)%mod;
            }
        }
    }
    if(f==-1){
        int tmp = qpower(n,mod-2);
        for(int i = 0;i < n;i++) 
        {
			a[i] = 1LL * a[i] * tmp % mod;
		}
    }
}
int d[N];
void ployInv(int *a,int *b,int n,int L){
    if(n == 1){
        b[0] = qpower(a[0],mod - 2);return;
    }
    ployInv(a,b,n >> 1,L - 1);
    memcpy(d,a,n*sizeof(int));
    memset(d + n,0,n*sizeof(int));
    NTT(d,1,n << 1,L + 1);
	NTT(b,1,n << 1,L + 1);
    for(int i = 0;i < (n<<1); i++)  {
		b[i] = 1LL * b[i] * ((2LL - 1LL * d[i] * b[i] % mod + mod) % mod) % mod;
	}
    NTT(b,-1,n << 1,L + 1);
    memset(b + n,0,n * sizeof(int));
}
ll n,m;
ll fac[N];
int L;
int A[N],B[N],C[N],inv_B[N];
int main()
{
	// freopen("in.txt","r",stdin);
  	std::cin >> n;
	m = 1;
	while(m <= (n << 1)) m<<=1, L++;

	fac[0] = 1;
	for(int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % mod;
	}
	for(ll i = 0; i <= n; i++) {
		B[i] = qpower(2,(i * (i - 1)>>1)) * qpower(fac[i],mod - 2) % mod;
	}

	for(ll i = 1; i <= n; i++) {
		C[i] = qpower(2,(i * (i - 1)>>1)) * qpower(fac[i - 1],mod - 2) % mod;
	}

	A[0] = 1;
	ployInv(B,inv_B,m,L);
	NTT(inv_B,1,m,L);
	NTT(C,1,m,L);
	for(int i = 0; i < m; i++) {
		A[i] = 1LL * inv_B[i] * C[i] % mod;
	}
	NTT(A,-1,m,L);
	std::cout << A[n] * fac[n-1] % mod << '\n';
  	return 0;
}
