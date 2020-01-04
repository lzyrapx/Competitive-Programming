/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 19:42:33
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>dp(rowIndex + 1, 0);
        dp[0] = 1;
        for(int  i = 0; i <= rowIndex; i++) {
            for(int j = i; j > 0; --j) {
                dp[j] = dp[j] + dp[j - 1]; 
            }
        }
        return dp;
    }
};