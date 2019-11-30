#include <bits/stdc++.h>
using namespace std;

const int maxn = 123;

int main()
{
    int t;
    cin >> t;
    vector<int> n(maxn), x(maxn), a(maxn), b(maxn);
    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> x[i] >> a[i] >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < t; i++)
    {
        ans = min(n[i] - 1, abs(a[i] - b[i]) + x[i]);
        cout << ans << endl;
    }
    return 0;
}