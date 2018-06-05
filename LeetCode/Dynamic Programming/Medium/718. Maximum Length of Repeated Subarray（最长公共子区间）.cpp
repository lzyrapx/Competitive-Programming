class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        
        int lenA = A.size();
        int lenB = B.size();
        if(lenA < 1 || lenB < 1) return 0;
        // dp[i][j] 表示 以 A[i] 和 B[i] 结尾 的 最长公共子区间
        vector<vector<int>>dp(lenA+1,vector<int>(lenB+1,0));
        int ans = 0;
        for(int i = 0 ; i <= lenA;i++) 
        {
            
            for(int j = 0; j <= lenB;j++) 
            {
                if(i == 0 || j == 0) 
                {
                    dp[i][j] = 0;
                }
                else if(A[i-1] == B[j-1]) 
                {
                    dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};