class Solution {
public:
    int solve(vector<int>&prices)
    {
        int ans = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - prices[i - 1] > 0)
            {
                ans += (prices[i] - prices[i - 1]);
            }
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        if(prices.size() == 0) return 0;
        if(prices.size() <= k) {
            return solve(prices);//随便交易
        }
        //local[j] 表示最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润。
        vector<int> local(k + 1, 0); //局部最优解
        
        //global[j] 表示最多可进行j次交易的最大利润。
        vector<int> global(k + 1,0); //全局最优解
        
        for(int i = 0; i < prices.size() - 1; i++)
        {
            int diff = prices[i + 1] - prices[i];
            for(int j = k; j >= 1; --j)
            {
                //局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，
                //和前一天的局部最优加上差值后相比，两者之中取较大值.
                local[j] = max(global[j - 1] + max(diff , 0), local[j] + diff);
                //全局最优比较局部最优和前一天的全局最优.
                global[j] = max(global[j] , local[j]);
            }
        }
        return global[k];
    }
};