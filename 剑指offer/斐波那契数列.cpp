class Solution {
public:
    typedef long long ll;
    int Fibonacci(int n) {
        vector<int>dp(41,0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
      for(int i = 4; i <= 40; i++)
      {
          dp[i] = dp[i-2] + dp[i-1];
      }
      return dp[n];
    }
};