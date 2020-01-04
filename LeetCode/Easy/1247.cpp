/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-03 22:54:57
 */
class Solution {
public:
    // 1 <= s1.length, s2.length <= 1000
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        if(s1.size() != s2.size()) return -1;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == 'x' && s2[i] == 'y') xy++;
            if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }
        // xy 3 yx 5
        if(yx % 2 != xy % 2) return -1;
        // xy 4 yx 6
        if(xy % 2 == 0) {
            // cout << xy << " " << yx << endl;
            return xy / 2 + yx / 2;
        }
        else { // xy 1 yx 1
            return xy / 2 + yx / 2 + 2;
        }
    }
};