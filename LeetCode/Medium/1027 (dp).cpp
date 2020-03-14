/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-14 21:25:32
 */
class Solution {
public:
    // 2 <= A.length <= 2000
    int longestArithSeqLength(vector<int>& A) {
        if(A.size() == 1) {
            return 1;
        }
        vector<unordered_map<int,int>>dp(A.size());
        int ans = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = i + 1; j < A.size(); j++) {
                int diff = A[j] - A[i];
                if(dp[i].count(diff) == 0) {
                    dp[j][diff] = 2;
                }
                else {
                    dp[j][diff] = dp[i][diff] + 1;
                }
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
    }
};