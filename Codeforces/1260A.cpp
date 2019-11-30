#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    int c, sum;
    for(int i = 0; i < n; i++) {
        cin >> c >> sum;
        long long ans = 0;
        for(int i = 0; i < c; i++) {
            int t = sum / (c - i);
            sum -= t;
            ans += 1LL * t * t;
            
        }
        cout << ans << endl;
    }
    return 0;
}