/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-07 17:42:01
 */
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        if(A.size() <= 2) {
            return 0;
        }
        map<int,int>mp;
        // dp[i][j], the length of longest fibonacci subsequence with last two terms A[i] and A[j]
        vector<vector<int>>dp(A.size(), vector<int>(A.size(), 2));
        int ans = 0;
        for(int i = 0; i < A.size(); i++) {
            int s = 0;
            int e = i - 1;
            while(s < e) {
                if(A[s] + A[e] == A[i]) {
                    dp[e][i] = max(dp[e][i], dp[s][e] + 1);
                    ans = max(ans, dp[e][i]);
                    s++;
                    e--;
                }
                else if(A[s] + A[e] < A[i]) {
                    s++;
                }
                else {
                    e--;
                }
            }
        }
        return ans == 2 ? 0 : ans;
    }
};