#include <bits/stdc++.h>

using namespace std;

// A sweet can be eaten at most once
int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), sum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        sum[i % m] += a[i];
        ans += sum[i % m];
        if (i == n - 1)
        {
            cout << ans << endl;
        }
        else
        {
            cout << ans << " ";
        }
    }
    return 0;
}
// g++ -std=c++11 -O3 -o main 1253C.cpp
// ./main