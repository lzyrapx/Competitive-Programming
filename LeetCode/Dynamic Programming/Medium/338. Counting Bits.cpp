class Solution {
public:
    vector<int> countBits(int num) {
      std::vector<int> dp(num+1,0);
      dp[0] = 0;
      for(int i=1;i<=num;i++) {
        dp[i] = dp[i&(i-1)] + 1;
      }
      return dp;
    }
};