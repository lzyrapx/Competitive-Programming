class Solution {
public:
 int maxProfit(vector<int>& prices) {
        std::vector<int> dp(prices.size()+1,0);

        int ans = 0;
        if(prices.size() < 2) return 0;
        std::vector<int> buy(prices.size()+1,0);
        std::vector<int> sell(prices.size()+1,0);
        buy[0] = - prices[0];
        for(int i = 1;i < (int)prices.size();i++) {
        	// buy[i-1]+prices[i] represents buy the stock on day i-1 and sell it on day i;
           // ( sell[i-1] - prices[i-1] ) + prices[i] : didn’t sell the stock on day i-1 but sell it on day i , just bought stock back and sell it on day i
            sell[i] = max(buy[i-1] + prices[i], ( sell[i-1] - prices[i-1] ) + prices[i]);
            if(sell[i] > ans) {
              ans = sell[i];
            }
            if(i == 1) {
              buy[1] = buy[0] + prices[0] - prices[1];
            }
            else
            {
              // sell[i-2] - prices[i] means sold the stock on day i-2 and buy it on day i (day i-1 is cooldown).
              // (buy[i-1] + prices[i-1]) - prices[i] : didn’t buy the stock on day i-1 but buy it on day i
              buy[i] = max(sell[i - 2] - prices[i], (buy[i-1] + prices[i-1]) - prices[i]);
            }
        }
        return ans;
    }
};
/*
Define buy[i] as the max profit when you buy the stock at day i. sell[i] as the max profit when you sell the stock at day i. 
Therefore set buy[0] = -prices[0], that if you buy the stock at first day, the profit is -prices[0], also set sell[0] = 0, that you do nothing in the first day.

sell[i]=max(buy[i-1]+prices[i], sell[i-1]-prices[i-1]+prices[i]);

buy[i-1]+prices[i] represents buy the stock on day i-1 and sell it on day i; 
sell[i-1]-prices[i-1]+prices[i] represents you didn’t sell the stock on day i-1 but sell it on day i (bought stock back and sell it on day i).

buy[i]=max(sell[i-2]-prices[i], buy[i-1]+prices[i-1]-prices[i]);

sell[i-2]-prices[i] means sold the stock on day i-2 and buy it on day i (day i-1 is cooldown). 
buy[i-1]+prices[i-1]-prices[i] means you didn’t buy the stock on day i-1 but buy it on day i.

No doubt that the max profit would appear in sell[i].
*/