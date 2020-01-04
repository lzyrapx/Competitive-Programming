/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 20:11:42
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int ans = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            if(prices[i + 1] > prices[i]) {
                ans += (prices[i + 1] - prices[i]);
            }
        }
        return ans;
    }
};