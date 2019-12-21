/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-21 18:47:25
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;

const ll mod = 998244353;
const int maxn = 2 * 1e5 + 123;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int>a(n);
    unordered_map<int,int>freq;
    vector<int>cnt(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        cnt[freq[a[i]]]++;
    }
    sort(a.begin(), a.end(), [&](int x, int y) -> bool {
        // 先比较 freq[x] freq[y]
        // 再比较 x y
        return tie(freq[x], x) > tie(freq[y], y);
    });
    int sum = 0;
    int r = 0, c = 0;
    for(int f = 1; f * f <= n; f++) {
        sum += cnt[f];
        if(sum >= f * f) {
            int tr = f;
            int tc = sum / f;
            if(tr * tc >= r * c) {
                r = tr;
                c = tc;
            }
        }
    }
    freq.clear();
    int cur = 0;
    vector< vector<int> >arr(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++) {
        for(int j = 0;; j++) {
            if(arr[(i + j) % r][j % c]) break;
            while(freq[a[cur]] >= r) cur++; // 会重复
            freq[a[cur]]++;
            arr[(i + j) % r][j % c] = a[cur];
            cur ++;
        }
    }
    cout << r * c << endl;
    cout << r << " " << c << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}