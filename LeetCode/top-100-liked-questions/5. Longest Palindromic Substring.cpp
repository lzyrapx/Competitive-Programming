class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        // dp[i][j] = if s[i...j] is palindromic 
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,1));
        int maxlen = 1; // 至少是 1
        int head = 0;
        for(int len = 2; len <= s.size(); len++) 
        {
            for(int i = 0; i + len - 1 < s.size(); i++) 
            {
                int j = i + len - 1;
                dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
                if(dp[i][j] == 1 && len >= maxlen) 
                {
                    head = i;
                    maxlen = len;
                }
            }
        }
        return s.substr(head,maxlen);
    }
};