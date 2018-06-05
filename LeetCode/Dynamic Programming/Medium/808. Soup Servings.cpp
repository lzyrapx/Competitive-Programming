class Solution {
public:
    vector<pair<int,int>>dir = {{-4,0},{-3,-1},{-2,-2},{-1,-3}};
    double soupServings(int N) {
        N = ceil(N / 25.0);
        if(N > 500) return 1.0;
        // dp[i][j] 表示有 i ml A 和 j ml B 的概率，那么最终答案为 dp[N][N].
        vector<vector<double>>dp(N+1,vector<double>(N+1,0));
        
        for(int i = 0; i < N + 1; i++)
        {
            for(int j = 0; j < N + 1; j++)
            {
                if(i == 0 && j > 0)
                {
                    dp[i][j] = 1.0; //A will be empty first
                }
                else if(i == 0 && j == 0)
                {  // 1.0 * 1/2 = 0.5
                    dp[i][j] = 0.5; //A and B become empty at the same time
                }
                else if(i > 0 && j > 0)
                {
                    for(auto d : dir)
                    {
                        dp[i][j] += 0.25 * dp[max(d.first + i, 0)][max(d.second + j,0)];
                    }
                }
            }
        }
        return dp[N][N];
    }
};