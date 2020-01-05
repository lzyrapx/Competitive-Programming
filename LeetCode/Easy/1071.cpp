/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 23:43:22
 */
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2 + str1) {
            return str1.substr(0, gcd(str1.size(), str2.size()));
        }
        return "";
    }
};