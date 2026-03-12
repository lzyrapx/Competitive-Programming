/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-16 22:26:50
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    ll a = 0;
    while((1LL << a) <= k) a++;
    a--;

    // for odd x
    ll y = k - (1LL << a);
    ll x = (n - y) / (1LL << a);
    if(x % 2 == 0) x--; // turn to odd
    ans = max(ans, x);

    // for even x
    if(k == (1LL << (a + 1)) - 1) a++;
    y = k - ((1LL << a) - 1);
    x = (n - y) / (1LL << (a - 1));
    if(x % 2 == 1) x--; // turn to even
    ans = max(ans ,x);

    cout << ans << endl;
    return 0;
}
