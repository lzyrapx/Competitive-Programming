/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-23 00:36:26
 */
class Solution {
public:
    // 2 <= word.length <= 300
    int getDis(int from, int to) {
        if(from == 26) {
            return 0;
        }
        return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    }
    int dp[301][27][27];
    int minimumDistance(string word) {
        for(int num = word.size() - 1; num >= 0; --num) {
            auto to = word[num] - 'A';
            for(int i = 0; i <= 26; i++) {
                for(int j = 0; j <= 26; j++) {
                    dp[num][i][j] = min(dp[num + 1][i][to] + getDis(j, to), dp[num + 1][j][to] + getDis(i, to));
                }
            }
        }
        return dp[0][26][26];
    }
};