class Solution {
public:
    int rectCover(int number) {
        if(number == 0) return 0;
        vector<int>dp(number+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= number; i++)
        {
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[number];
    }
};