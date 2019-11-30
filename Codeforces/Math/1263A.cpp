#include <bits/stdc++.h>

using namespace std;

//  needs to eat exactly two candies.
int a, b, c;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        cout << min(min(min(a + b, b + c), a + c), (a + b + c) / 2) << endl;
    }
    return 0;
}