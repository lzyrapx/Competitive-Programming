/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-09 15:16:29
 */
class Solution {
public:
    // 1 <= text.length <= 10^4
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(int i = 0; i < text.size(); i++) {
            mp[text[i]] += 1;
        }
        int l = mp['l'] / 2;
        int o = mp['o'] / 2;
        int a = mp['a'];
        int n = mp['n'];
        int ans = min(l, min(o, min(a, n)));
        return ans;
    }
};