/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-15 22:16:39
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-15 22:16:39
 */
class Solution {
public:
    // 0 <= num <= 1e8
    int maximumSwap(int num) {
        int ans = num;
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++) { // maxinum s.size() is 9, so O(9*9)
            for(int j = i + 1; j < s.size(); j++) {
                if((s[i] - '0') < (s[j] - '0')) {
                    swap(s[i], s[j]);
                    ans = max(ans, stoi(s));
                    swap(s[i], s[j]);
                }
            }
        }
        return ans;
    }
};