class Solution {
public:
int isprime(int x)
{
  if(x<2)return 0;
  if(x==2)return 1;
  for(int i=2;i*i<=x;i++) {
    if(x % i==0)return 0;
  }
  return 1;
}
int minSteps(int n) {
      vector<int>dp(3*n+1,0);
      dp[0] = 0;
      dp[1] = 0;
      dp[2] = 2; dp[3]=3;
      for(int i=2;i<=n;i++) {

        if(isprime(i)) {
          dp[i] = i;
        }
        if(i % 23 == 0) {
          dp[i] = dp[i / 23] + 23;
        }
        else if(i % 19== 0) {
          dp[i] = dp[i / 19] + 19;
        }
        else if(i % 17 == 0) {
          dp[i] = dp[i / 17] + 17;
        }
        else if(i % 13 == 0) {
          dp[i] = dp[i / 13] + 13;
        }
        else if(i % 11 == 0) {
          dp[i] = dp[i / 11] + 11;
        }
        else if(i % 7 == 0) {
          dp[i] = dp[i / 7] + 7;
        }
        else if(i % 5 == 0) {
          dp[i] = dp[i/5] + 5;
        }
        else if(i % 3 == 0 && i % 2 == 0) {
          dp[i] = dp[i / 2] + 2;
        }
        else if(i % 2 == 0 && i % 3!= 0) {
          dp[i] = dp[i / 2] + 2;
        }
        else if(i%3 == 0 && i % 2!=0) {
          dp[i] = dp[i / 3] + 3;
        }
      }
      return dp[n];
    }
};