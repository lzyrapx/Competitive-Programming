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

const int maxn = 1e5 + 123;
// k > 1
int a[maxn];
vector<int>ve;

ll cost(int k) {
    ll ans = 0;
    for(int i = 0; i < ve.size(); i += k) {
        int median = ve[i + (k - 1) / 2];
        for(int j = i; j < i + k; j++) {
            ans += abs(ve[j] - median);
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) {
            ve.push_back(i);
        }
    }
    if(ve.size() == 1) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 1e18;
    int tmp = ve.size();
    int k = 2;
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
    cout << ans << endl;
    return 0;
}
