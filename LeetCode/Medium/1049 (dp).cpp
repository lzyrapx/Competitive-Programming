/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 21:30:11
 */
class Solution {
public:
    // 1 <= stones.length <= 30
    // 1 <= stones[i] <= 100
    // change to find the minimum difference between the sum of two groups.
    int lastStoneWeightII(vector<int>& stones) {
        // dp[i] represent as the smaller groups have i weight
        vector<bool>dp(30 * 100 / 2, false);
        dp[0] = true;
        int sum = 0;
        for(auto x: stones) {
            sum += x;
            for(int i = min(30 * 100 / 2, sum); i >= x; --i) {
                dp[i] = dp[i] | dp[i - x];
            }
        }
        for(int i = sum / 2; i >= 1; --i) {
            if(dp[i] == true) {
                return sum - i - i;
            }
        }
        return 0;
    }
};