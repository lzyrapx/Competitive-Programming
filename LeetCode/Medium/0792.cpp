class Solution {
public:
    // 给一个字符串s和一系列 words，问你这些words里有多少个是字符串s的子序列(非连续)
    int numMatchingSubseq(string S, vector<string>& words) {
        if(S.size() == 0 || words.size() == 0) {
            return 0;
        }
        //dp[i][j]表示从S的第i个字符开始，字母j所处的位置。
        vector<vector<int>>dp(S.size() + 1, vector<int>(26, 0));
        int n = S.size();
        for(int i = 0; i < 26; i++) {
            dp[n][i] = n; // n 代表不存在
        }
        for(int i = n - 1; i >= 0; --i){
            for(int j = 0; j < 26; j++) {
                if(S[i] == 'a' + j) {
                    dp[i][j] = dp[i][j] = i;
                }
                else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        int cnt = 0;
        for(string word: words) {
            int len = word.size();
            int add = 0;
            bool isSubseq = true;
            for(int i = 0; i < len; i++) {
                if(dp[add][word[i] - 'a'] == n) {
                    isSubseq = false;
                    break;
                }
                // add跳到匹配word[i]的下标位置，并且+1
                add = dp[add][word[i] - 'a'] + 1;
            }
            if(isSubseq) {
                cnt++;
            }
        }
        return cnt;
    }
};