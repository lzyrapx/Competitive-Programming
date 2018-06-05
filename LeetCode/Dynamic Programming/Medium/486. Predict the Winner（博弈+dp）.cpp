class Solution {
public:
      bool PredictTheWinner(vector<int>& nums) {
          
     int sz = nums.size();
     if(nums.size()<=1)return 1;
     // dp[i][j] = max(num[i] - dp[i-1][j],num[j]-dp[i][j-1])
    std::vector<std::vector<int> > dp(sz+2,std::vector<int>(sz+2,0));
    for(int s = sz; s >= 0; --s)
    {
      for(int e = s + 1; e < sz; e++) {
        dp[s][e] = max(nums[s] - dp[s+1][e], nums[e] - dp[s][e-1]);
      }
    }
    int player1 = dp[0][sz-1];
    return player1 >= 0;
   }
};