/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-09 17:57:00
 */
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0;
        for(int x: distance) {
            sum += x;
        }
        int sum1 = 0;
        for(int i = start; i != destination; i = (i + 1) % distance.size()) {
            sum1 += distance[i];
        }
        return min(sum1, sum - sum1);
    }
};