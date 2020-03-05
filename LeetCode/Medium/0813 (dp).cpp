/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-04 00:54:56
 */
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if(A.size() == 0) {
            return 0;
        }
        vector<int>presum(A.size() + 1, 0);
        vector<vector<double>>dp(A.size() + 1, vector<double>(K + 1, 0.0));
        // dp[i][k] represent that maximum score of subSum{i, n} in k groups
        for(int i = 1; i <= A.size(); i++) {
            presum[i] = presum[i - 1] + A[i - 1];
        }
        for(int i = 0; i < A.size(); i++){
            dp[i][0] = 1.0 * (presum[A.size()] - presum[i]) / (A.size() - i);
        }
        for(int k = 1; k <= K; k++) {
            for(int i = A.size(); i >= 0; --i) {
                for(int j = i + 1; j < A.size(); j++){
                    dp[i][k] = max(1.0 * (presum[i] - presum[j]) / (i - j) + dp[j][k - 1], dp[i][k]);
                }
            }
        }
        // for(int i = 0; i <= K; i++) cout << dp[0][i] << " ";
        return dp[0][K - 1];
    }
};