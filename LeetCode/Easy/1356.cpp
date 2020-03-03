/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-03 20:49:59
 */
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int x, int y) -> bool {
           if(__builtin_popcount(x) == __builtin_popcount(y)) return x < y;
           else return __builtin_popcount(x) < __builtin_popcount(y);
        });
        return arr;
    }
};