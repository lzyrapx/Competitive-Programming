/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-07 19:24:25
 */ 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int minSum = INT_MAX;
        int idx = 0;
        for(int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            if(sum < minSum) {
                minSum = sum;
                idx = i;
            }
        }
        if(sum >= 0) {
            return (idx + 1) % gas.size();
        }
        else {
            return -1;
        }
    }
};