/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-14 21:12:10
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

typedef long long ll;


const ll mod = 998244353;

// 建立一个区间为[0, 2^60-1]的线段树
// 把所给的区间拆分到线段树上去
// 假设一个线段树的深度为 d，那么线段树每个区间都可以看成高 d 位不变，下面的位变化
// 题目要求两个线段树进行合并，假设深度为d1,d2. 合并就是高 min(d1,d2)位不变，下面的位变化

int n, m;
vector<pair<ll,ll>> segments_on[123][2], decomp_a[123][2];
 
void dfs_a(int depth, ll L, ll R, ll l, ll r, int bits) {
    if(L >= l && R <= r) {
        decomp_a[depth][bits].push_back({L, R});
        return;
    }
    if(l > R || r < L) return;
    ll mid = (L + R) >> 1;
    dfs_a(depth - 1, L, mid, l, r, bits);
    dfs_a(depth - 1, mid + 1, R, l, r, bits);
}
 
void dfs_b(int depth, ll L, ll R, ll l, ll r, int bits) {
    if(l > R || r < L) return;
    segments_on[depth][bits].push_back({L, R});
    if(L >= l && R <= r) return;
    ll mid = (L + R) >> 1;
    dfs_b(depth - 1, L, mid, l, r, bits);
    dfs_b(depth - 1, mid + 1, R, l, r, bits);
}
 
ll calc(ll x) {
    x %= mod;
    return (x) * (x + 1) >> 1LL % mod;
}
void brute() {
    set<int>s;
    for(int i = 1; i <= 9; i++) {
        for(int j = 2; j <= 10; j++) {
            s.insert(i ^ j);
        }
    }
    ll sum = 0;
    for(auto x: s) {
        sum += x;
    }
    cout << "ans = " << sum << endl;
    s.clear();
    for(int i = 3; i <= 8; i++) {
        for(int j = 1; j <= 9; j++) {
            s.insert(i ^ j);
        }
    }
    sum = 0;
    for(auto x: s) {
        sum += x;
    }
    cout << "ans = " << sum << endl;
    
}
int main() {
    // brute();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll L, R; 
        cin >> L >> R;
        dfs_a(60, 0, (1LL << 60) - 1, L, R, 0);
        dfs_b(60, 0, (1LL << 60) - 1, L, R, 1);
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        ll L, R; 
        cin >> L >> R;
        dfs_a(60, 0, (1LL << 60) - 1, L, R, 1);
        dfs_b(60, 0, (1LL << 60) - 1, L, R, 0);
    }
    vector<pair<ll,ll>> ans;
    for(int depth = 0; depth <= 60; depth++) {
        for(int bits = 0; bits <= 1; bits++) {
            for(auto p : segments_on[depth][bits]) {
                for(auto q : decomp_a[depth][bits]) {
                    ll pref = (p.first ^ q.first) >> depth;
                    // cerr << "case = " << p.first << " " << q.first << " " << depth << " " << pref << endl;
                    ans.push_back({pref << depth, (pref << depth) + (1LL << depth) - 1});
                    // ans.push_back({pref * pow(2, depth), (pref * pow(2, depth)) + pow(2, depth) - 1});
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    ll res = 0;
    ll last = -1;
    for(auto p : ans) {
        p.first = max(p.first, last);
        if(p.first > p.second) continue;
        res += calc(p.second) - calc(p.first - 1);
        res += mod;
        last = p.second + 1;
        res %= mod;
    }
    cout << res % mod << endl;
    return 0;
}
