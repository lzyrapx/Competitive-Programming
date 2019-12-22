/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-26 13:38:37
 */
class Solution {
public:
    // 1 <= s.length <= 1000
    int balancedStringSplit(string s) {
        if(s.size() <= 1) return 0;
        int cnt = 0;
        int R = 0;
        int L = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'R') {
                R ++;
            }
            if(s[i] == 'L') {
                L ++;
            }
            if(R == L) {
                cnt ++;
                R = 0;
                L = 0;
            }
        }
        return cnt;
    }
};