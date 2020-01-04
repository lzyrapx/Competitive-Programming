/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-01 16:47:47
 */
class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int i = -1;
        while(num > 1) {
            i++;
            // cout << num << endl;
            if(num % 2 == 1) {
                num /= 2;
            }
            else {
                ans += 1 << i;
                num /= 2;
            }
        }
        return ans;
    }
};