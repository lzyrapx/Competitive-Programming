/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-13 15:13:35
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

// 显然是一道期望dp题
// dp[i] = (dp[i - 1] + 1) * (p[i] / 100) + (dp[i - 1] + 1 + dp[i](这个表示重新回到这个点的期望)) * (1 - p[i] / 100)
// 手动简化一下就是：dp[i] = (dp[i - 1] + 1) * (100 / p[i])
ll qpower(ll a, ll b, ll MOD) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
ll dp[2 * 123456];
int main() {
    int n;
    cin >> n;
    vector<ll>p(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = (dp[i - 1] + 1) * 100 % mod * qpower(p[i], mod - 2, mod);
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
}