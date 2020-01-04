/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-18 00:26:26
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-18 00:26:26
 */
class Solution {
public:
    // if alex win return true else return false
    bool stoneGame(vector<int>& piles) {
        int sz = piles.size();
        if(sz <= 2) return true;
        vector<vector<int>>dp(sz, vector<int>(sz, 0));
        for(int i = 0; i < sz; i++) {
            dp[i][i] = piles[i];
        }
        // dp[i][j] 表示在 piles[i] ~ piles[j] 中，你比对手多的石头数
        for(int j = 1; j < sz; j++) {
            for(int i = 0; i < sz - j; i++) {
                dp[i][i + j] = max(piles[i] - dp[i][i + j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][sz - 1] > 0;
    }
};