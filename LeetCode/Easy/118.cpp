/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 19:00:31
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp;
        for(int i = 0; i < numRows; i++) {
            dp.push_back(vector<int>(i + 1, 1));
            for(int j = 1; j < i; j ++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp;
    }
};