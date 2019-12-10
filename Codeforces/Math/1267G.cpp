
/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-10 17:00:56
 */

#include <bits/stdc++.h>

using namespace std;

long double C[123][123];
long double dp[123][12345];
int a[123];
int main()
{
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    C[0][0] = 1;
    for (int i = 1; i <= 120; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; --j)
        {
            for (int k = a[i]; k <= sum; k++)
            {
                dp[j][k] = dp[j][k] + dp[j - 1][k - a[i]];
            }
        }
    }
    cerr << "finished" << endl;
    long double ans = 0.0;
    for (int k = 1; k <= n; k++)
    {
        for (int s = 1; s <= sum; s++)
        {
            ans += 1.0 * dp[k][s] / C[n][k] * min(1.0 * s / k, (1.0 * (n + k) / k) * x * 0.5);
        }
    }
    printf("%.9Lf\n", ans);
    return 0;
}