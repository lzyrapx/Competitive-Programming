/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-19 14:51:18
 */ 
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

typedef long long ll;
ll qpower(ll a, ll b,ll mod)
{
    long long ans=1;
    while(b>0) {
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

int a[1234][1234];
int cost[4][25][25][25];

int get_value(int i, int j, int k, int l) {
    int ans = 0, cur = 0, sum = i;
    for(int o = 1; o <= 8; o++) {
        int t = 8 * o * o;
        if(t > cur) {
            ans += (t - cur) / sum;
            cur += (t - cur) / sum * sum;
            if(cur < t) {
                cur += sum;
                ans += 1;
            }
        }
        if(j > 0) {
            j -= 1;
            sum += 3;
        }
        else if(k > 0) {
            k -= 1;
            sum += 2;
        }
        else if(l > 0 ) {
            l -= 1;
            sum += 1;
        }
    }
    return ans;
}
int solve(int x, int y, int n, int xx, int yy) {
    int One = 0;
    int Two = 0;
    int Three = 0;
    for(int i = max(1, x - 3); i <= min(x + 3, n); i++) {
        for(int j = max(y - 3, 1); j <= min(y + 3, n); j++) {
            if(abs(i - x) + abs(j - y) > 3) {
                continue;
            }
            if(a[i][j] == 3) {
                One++;
            }
            else if(a[i][j] == 2) {
                Two++;
            }
            else {
                Three++;
            }
        }
    }
    // cout << "lll" << endl;
    if(a[x][y] == 3) {
        One--;
    }
    else if(a[x][y] == 2) {
        Two--;
    }
    else {
        Three--;
    }
    // cout << "ppp = " <<  a[x][y] << endl;
    int ans = ((abs(x - xx) + abs(y - yy) + 1) / 2 + cost[a[x][y]][One][Two][Three]);
    // cout << "oooo" << endl;
    return ans;
}

int main(int argc, char const *argv[])
{
    for(int i = 1; i <= 3; i++) {
        for(int j = 0; j <= 24; j++) {
            for(int k = 0; k <= 24; k++) {
                for(int l = 0; l <= 24; l++) {
                    if(j + k + l <= 24) {
                        cost[i][j][k][l] = get_value(i, j, k, l);
                    }
                    else {
                        cost[i][j][k][l] = 1e9;
                    }
                }
            }
        }
    }
    int t = 0;
    cin >> t;
    while(t--) {
        int n, x, y;
        int ans = 1e9;
        cin >> n >> x >> y;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        // cout << "ok" << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                ans = min(ans, solve(i, j, n, x, y));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
