/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-21 16:06:34
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const ll mod = 998244353;
const int maxn = 2 * 1e5 + 123;
string s[maxn];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        set<string>visited;
        set<string>bad; // 不可翻转
        visited.clear();
        bad.clear();
        // 00       11      01       10
        int zz = 0, oo = 0, zo = 0, oz = 0;
        for(int i  = 0; i < n; i++) {
            string t = s[i];
            if(t[0] == '0' && t[t.length() - 1] == '0') { // 00
                zz++;
            }
            else if(t[0] == '0' && t[t.length() - 1] == '1') { // 01
                zo++;
                string rev(t.rbegin(),t.rend());
                if(visited.count(rev)) {
                    bad.insert(t);
                    bad.insert(rev);
                }
                visited.insert(t);
            }
            else if(t[0] == '1' && t[t.length() - 1] == '1') { // oo
                oo++;
            }
            else if(t[0] == '1' && t[t.length() - 1] == '0') { // oz
                oz++;
                string rev(t.rbegin(),t.rend());
                if(visited.count(rev)) {
                    bad.insert(t);
                    bad.insert(rev);
                }
                visited.insert(t);
            }
        }
        if(zo == 0 && oz == 0) {
            if(oo == 0 || zz == 0) {
                cout << "0" << "\n" << endl;
            }
            else {
                cout << "-1" << endl;
            }
        } else {
            int ans = abs(zo - oz) / 2;
            cout << ans << endl;
            for(int i = 0; i < n; i++) {
                if(ans == 0) break;
                if(zo > oz && s[i][0] == '0' && s[i].back() == '1' && bad.count(s[i]) == 0) {
                    ans -= 1;
                    cout << i + 1 << " ";
                }
                if(zo < oz && s[i][0] == '1' && s[i].back() == '0' && bad.count(s[i]) == 0) {
                    ans -= 1;
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}