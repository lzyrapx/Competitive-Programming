/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-29 22:52:19
 */
class Solution {
public:
    int has_lower = 0, has_upper = 0, has_digit = 0;
    int rep = 0;
    vector<int>repeat;
    int rep_1 = 0, rep_2 = 0;
    void check(string s) {
        int cnt = 0;
        char c = '@';
        for(int i = 0; i < s.size(); i++) {
            if(isupper(s[i])) {
                has_upper = 1;
            }
            if(islower(s[i])) {
                has_lower = 1;
            }
            if(isdigit(s[i])) {
                has_digit = 1;
            }
            if(s[i] == c) {
                cnt++;
            }
            else {
                if(cnt >= 3) {
                    repeat.push_back(cnt);
                }
                c = s[i];
                cnt = 1;
            }
        }
        if(cnt >= 3) {
            repeat.push_back(cnt);
        }
        for(auto x: repeat) {
            if(x % 3 == 0) { 
                rep_1 += 1; 
            }
            if(x % 3 == 1) {
                rep_2 += 1;
            }
            rep += x / 3; // rep: 如果连续次数超过3，则将其替换字母，使得其连续字母个数不超过3的操作数
        }
    }
    // 连续重复长度是3的倍数的改一个，余数为1的改两个，余数为2的改三个，改一个算一个操作
    int strongPasswordChecker(string s) {
        if(s.size() == 0) {
            return 6;
        }
        check(s);
        int letter = 3 - has_upper - has_lower - has_digit;
        if(s.size() < 6) {
            return max(6 - (int)s.size(), letter);
        }
        if(s.size() <= 20 && s.size() >= 6) {
            return max(rep, letter);
        }
        if(s.size() > 20) {
            int remain = s.size() - 20;
            if(remain <= rep_1) {
                rep -= remain;
            }
            else if(remain - rep_1 <= 2 * rep_2) {
                rep -= rep_1 + (remain - rep_1) / 2;
            }
            else {
                rep -= rep_1 + rep_2 + (remain - rep_1 - 2 * rep_2) / 3;
            }
            return remain + max(rep, letter);
        }
        return 0;
    }
};