class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int sz = prices.size();
        // local[i][j] 表示 前 i 天进行了 j 次交易，并且最后一天是最后一次交易卖出的最大利润，局部最优
        vector<vector<int>>local(sz + 1, vector<int>(3,0));
        // local[i][j] 表示 前 i 天进行了 j 次交易的最大利润, 全局最优
        vector<vector<int>>global(sz + 1, vector<int>(3,0));
        
        for(int i = 1; i < sz; i++)
        {
            int diff = prices[i] - prices[i-1];
            for(int j = 1; j <= 2; j ++)
            {
                local[i][j] = max(global[i-1][j-1] + max(diff,0), local[i-1][j] + diff);
                global[i][j] = max(local[i][j],global[i-1][j]);
            }
        }
        return global[sz-1][2];
    }
};