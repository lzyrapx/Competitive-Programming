class Solution {
public:
    // 就是个最长公共子序列
    int minDistance(string word1, string word2) {
        if(word1.size()==0 && word2.size()==0) return 0;
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i = 0; i <= word1.size();i++) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= word2.size(); i++) {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int val = dp[word1.size()][word2.size()];
        return word1.size() - val + word2.size() - val;
    }
};