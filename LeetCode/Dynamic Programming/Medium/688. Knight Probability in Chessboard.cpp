class Solution {
public:
    int dir[8][2]= {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    // double dp[123][123];
    // double dp2[123][123];
    
    double dp[123][27][27]; 
    // dp[k][i][j] 表示 花费 k 步 到达点(i,j)时的概率。那么答案为 dp[K][\sum_{i}][\sum_{j}].

    double knightProbability(int N, int K, int r, int c) {
        
        
        dp[0][r][c] = 1;
        
        for(int step = 1; step <= K; step++)
        {
            for(int i = 0; i < N ; i++) //行
            {
                for(int j = 0; j < N; j++) //列
                {
                    for(int k = 0; k < 8; k++) 
                    {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if(nx >=0 && nx < N && ny >= 0 && ny < N)
                        {
                            dp[step][i][j] += (dp[step-1][nx][ny] / 8.0);
                        }
                    }
                }
            }
        }
        double ans = 0.0;
        for(int i = 0;i < N; i++)
        {
            for(int j = 0; j < N ;j++)
            {
                ans += dp[K][i][j];
            }
        }
        return ans;
    }
};