/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-21 18:24:10
 */ 
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>stack;
        for(int i = 0; i < prices.size(); i++) {
            while(stack.size() >0 && prices[stack.back()] >= prices[i]) {
                prices[stack.back()] -= prices[i];
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return prices;
    }
};