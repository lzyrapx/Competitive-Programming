/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 15:39:27
 */
class Solution {
public:
    // 1 <= books.length <= 100
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        // dp[i] represent as the minimum height that we pick i-th book
        vector<int>dp(books.size() + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= books.size(); i++) {
            int height = 0, width = 0;
            for(int j = i - 1; j >= 0; j--) {
                width += books[j][0];
                if(width > shelf_width) break;
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], dp[j] + height);
            }
        }
        return dp[books.size()];
    }
};