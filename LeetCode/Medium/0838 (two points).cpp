/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-07 15:28:45
 */
class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";
        int len = dominoes.size();
        string ans = "";
        for(int i = 0, j = 1; j < len; j++) {
            if(dominoes[j] == '.') continue;
            int mid = j - i - 1;
            if(i > 0) {
                ans += dominoes[i];
            }
            if(dominoes[i] == dominoes[j]) {
                ans += string(mid, dominoes[i]);
            }
            else if(dominoes[i] == 'L' && dominoes[j] == 'R') {
                ans += string(mid, '.');
            }
            else {
                ans += string(mid / 2, 'R') + string(mid % 2, '.') + string(mid / 2, 'L');
            }
            i = j;
        }
        return ans;
    }
};