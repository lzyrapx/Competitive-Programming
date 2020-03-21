/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 17:47:10
 */
class Solution {
public:
    // 3 <= A.length <= 50
    int minScoreTriangulation(vector<int>& A) {
        if(A.size() == 3) {
            return A[0] * A[1] * A[2];
        }
        // dp[i][j] represent as the smallest possible total score in A{i ~ j}
        // so the answer is dp[0][A.size() - 1]
        vector<vector<int>>dp(A.size(), vector<int>(A.size(), 0));
        // A[i, k, j]
        for(int i = A.size(); i >= 0; i--) {
            for(int j = i + 1; j < A.size(); j++) {
                for(int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j] == 0 ? INT_MAX: dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
                }
            }
        }
        return dp[0][A.size() - 1];
    }
};