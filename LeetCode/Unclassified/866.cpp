/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-17 01:05:41
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-17 01:05:41
 */
class Solution {
public:
    // 1 <= N <= 1e8
    int primePalindrome(int N) {
        if(N <= 2) return 2;
        if(N >= 8 && N <= 11) return 11;
        for(int i = 1; i <= 1000000; i++) {
            int num = MakePalindrome(i);
            if(num >= N && check(num)) {
                return num;
            }
        }
        return -1;
    }
    int MakePalindrome(int x) {
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        s.pop_back();
        return stoi(s + t);
    }
    bool check(int x) {
        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    }
};