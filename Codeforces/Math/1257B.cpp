#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    // 1. a % 2 == 0 => 3a/2
    // 2. a > 1 => a - 1
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            puts("YES");
            continue;
        }
        if (x == 1 && y > 1)
        {
            puts("NO");
            continue;
        }
        if (x == 2 && y == 3)
        {
            puts("YES");
            continue;
        }
        if (x >= y)
        {
            puts("YES");
            continue;
        }
        if (x > 3)
        {
            puts("YES");
            continue;
        }
        puts("NO");
    }
    return 0;
}