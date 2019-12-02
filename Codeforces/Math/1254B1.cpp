/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-01 13:13:46
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 123;
// k > 1
ll a[maxn];
ll sum[maxn];
vector<int>ve;

int n;
ll cost(ll k) {
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += min(sum[i] % k, k - sum[i] % k);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    if(sum[n] == 1) {
        printf("-1\n");
        return 0;
    }
    ll ans = 1e18;
    ll tmp = sum[n];
    ll k = 2;
    while(k * k <= tmp) {
        if(tmp % k == 0) {
            ans = min(ans, cost(k));
            while(tmp % k == 0) {
                tmp /= k;
            }
        }
        k++;
    }
    if(tmp > 1) {
        ans = min(ans, cost(tmp));
    }
    printf("%lld\n", ans);
    return 0;
}
