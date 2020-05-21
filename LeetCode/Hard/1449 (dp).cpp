/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-20 23:28:33
 */ 
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
       vector<int>dp(target + 1, -1e9);
        //  dp[i] = the max digits to reach i, dp[0] = 0
        dp[0] = 0; // 忘记初始化了...
        for(int i = 0; i < 9; i++) {
            for(int j = cost[i]; j <= target; j++) {
                dp[j] = max(dp[j], dp[j - cost[i]] + 1);
            }
        }
        // for(int i = 0; i <= 9; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        if(dp[target] < 0) { // not possible to reach target
            return "0";
        }
        string ans = "";
        // because cost.length == 9, so the maximum is 8
        // now that we know the max digits
        // we add possible numbers from large to small to get largest combination
        for(int i = 8; i >= 0; i--) {
            // verify that we can indeed use this relatively large digit, as many times as possible
            while(target >= cost[i] && dp[target] == dp[target - cost[i]] + 1) {
                ans += to_string(i + 1);
                target -= cost[i];
            }
        }
        return ans;
    }
};