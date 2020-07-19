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
int a[1234567];

int main(int argc, char const *argv[])
{
    int t = 0;
    int n;
    cin >> t;
    while(t --) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll ans = (a[1] + a[n]) * qpower(4, mod - 2, mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
