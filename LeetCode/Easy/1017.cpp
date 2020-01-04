/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 15:35:11
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 15:35:11
 */
class Solution {
public:
    string baseNeg2(int N) {
        if(N == 0) return "0"; 
        string ans;
        while(N != 0) {
            if(abs(N & 1) == 1) {
                ans = ans + '1';
                N = (N - 1) / (-2);
            } else {
                ans = ans + "0";
                N = N / (-2);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};