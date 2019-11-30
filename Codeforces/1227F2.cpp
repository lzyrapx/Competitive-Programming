#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 998244353;
int n, k;

ll qower(ll a, ll b)
{
    ll ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

void precalc(int n)
{
}
void sovle(int n)
{
}
int main()
{

    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    return 0;
}