int maxProfit(vector<int>& prices, int fee) {
        int dp1=0; // sell - > having no stock
        int dp2=INT_MIN; // buy -> having 1 stock

        for(auto p : prices) {
          int tmp = dp1;
          dp1 = max(dp1,dp2 + p);
          dp2 = max(dp2,tmp - p - fee);
        }
        // std::cout << "dp1=" << dp1 << '\n';
        // std::cout << "dp2=" << dp2 << '\n';
        return dp1;
    }