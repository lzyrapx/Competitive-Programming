/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-04 15:04:49
 */
class Solution {
public:
    // 一开始 0 分，总分在小于K分的时候抽卡，每次抽到的卡的范围是1-W，
    // 每次抽卡独立概率相等，当抽到大于等于1分之后停止抽卡
    // 问得到 N 分或更少分数的概率.
    double new21Game(int N, int K, int W) {
        if(K == 0) {
            return 1;
        }
        if(N == 0) {
            return 0;
        }
        if(K > N) {
            return 0;
        }
        // dp[i] represent that the probability when get i points totally, final answer is sum(dp[k:])
        // 当i <= K时，dp[i] = （前W个dp的和）/ W
        vector<double>dp(N + 1, 0);
        dp[0] = 1.0;
        double ans = 0.0;
        double psum = 1.0;
        for(int i = 1; i <= N; i++) {
            dp[i] = 1.0 * psum / W;
            if(i < K) {
                psum += dp[i];
            }
            else {
                ans += dp[i];
            }
            if(i >= W) { // 重复的范围
                psum -= dp[i - W];
            }
        }
        return ans;
    }
};