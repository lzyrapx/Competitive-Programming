class Solution {
public:
    // 模式中的字符'.'表示任意一个字符
    // '*'表示它前面的字符可以出现任意次（包含0次）
    bool match(char* str, char* pattern)
    {
        int lenA = strlen(str);
        int lenB = strlen(pattern);
        vector<vector<bool> > dp(lenA + 1, vector<bool>(lenB + 1, false));
        dp[0][0] = true;
        for(int i = 1; i < dp[0].size(); i++) {
            if(pattern[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for(int i = 1; i <= lenA; i++) {
            for(int j = 1; j <= lenB; j++) {
                if(pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(pattern[j - 1] == '*') {
                    if(pattern[j - 2] != str[i - 1] && pattern[j - 2] != '.') {
                        dp[i][j] = dp[i][j - 2]; // a*匹配0次
                    }
                    
                    else if(pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.') {
                           dp[i][j] = dp[i][j] || dp[i][j - 2];  // a*匹配0次
                           dp[i][j] = dp[i][j] || dp[i][j - 1]; // a*匹配1次
                           dp[i][j] = dp[i][j] || dp[i - 1][j]; // a*匹配多次
                    }
                }
            }
        }
        return dp[lenA][lenB];
    }
};