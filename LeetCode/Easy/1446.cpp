/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-17 00:44:19
 */ 
class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 1) {
            return 1;
        }
        int len = 1;
        int ans = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                len++;
            }
            else {
                len = 1;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};