/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-04 19:10:48
 */
class Solution {
public:
    string defangIPaddr(string address) {
        if(address.size() == 0) {
            return "";
        }
        string ans = "";
        for(int i = 0; i < address.size(); i++) {
            if(address[i] == '.') {
                ans = ans + "[" + "." + "]";
            }
            else {
                ans = ans + address[i];
            }
        }
        return ans;
    }
};