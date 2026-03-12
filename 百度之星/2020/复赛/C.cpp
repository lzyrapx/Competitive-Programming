#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 123;
const int mod = 998244353;

int c[maxn];
int main(int argc, char const *argv[])
{
    int t;
    // cin >> t;
    scanf("%d",&t);
    while(t--) {
        int n, l, k;
        // cin >> n >> l >> k;
        scanf("%d%d%d",&n,&l,&k);
        for(int i = 1; i <= n; i++) {
            // cin >> c[i];
            scanf("%d",&c[i]);
        }
        ll ans1 = 0;
        sort(c + 1, c + n + 1);
        int idx = n + 1;
        for(int i = l - k + 1; i <= n; i += l) {
            int minn = min(n, i + k - 1);
            int j = i;
            for(j = i; j <= minn; j++) {
                if(j < minn && i - 1 > l - k) {
                    ans1 += c[--idx];
                    // cout << "t1 = " << ans1 << endl;
                }
                else {
                    idx = idx - 1;
                }
            }
            int k1 = min(n, (j - 1) + (l - k));
            ans1 += 1LL * c[idx] * (k1 - j + 2);
        }
        // cout << "ans1 = " << ans1 << endl;
        for(int i = 1; i <= n; i++) {
            c[i] = -1 * c[i];
        }
        k = l - k + 1;
        ll ans2 = 0;
        sort(c + 1, c + n + 1);
        idx = n + 1;
        for(int i = l - k + 1; i <= n; i += l) {
            int minn = min(n, i + k - 1);
            int k1 = n, j = i;
            for(j = i; j <= minn; j++) {
                if(j < minn && i - 1 > l - k) {
                    ans2 += c[--idx];
                    
                }
                else {
                    idx = idx - 1;
                }
            }
            k1 = min(n, (j - 1) + (l - k));
            ans2 += 1LL * c[idx] * (k1 - j + 2);
        }
        printf("%lld %lld\n",ans1, -1 * ans2);
        // cout << ans1 << " " << -1 * ans2 << endl;
    }
    return 0;
}
