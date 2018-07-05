class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>dp(100000,0);
        dp[0] = 0;
        int minn = 1000000;
        int ans = 0;
        for(int i =0 ; i < (int)prices.size();i++) {
            minn = min(minn,prices[i]);
            // std::cout << "prices=" << prices[i] << '\n';
            // std::cout << "minn = " << minn << '\n';
            // std::cout << "dp="<<dp[i-1] << '\n';
            // std::cout  << '\n';
            if(prices[i] > minn) {
                dp[i] = max(dp[i-1],prices[i]-minn);
                ans = max(dp[i],ans);
            }
        }
        return ans;
    }
};