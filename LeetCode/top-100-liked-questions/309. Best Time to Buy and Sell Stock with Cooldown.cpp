class Solution {
public:
 int maxProfit(vector<int>& prices) {
        std::vector<int> dp(prices.size()+1,0);

        int ans = 0;
        if(prices.size() < 2) return 0;
        std::vector<int> buy(prices.size()+1,0);
        std::vector<int> sell(prices.size()+1,0);
        buy[0] = - prices[0];
        for(int i = 1;i < (int)prices.size();i++) 
        {
          //( sell[i-1] - prices[i-1] ) + prices[i] : bought stock back and sell it on day i
            sell[i] = max(buy[i-1] + prices[i], ( sell[i-1] - prices[i-1] ) + prices[i]);
            if(sell[i] > ans) {
              ans = sell[i];
            }
            if(i == 1) {
              buy[1] = buy[0] + prices[0] - prices[1];
            }
            else
            {
              // (buy[i-1] + prices[i-1]) - prices[i] : didn’t buy the stock on day i-1 but buy it on day i
              buy[i] = max(sell[i - 2] - prices[i], (buy[i-1] + prices[i-1]) - prices[i]);
            }
        }
        return ans;
    }
};