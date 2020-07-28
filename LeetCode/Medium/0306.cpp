/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-28 23:29:15
 */ 
class Solution {
public:
    bool dfs(string first, string second, int pos, string num) {
        if(pos == num.size()) {
            return true;
        }
        if(pos > num.size()) {
            return false;
        }
        string nxt = to_string(stoll(first) + stoll(second));
        int len = nxt.size();
        if(len + pos <= num.size() && num.substr(pos, len) == nxt) {
            return dfs(second, nxt, len + pos, num);
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for(int i = 1; i <= len / 2; i++) {
            string first = num.substr(0, i);
            if(i > 1 && first[0] == '0') continue;
            for(int j = 1; len - i - j >= max(i, j); j++) {
                string second = num.substr(i, j);
                if(j > 1 && second[0] == '0') continue;
                if(dfs(first, second, i + j, num)) {
                    return true;
                }
            }
        }
        return false;
    }
};