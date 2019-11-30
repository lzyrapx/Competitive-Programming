#include <bits/stdc++.h>

using namespace std;

const int g = 3;
const int mod = 998244353;
const int maxn = 3456789;

typedef long long ll;

int rv[maxn + 123];
int invr[maxn + 123];
template <class T>
inline void read(T &x)
{
    int ch = 0, f = 0;
    x = 0;
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = 1;
    for (; isdigit(ch); ch = getchar())
        x = x * 10 + ch - 48;
    if (f)
        x = -x;
}

struct poly
{
    vector<int> x;
    int deg = 0;
    poly() { deg = 0, x.resize(1); }
};
int M(int x) { return x >= mod ? x - mod : x; }
int mypow(int a, int b) //快速幂
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}
void precalc_invr() //线性筛逆元
{
    int i;
    invr[1] = 1;
    for (i = 2; i <= maxn; i++)
    {
        invr[i] = M(-1LL * invr[mod % i] * (mod / i) % mod + mod);
    }
}
poly add(poly a, poly b) //多项式加法
{
    int i;
    poly nw;
    nw.deg = max(a.deg, b.deg);
    nw.x.resize(nw.deg + 1);
    for (i = 0; i <= a.deg; i++)
    {
        nw.x[i] += a.x[i];
    }
    for (i = 0; i <= b.deg; i++)
    {
        nw.x[i] += b.x[i];
    }
    for (i = 0; i <= nw.deg; i++)
    {
        nw.x[i] = M(nw.x[i]);
    }
    return nw;
}
poly Minus(poly a, poly b) //多项式减法
{
    int i;
    poly nw;
    nw.deg = max(a.deg, b.deg);
    nw.x.resize(nw.deg + 1);
    for (i = 0; i <= a.deg; i++)
    {
        nw.x[i] += a.x[i];
    }
    for (i = 0; i <= b.deg; i++)
    {
        nw.x[i] -= b.x[i];
    }
    for (i = 0; i <= nw.deg; i++)
    {
        nw.x[i] = M(nw.x[i] + mod);
    }
    return nw;
}
poly ext(poly a, int siz) //多项式变项数（可变长补零或变短忽略高位）
{
    int i, tp;
    poly nw;
    nw.deg = siz;
    nw.x.resize(siz + 1);
    tp = min(siz, a.deg);
    for (i = 0; i <= tp; i++)
    {
        nw.x[i] = a.x[i];
    }
    return nw;
}
poly reverse(poly a) //多项式翻转
{
    int i;
    poly nw;
    nw.deg = a.deg;
    nw.x.resize(nw.deg + 1);
    for (i = 0; i <= nw.deg; i++)
    {
        nw.x[i] = a.x[nw.deg - i];
    }
    return nw;
}
poly dot(poly a, poly b) //多项式点乘
{
    int i;
    poly nw;
    nw.deg = min(a.deg, b.deg);
    nw.x.resize(nw.deg + 1);
    for (i = 0; i <= nw.deg; i++)
    {
        nw.x[i] = 1LL * a.x[i] * b.x[i] % mod;
    }
    return nw;
}
poly scalar_mul(poly a, int k) //多项式数乘
{
    int i;
    poly nw;
    nw.deg = a.deg;
    nw.x.resize(nw.deg + 1);
    for (i = 0; i <= nw.deg; i++)
    {
        nw.x[i] = 1LL * a.x[i] * k % mod;
    }
    return nw;
}
poly der(poly a) //多项式求导
{
    int i;
    poly nw;
    nw.deg = max(0, a.deg - 1);
    nw.x.resize(nw.deg + 1);
    for (i = 1; i <= a.deg; i++)
    {
        nw.x[i - 1] = 1LL * a.x[i] * i % mod;
    }
    return nw;
}
poly integ(poly a) //多项式积分
{
    int i;
    //precalc_invr()
    poly nw;
    nw.deg = a.deg + 1;
    nw.x.resize(nw.deg + 1);
    for (i = 0; i <= a.deg; i++)
    {
        nw.x[i + 1] = 1LL * a.x[i] * invr[i + 1] % mod;
    }
    return nw;
}
void dft(poly *a, int type, int limit) //DFT/IDFT
{
    int wn, w, mid, u, v, rr, i, j, k;
    for (i = 1; i < limit; i++)
    {
        if (rv[i] > i)
        {
            swap(a->x[rv[i]], a->x[i]);
        }
    }

    for (mid = 1; mid < limit; mid <<= 1)
    {
        wn = (type == 1) ? mypow(g, (mod - 1) / 2 / mid) : mypow(g, mod - 1 - (mod - 1) / 2 / mid);
        for (j = 0, rr = mid << 1; j < limit; j += rr)
        {
            w = 1;
            for (k = 0; k < mid; k++, w = 1LL * w * wn % mod)
            {
                u = a->x[j + k], v = 1LL * w * a->x[j + mid + k] % mod;
                a->x[j + k] = M(u + v);
                a->x[j + mid + k] = M(u - v + mod);
            }
        }
    }
    if (type == -1)
    {
        int inv = mypow(limit, mod - 2);
        for (i = 0; i < limit; i++)
        {
            a->x[i] = 1LL * inv * a->x[i] % mod;
        }
    }
}
poly mul(poly a, poly b) //多项式乘法
{
    int limit = 1, l = 0, i, n, m;
    n = a.deg;
    m = b.deg;
    poly f, g;
    while (limit <= n + m)
    {
        limit <<= 1, l++;
    }
    for (i = 1; i < limit; i++)
    {
        rv[i] = (rv[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    f = ext(a, limit - 1);
    g = ext(b, limit - 1);
    dft(&f, 1, limit);
    dft(&g, 1, limit);
    for (i = 0; i < limit; i++)
    {
        f.x[i] = 1LL * f.x[i] * g.x[i] % mod;
    }
    dft(&f, -1, limit);
    f.deg = n + m;
    f.x.resize(n + m + 1);
    return f;
}
poly poly_inv(poly a, int n) //多项式求逆，mod x^n,要求常数项非零
{
    int i, seq[21], cnt = 0;
    poly h, f[21];
    while (n != 1)
    {
        f[++cnt] = ext(a, n - 1);
        seq[cnt] = n, n = n / 2 + (n & 1);
    }
    h.x[0] = mypow(a.x[0], mod - 2);
    for (i = cnt; i > 0; i--)
    {
        h = Minus(scalar_mul(h, 2LL), ext(mul(ext(mul(f[i], h), seq[i] - 1), h), seq[i] - 1));
    }
    return h;
}
poly poly_ln(poly a, int n) //多项式取ln，mod x^n,要求常数项为1
{
    poly f;
    f = der(a);
    f = integ(ext(mul(f, poly_inv(a, n)), n - 1));
    f.deg = n - 1;
    f.x.resize(n);
    return f;
}
poly poly_exp(poly a, int n) //多项式exp，mod x^n,保证常数项为0
{
    int i, seq[21], cnt = 0;
    poly h, f[21];
    while (n != 1)
    {
        f[++cnt] = ext(a, n - 1);
        seq[cnt] = n, n = n / 2 + (n & 1);
        f[cnt].x[0] = 1;
    }
    h.x[0] = 1;
    for (i = cnt; i > 0; i--)
    {
        h = ext(mul(h, Minus(f[i], poly_ln(h, seq[i]))), seq[i] - 1);
    }
    return h;
}
void poly_div(poly a, poly b, poly *q, poly *r) //多项式除法，q为商,r为余数 保证b不为零多项式
{
    int n, m;
    n = a.deg;
    m = b.deg;
    if (n < m)
    {
        q->x.resize(1);
        q->deg = 0;
        q->x[0] = 0;
        *r = a;
    }
    *q = reverse(ext(mul(reverse(a), poly_inv(reverse(b), n - m + 1)), n - m));
    *r = Minus(a, mul(*q, b));
}
poly poly_sqrt(poly a, int n) //多项式开根，保证常数项为1,当常数项不为1时需要二次剩余
{
    int i, seq[21], cnt = 0, inv2;
    inv2 = mypow(2, mod - 2);
    poly h, f[21];
    while (n != 1)
    {
        f[++cnt] = ext(a, n - 1);
        seq[cnt] = n, n = n / 2 + (n & 1);
        f[cnt].x[0] = 1;
    }
    h.x[0] = 1;
    for (i = cnt; i > 0; i--)
    {
        h = add(ext(mul(f[i], poly_inv(scalar_mul(h, 2), seq[i])), seq[i]), scalar_mul(h, inv2));
    }
    return h;
}
poly poly_pow(poly a, int m, int n) //多项式幂次a^m mod x^n，常数项可随意版本
{
    int i, np, tp, inv, tmp;
    poly f, g;
    np = a.deg;
    for (i = 0; i <= np && a.x[i] == 0; i++)
        ;
    tp = i;
    if (i > n)
        return f;
    inv = mypow(a.x[tp], mod - 2);
    tmp = mypow(a.x[tp], m);
    g.deg = np - tp;
    g.x.resize(g.deg + 1);
    for (i = 0; i <= g.deg; i++)
    {
        g.x[i] = 1LL * inv * a.x[i + tp] % mod;
    }
    g = poly_exp(scalar_mul(poly_ln(g, n), m), n);
    f.x.resize(n);
    f.deg = n - 1;
    for (i = 0; i <= g.deg && 1LL * i + 1LL * m * tp <= f.deg; i++)
    {
        f.x[i + m * tp] = 1LL * tmp * g.x[i] % mod;
    }
    return f;
}

int p[maxn];
int num[maxn];
poly f[maxn];
poly solve(int l, int r)
{
    if (l == r)
    {
        return f[l];
    }
    int mid = (l + r) >> 1;
    return mul(solve(l, mid), solve(mid + 1, r));
}
int main()
{

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        num[p[i]] += 1;
    }
    int tot = 0;
    for (int i = 1; i <= 3e6; i++)
    {
        if (num[i] == 0)
            continue;
        tot++;
        f[tot].deg = num[i];
        f[tot].x.resize(num[i] + 1);
        for (int j = 0; j <= num[i]; j++)
        {
            f[tot].x[j] = 1;
        }
    }
    poly ans = solve(1, tot);
    cout << ans.x[n / 2] << endl;
    return 0;
}
// g++ -std=C++11 -O3 -o main 1257G.cpp
// ./main