/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-13 20:50:35
 */
class Solution {
public:
    int mod = 1e9 + 7;
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<long long>>dp(41, vector<long long>((1 << n), 0));
        // dp[i][j]表示戴上第i个帽子后，人们戴帽子状态为 j (拆成二进制位0没戴，1戴了)的戴帽子方案数
        dp[0][0] = 1;
        vector<set<int>>ve(41);
        for(int i = 0; i < n; i++) {
            for(auto hat: hats[i]) {
                ve[hat].insert(i);
            }
        }
        for(int i = 1; i <= 40; i++) { // 每个帽子
            dp[i] = dp[i - 1]; // 没人戴的情况
            for(auto h: ve[i]) { // 哪些人可以戴这个帽子
                for(int state = 0; state < (1 << n); state++) {
                    // (state - (1 << h)) 和 (state ^ (1 << h)) 的效果是一样的
                    if(((((state ^ (1 << h))) >> h) & 1) == 0) {
                        dp[i][state] += dp[i - 1][state ^ (1 << h)];
                    }
                }
            }
        }
        return dp[40][(1 << n) - 1] % mod;
    }
};