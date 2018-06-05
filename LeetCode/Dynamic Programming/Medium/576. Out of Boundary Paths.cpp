class Solution {
public:
    // m * n 的图
    // N步
    long long dp[51][51][51]; // dp i, j , k 表示从 (j ,k)开始走，可以走N步走出界的路径条数

    int findPaths(int m, int n, int N, int i, int j) {
      for(int a = 1;a <= N;a++) 
      {
        for(int b = 0;b < m; b++) { // cur_i
          for(int c = 0;c < n; c++) { // cur_j
            dp[a][b][c] = ( ( b == 0 ? 1 : dp[a - 1][b - 1][c]) +
            (b == m - 1? 1 : dp[a - 1][b + 1][c]) +( c == 0 ? 1 : dp[a - 1][b][c - 1]) +
            (c == n - 1 ? 1 :dp[a - 1][b][c + 1])  ) % 1000000007;
          }
        }
      }
      return dp[N][i][j];
   }
};