/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-26 23:48:32
 */ 
class Solution {
public:
    // 1 <= rows, cols <= 50
    // 1 <= k <= 10
    int mod = 1e9 + 7;
    void add(long long &a, long long &b) {
        a =  (a + b) % mod;
    }
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>>cnt(m + 1,vector<int>(n + 1, 0));
        for(int i = m - 1; i >= 0; --i) {
            int s = 0;
            for(int j = n - 1; j >= 0; --j) {
                s += pizza[i][j] == 'A';
                cnt[i][j] = cnt[i + 1][j] + s;
            }
        }
        vector<vector<vector<long long>>>dp(m + 1, vector<vector<long long>>(n + 1, vector<long long>(k + 1)));
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                dp[i][j][1] = 1;
                for(int h = 2; h <= k; h++) {
                    for(int r = i + 1; r < m; r++) {
                        if(cnt[i][j] == cnt[r][j]) continue;
                        if(cnt[r][j] == 0) break;
                        add(dp[i][j][h],dp[r][j][h-1]);
                    }
                    for(int c = j + 1; c < n; c++){
                        if(cnt[i][j] == cnt[i][c]) continue;
                        if(cnt[i][c] == 0) break;
                        add(dp[i][j][h],dp[i][c][h-1]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};