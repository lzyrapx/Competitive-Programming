#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 123;
const int mod = 998244353;

int sum[maxn];
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n = 0;
        string s, t;
        cin >> n >> s >> t;
        sum[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] != t[i]) {
                sum[i] = sum[i + 1] + 1;
            }
            else {
                sum[i] = sum[i + 1];
            }
        }
        int ans = sum[0];
        sum[n + 1] = 0;
        int zero = 0, one = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                zero++;
            }
            if(t[i] == '1') {
                one++;
            }
            int k = 0;
            if(t[i + 1] != '1') {
                k++;
            }
            if(s[i + 1] == '1') {
                k++;
            }
            int val = zero + one + sum[i + 2] + k + 1;
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}
