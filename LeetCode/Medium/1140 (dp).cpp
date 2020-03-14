/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-14 16:54:54
 */
class Solution {
public:
    // 1 <= piles.length <= 100
    int stoneGameII(vector<int>& piles) {
        if(piles.size() == 1) {
            return piles[0];
        }
        vector<int>presum(piles.size() + 1, 0);
        presum[0] = piles[0];
        for(int i = 1; i < piles.size(); i++) {
            presum[i] = presum[i - 1] + piles[i];
        }
        // dp[i][j] represent as the maximum value Alex can pick when 
        // he is started at i-th stone and can pick at most 2*j stones
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(), 0));
        for(int i = piles.size() - 1; i >= 0; --i) {
            for(int j = 0; j < piles.size(); j++) { // M
                if(i + 2 * j >= piles.size()) {
                    dp[i][j] = presum[piles.size() - 1] - presum[i] + piles[i];
                }
                for(int x = 1; x <= 2 * j; x++) { // x
                    if(i + x >= piles.size()) break;
                    // dp[i + x][max(x, j)] represent as the minimum stones that lee can pick
                    dp[i][j] = max(dp[i][j], presum[piles.size() -1] - dp[i + x][max(x, j)] - presum[i] + piles[i]);
                }
            }
        }
        return dp[0][1];
    }
};