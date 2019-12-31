/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-28 23:47:04
 */
class Solution {
public:
    string toLowerCase(string str) {
        string ans = "";
        for(int i = 0; i < str.size(); i++) {
            ans += tolower(str[i]);
        }
        return ans;
    }
};