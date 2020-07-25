/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-25 12:19:57
 */ 
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange) return numBottles;
        int ans = numBottles;
        int empty = numBottles;
        while(empty >= numExchange) {
            ans += (empty / numExchange);
            empty = (empty % numExchange) + (empty / numExchange);
        }
        return ans;
    }
};