#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;
struct node
{
    int x, y;
} point[maxn];

bool cmp(node a, node b)
{
    return atan2(a.x, a.y) < atan2(b.x, b.y);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> point[i].x >> point[i].y;
    }
    long long ans = 0;
    int tx, ty;
    sort(point, point + n, cmp);
    for (int i = 0; i < n; i++)
    {
        tx = point[i].x;
        ty = point[i].y;
        ans = max(ans, 1LL * tx * tx + 1LL * ty * ty);
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n)
        {
            tx += point[j].x;
            ty += point[j].y;
            ans = max(ans, 1LL * tx * tx + 1LL * ty * ty);
        }
    }
    double res = sqrt(ans);
    printf("%.13f\n", res);
    return 0;
}