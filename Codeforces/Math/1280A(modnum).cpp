/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-16 15:52:03
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll modinv(ll a, ll m)
{
    assert(m > 0);
    if (m == 1)
        return 0;
    a %= m;
    if (a < 0)
        a += m;
    assert(a != 0);
    if (a == 1)
        return 1;
    return m - modinv(m, a) * m / a;
}

template <int MOD_>
struct modnum
{
private:
    int v;

public:
    static const int MOD = MOD_;

    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD))
    {
        if (v < 0)
            v += MOD;
    }
    explicit operator int() const { return v; }
    friend bool operator==(const modnum &a, const modnum &b) { return a.v == b.v; }
    friend bool operator!=(const modnum &a, const modnum &b) { return a.v != b.v; }

    modnum operator~() const
    {
        modnum res;
        res.v = modinv(v, MOD);
        return res;
    }

    modnum &operator+=(const modnum &o)
    {
        v += o.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }
    modnum &operator-=(const modnum &o)
    {
        v -= o.v;
        if (v < 0)
            v += MOD;
        return *this;
    }
    modnum &operator*=(const modnum &o)
    {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum &operator/=(const modnum &o)
    {
        return *this *= (~o);
    }

    friend modnum operator+(const modnum &a, const modnum &b) { return modnum(a) += b; }
    friend modnum operator-(const modnum &a, const modnum &b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum &a, const modnum &b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum &a, const modnum &b) { return modnum(a) /= b; }
};

template <typename T>
T pow(T a, long long b)
{
    assert(b >= 0);
    T r = 1;
    while (b)
    {
        if (b & 1)
            r *= a;
        b >>= 1;
        a *= a;
    }
    return r;
}

using num = modnum<mod>;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        num len = s.size();
        for (int i = 0; i < x; i++)
        {
            if (s.size() <= x)
            {
                string str = s.substr(i + 1);
                for (int j = 0; j < (s[i] - '1'); j++)
                {
                    s += str;
                }
            }
            len = (i + 1) + (len - (i + 1)) * (s[i] - '0');
        }
        cout << (int)len << endl;
    }
    return 0;
}