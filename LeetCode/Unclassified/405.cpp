/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-05 22:27:27
 */
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ans;
        unsigned int n = num; // must be unsigned int 
        while(n > 0) {
            int d = n % 16;
            n /= 16;
            if(d < 10) {
                ans = string(1,'0' + d) + ans;
            }
            else {
                ans = string(1,'a' + d - 10) + ans;
            }
        }
        return ans;
    }
};