/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-30 23:38:22
 */
class Solution {
public:
    int count_node(long long root, long long n) {
        long long cnt = 0;
        long long son = root + 1;
        while(root <= n) {
            cnt += min(son, n + 1) - root;
            root *= 10;
            son *= 10;
        }
        return cnt;
    }
    long long dfs(long long root, long long n, long long k) {
        if(k == 0) {
            return root;
        }
        // how many nodes in the subtree rooted at root
        long long cnt = count_node(root, n);
        if(cnt > k) {
            return dfs(10 * root, n, k - 1);
        }
        else {
            return dfs(root + 1, n, k - cnt);
        }
    }
    int findKthNumber(int n, int k) {
        return dfs(1, n, k - 1);
    }
};