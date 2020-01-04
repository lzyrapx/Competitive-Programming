/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-09 14:51:21
 */
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    // 1 <= function_id <= 9
    // 1 <= z <= 100
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>ans;
        for(int i = 1; i <= 1000; i++) {
            for(int j = 1; j <= 1000; j++) {
                if(customfunction.f(i, j) == z) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};