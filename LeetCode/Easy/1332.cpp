/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-16 18:48:25
 */
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 0) {
            return 0;
        }
        bool isP = 1;
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size() - 1 - i]) {
                isP = 0;
                break;
            }
        }
        return isP ? 1 : 2;
    }
};