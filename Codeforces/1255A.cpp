#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << ans << endl;
            continue;
        }
        if (b > a)
        {
            swap(a, b);
        }
        a = a - b;
        ans += a / 5;
        a = a % 5;

        ans += a / 2;
        a = a % 2;

        ans += a;
        cout << ans << endl;
    }
    return 0;
}
//  g++ -std=c++11 -O3 -o main 1255A.cpp
// ./main