#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v;
    cin >> v;
    int tmp = v;
    int ans = 0, cnt = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> v;
        if (v <= tmp)
        {
            cnt += 1;
            tmp = v;
        }
        else
        {
            cnt = 0;
            tmp = v;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}