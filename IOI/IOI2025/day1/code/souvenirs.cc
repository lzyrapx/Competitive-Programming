/*
在已知类型0的纪念品价格（P0）且其他类型价格未知的情况下，通过多次交易购买纪念品
最终满足每个类型i（0 <= i <== N）恰好购买 i 个的要求（注意：类型 0 购买 0 个，类型 1 购买 1 个，类型 2 购买2个，以此类推）。

做法：DFS 确定每个纪念品的价格，并在后续交易中补足所需数量。
*/

#include <bits/stdc++.h>

#include "souvenirs.h"

using namespace std;

typedef long long ll;

int p[101];          // 全局数组，记录每个类型已购买的纪念品数量
ll prices[101];      // 全局数组，记录每个类型纪念品的价格

// 执行一次交易，并更新购买计数
std::pair<std::vector<int>, ll> deal(ll val) {
    // 调用交易函数，传入硬币数量 val
    auto r = transaction(val);
    // 遍历交易中购买的纪念品类型，更新全局购买计数 p
    for (auto &x: r.first) {
        p[x]++;  // 类型x的购买数量增加
    }
    return r;
}

// DFS 确定纪念品价格
// val：当前交易使用的硬币数量
// M：当前处理的类型下界（初始为 N ）
// 返回值：当前处理的最小类型
int dfs(ll val, int M) {
    // 执行交易，获取购买列表和剩余硬币
    auto [v, remain] = deal(val);
    ll t = val - remain;  // 计算总花费（用于购买纪念品的硬币）
    ll cur = v[0];        // 当前交易中购买的最小类型（即最昂贵的类型）

    while(true) {
        // 移除已确定价格的高类型（类型编 >= M），并扣除其花费
        while(!v.empty() && v.back() >= M) {
            t -= prices[v.back()];  // 从总花费中扣除高类型价格
            v.pop_back();           // 从购买列表中移除
        }
        // 如果当前最小类型 cur 与 M 连续（cur+1 == M），则退出循环
        if (cur + 1 == M) 
            break;
        // 递归调用：处理剩余纪念品（类型 < M）
        // 新交易金额 = (总花费 - 1) / 剩余纪念品数量（向下取整）
        M = dfs((t - 1) / (int) v.size(), M);
    }
    // 设置当前类型 cur 的价格为剩余总花费 t
    prices[cur] = t;
    return cur;  // 返回当前类型，作为递归上层的新 M
}

// 购买纪念品
void buy_souvenirs(int N, long long P0) {
    // 初始化类型 0 的价格（已知）
    prices[0] = P0;
    // 从 P0-1 硬币开始 DFS，初始类型下界 M=N
    // 目标：确定所有类型（1 到 N-1）的价格
    dfs(P0 - 1, N);

    // 补足购买数量：对每个类型 i（1 到 N-1）
    for (int i = 1; i < N; i++) {
        // 如果当前购买数量 p[i] 小于目标 i，则补足
        while (p[i] < i) {
            // 执行交易：使用已确定的价格 prices[i] 购买类型 i
            // 每次交易会购买一个类型 i 的纪念品
            deal(prices[i]);
        }
    }
}