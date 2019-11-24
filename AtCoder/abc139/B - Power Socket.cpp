#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (b <= 1)
    {
        cout << 0 << endl;
        exit(0);
    }
    int now = 1;
    int ans = 0;
    while (now < b)
    {
        ans += 1;
        now -= 1;
        now += a;
    }
    cout << ans << endl;
    return 0;
}