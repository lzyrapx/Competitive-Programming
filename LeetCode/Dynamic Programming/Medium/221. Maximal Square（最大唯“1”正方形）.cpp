class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        //dp[i][j]表示到 点(i,j) 时得到的 最大唯“1”子正方形(square)的最大边
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        int maxsize = 0;
        for(int i = 0; i < n; i++) 
        {
            dp[0][i] = matrix[0][i] - '0';
            maxsize = max(maxsize,dp[0][i]);
        }
        for(int i= 0 ;i < m ;i ++)
        {
            dp[i][0] = matrix[i][0] -'0';
            maxsize = max(maxsize,dp[i][0]);
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j - 1] , min( dp[i - 1][j], dp[i][j - 1])) + 1;
                    maxsize = max(maxsize,dp[i][j]);
                }
            }
        }
        return maxsize * maxsize;
    }
};