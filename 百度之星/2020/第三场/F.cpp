/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-26 23:36:36
 */ 
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 200001;
const int mod = 1e9 + 7;

int inv[maxn];
vector<int>ve[maxn];
int father[maxn];
int ids[maxn];
ll qpower(ll a, ll b,ll mod)
{
    long long ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

void dfs(int v, int fa) {
  father[v] = fa;
  for (vector<int>::iterator it = ve[v].begin(); it != ve[v].end(); ++it) {
       if (*it != fa) {
        dfs(*it, v);
    }
  }
}

int main(int argc, char const *argv[])
{
    inv[0] = 1;
    for(int i = 0; i < maxn; i++){
        inv[i] = qpower(i, mod - 2, mod);
    }

    int t;
    cin >> t;
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
            ve[i].clear();
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        if(m == 1) {
            cout << 1 << endl;
            continue;
        }
        dfs(1, 0);
        int id = 0;
        for(int i = m; i; i = father[i]) {
            ids[++id] = i;
        }
        ll value  = 1;
        for(int i = 2; i <= id; i++) {
            value = value * inv[ve[ids[i]].size()] % mod;
        }
        ll ans = value % mod;
        if(ve[1].size() != 1) {
            ans = 2LL * value % mod;
        }
        // cout << "ans = " << ans << endl;
        for(int i = 2; i < id; i++) {
            ans = (ans + 1LL * value * (ve[ids[i]].size() - 2) % mod * inv[ve[ids[i]].size() - 1]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}