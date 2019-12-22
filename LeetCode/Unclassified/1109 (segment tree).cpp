/*
 * @Descripttion: Prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 01:12:27
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 01:12:27
 */
class Solution {
public:
    // segment tree
    #define lson l, mid, rt << 1
    #define rson mid + 1, r, rt << 1 | 1
    long long sum[int(1e5) << 2];
    long long add[int(1e5) << 2];
    void push_up(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
    void push_down(int rt, int m) {
        if(add[rt]) {
            add[rt << 1] += add[rt];
            add[rt << 1 | 1] += add[rt];
            sum[rt << 1] += (m - (m >> 1)) * add[rt];
            sum[rt << 1 | 1] += (m >> 1) * add[rt];
            add[rt] = 0;
        }
    }
    void build(int l, int r, int rt) {
        add[rt] = 0;
        if(l == r) {
            sum[rt] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        push_up(rt);
    }
    void update(int L, int R, int val, int l, int r, int rt) {
        if(L <= l && R >= r) {
            sum[rt] += (r - l + 1) * val;
            add[rt] += val;
            return;
        }
        push_down(rt, r - l + 1);
        int mid = (l + r) >> 1;
        if(L <= mid) update(L, R, val, lson);
        if(R > mid) update(L, R, val, rson);
        push_up(rt);
    }
    long long query(int L, int R, int l, int r, int rt) {
        if(L <= l && R >= r) return sum[rt];
        push_down(rt, r - l + 1);
        int mid = (l + r) >> 1;
        int ans = 0;
        if(L <= mid) {
            ans += query(L, R, lson);
        }
        if(R > mid) {
            ans += query(L, R, rson);
        }
        return ans;
    }
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res;
        build(1, n, 1);
        for(int i = 0; i < bookings.size(); i++) {
            update(bookings[i][0], bookings[i][1], bookings[i][2], 1, n, 1);
        }
        for(int i = 1; i <= n; i++) {
            // cout << query(i, i, 1, n, 1) << endl;
            res.push_back(query(i, i, 1, n, 1));
        }
        return res;
    }
};