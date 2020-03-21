/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 22:00:59
 */
class Solution {
public:
    // 1 <= arr.length <= 10^5
    int longestSubsequence(vector<int>& arr, int difference) {
         if(arr.size() == 1) {
             return 0;
         }
        unordered_map<int,int>dp;
        int ans = 1;
        for(auto x: arr) {
            if(dp[x - difference] > 0) {
                dp[x] = dp[x - difference] + 1;
                ans = max(ans, dp[x]);
            }
            else {
                dp[x] = 1;
            }
        }
        return ans;
    }
};