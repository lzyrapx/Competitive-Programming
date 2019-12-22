/*
 * @Descripttion: Prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-11 09:10:12
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-11 09:10:12
 */
class Solution {
public:
    // if N is even, Alice win
    // if N is odd, Bob win
    bool divisorGame(int N) {
        return !(N & 1);
    }
};