#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> se;
        se.insert(0);
        for (int i = 1; i <= sqrt(n); i++)
        {
            se.insert(n / i);
            se.insert(i);
        }
        cout << se.size() << endl;
        for (auto x : se)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}