/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-12 00:23:24
 */
class Solution {
public:
    // 2 <= arr.length <= 40
    // 1 <= arr[i] <= 15
    // DP：O(n^3)
    // Greedy: O(n^2)
    int mctFromLeafValues(vector<int>& arr) {
        if(arr.size() == 1) {
            return 0;
        }
        int sum = 0;
        while(arr.size() > 1) {
            int min_product = INT_MAX;
            int idx = -1; 
            for(int i = 1; i < arr.size(); i++) {
                if(min_product > arr[i - 1] * arr[i]) {
                    idx = arr[i - 1] < arr[i] ? i - 1: i;
                    min_product = arr[i - 1] * arr[i];
                }
            }
            sum += min_product;
            arr.erase(arr.begin() + idx);
        }
        return sum;
    }
};