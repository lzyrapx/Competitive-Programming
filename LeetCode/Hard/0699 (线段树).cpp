/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-14 09:12:32
 */
class Solution {
public:
    int n;
    vector<int> height, lazy;
    void push_up(int rt) {
        height[rt] = max(height[rt * 2], height[rt * 2 + 1]);
    }
    void push_down(int rt) {
        // use lazy symbol to reduce the segment tree traverse, only update the son when needed
        if(lazy[rt]) {
            lazy[rt * 2] = lazy[rt * 2 + 1] = lazy[rt];
            height[rt * 2] = height[rt * 2 + 1] = lazy[rt];
            lazy[rt] = 0;
        }
    }
    void update(int rt, int l, int r, int L, int R, int val) {
        if(L <= l && r <= R) {
            height[rt] = val;
            lazy[rt] = val;
            return;
        }
        push_down(rt);
        int mid = l + (r - l) / 2;
        if(L < mid) {
            update(rt * 2, l, mid, L, R, val);
        }
        if(R > mid) {
            update(rt * 2 + 1, mid, r, L, R, val);
        }
        push_up(rt);
    }
    int query(int rt, int l, int r, int L, int R) {
        if(L <= l && r <= R) {
            return height[rt];
        }
        push_down(rt);
        int ans = 0;
        int mid = l + (r - l) / 2;
        if(L < mid) {
            ans = max(ans, query(rt * 2, l, mid, L, R));
        }
        if(R > mid) {
            ans = max(ans, query(rt * 2 + 1, mid, r, L, R));
        }
        return ans;
    }
    // 俄罗斯方块，求最高度，用线段树...O(nlogn)
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int>a;
        for(auto& p: positions) {
            a.push_back(p[0]);
            a.push_back(p[0] + p[1]);
        }
        
        // discretization
        sort(a.begin(), a.end());
        n = unique(a.begin(), a.end()) - a.begin();
        a.resize(n);
        
        height.resize(n << 3, 0);
        lazy.resize(n << 3, 0);
        vector<int>ans;
        
        for(auto& p: positions) {
            int l = lower_bound(a.begin(), a.end(), p[0]) - a.begin() + 1;
            int r = lower_bound(a.begin(), a.end(), p[0] + p[1]) - a.begin() + 1;
            // query the maxHeight from l to r
            int maxx = query(1, 1, n, l, r);
            // add new height to segment tree from l to r
            update(1, 1, n, l, r, maxx + p[1]);
            ans.push_back(query(1, 1, n, 1, n));
        }
        return ans;
    }
};