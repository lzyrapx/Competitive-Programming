/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-18 23:39:24
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-18 23:39:24
 */
class Solution {
public: 
    // 1 <= N <= 1e9
    bool reorderedPowerOf2(int N) {
        set<string>pre;
        string s;
        for(int i = 0; i <= 34; i++) {
            if((1 << i) < 0) break;
            s = to_string(1 << i);
            sort(s.begin(),s.end());
            pre.insert(s);
        }
        s = to_string(N);
        sort(s.begin(), s.end());
        if(pre.count(s)) return true;
        return false;
    }
};