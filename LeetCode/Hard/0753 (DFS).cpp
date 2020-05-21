/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-17 15:36:16
 */ 
class Solution {
public:
    // 找到一个字符串可以覆盖所有的长度为 n 的字符串(只能由 0 ~ k-1 组成)
    // 如何保证最短？
    // 两个长度为 n 的密码最好能共享 n-1 个数字，这样累加出来的钥匙串肯定是最短的。
    // DFS 复杂度 O(k^n)
    void dfs(int n, int k, int total, unordered_set<string>&vis, string& ans) {
        if(vis.size() == total) {
            return;
        }
        string pre = ans.substr(ans.size() - (n - 1), n - 1);
        for(int i = k - 1; i >= 0; i--) {
            string cur = pre + to_string(i);
            if(vis.count(cur)) {
                continue;
            }
            vis.insert(cur);
            ans += to_string(i);
            dfs(n, k, total, vis, ans);
        }
        
    }
    string crackSafe(int n, int k) {
        string ans = string(n, '0');
        unordered_set<string> vis{{ans}};
        dfs(n, k, pow(k, n), vis, ans);
        return ans;
    }
};