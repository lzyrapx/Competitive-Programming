/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-03 15:23:39
 */
class Solution {
public:
    // num: [-1e7, 1e7]
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans = "";
        int f = 0;
        if(num < 0) {
            f = 1;
            num = -num;
        }
        while(num > 0) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        if(f == 1) {
            ans = "-" + ans;
        }
        return ans;
    }
};