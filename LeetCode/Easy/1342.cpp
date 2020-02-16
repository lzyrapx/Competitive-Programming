/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-16 19:13:41
 */
class Solution {
public:
    int numberOfSteps (int num) {
        if(num == 0) {
            return 0;
        }
        int cnt = 0;
        while(num > 0) {
            if(num & 1) {
                num -= 1;
            }
            else {
                num /= 2;
            }
            cnt++;
        }
        return cnt;
    }
};