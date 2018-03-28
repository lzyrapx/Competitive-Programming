#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

long long cnt[20][20];
int mxi;
int d[20];
long long ans;
int x;
/*
给定一个正整数序列(序列长度n≤10^5)数字大小 2^20
现选定一个正整数数xx与原序列中所有的数异或
然后问操作之后的序列相邻两数差的绝对值之和最小是多少
在满足该值最小的前提下 最小的xx又是多少
*/
void dfs(int i, int cx, long long sum)
{
    if (i == mxi)
    {
        if (ans > sum || (ans == sum && x > cx))
            ans = sum, x = cx;
    }
    else
        for (d[i] = 0; d[i] < 2; ++d[i])
        {
            long long nsum = sum + cnt[i][i];
            for (int j = 0; j < i; ++j)
                if (d[i] ^ d[j])
                    nsum -= cnt[i][j];
                else
                    nsum += cnt[i][j];
            dfs(i + 1, cx | (d[i] << i),  nsum);
        }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j <= i; ++j)
                cnt[i][j] = 0;
        int a;
        scanf("%d", &a);
        for (int i = 1; i < n; ++i)
        {
            int b;
            scanf("%d", &b);
            int high = 19;
            while (high >= 0 && ~(a ^ b) >> high & 1)
                --high;
            int mx = max(a, b);
            int mi = min(a, b);
            for (int j = high; j >= 0; --j)
                cnt[high][j] += (mx >> j & 1) - (mi >> j & 1);
            a = b;
        }
        mxi = 20;
        while (mxi > 0 && !cnt[mxi - 1][mxi - 1])
            --mxi;
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j <= i; ++j)
                cnt[i][j] <<= j;
        ans = 1e18;
        dfs(0, 0, 0);
        printf("%d %lld\n", x, ans);
    }
    return 0;
}