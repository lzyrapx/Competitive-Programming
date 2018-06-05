class Solution {
public:
    /*
    dp[i][j][k]，表示区间[i, j]中能获得的最大积分，当boxes[i]左边有k个数字跟其相等，那么我们的目标就是要求dp[0][n-1][0]了，
    而且我们也能推出dp[i][i][k]= (1+k) * (1+k)这个等式。那么我们来推导重现关系，对于dp[i][j][k]，
    如果我们移除boxes[i]，那么我们得到(1+k)*(1+k) + dp[i+1][j][0]。对于上面提到的那种情况，
    当某个位置pos，有boxes[i] == boxes[pos]时，我们也应该考虑先移除[i+1,pos-1]这部分，我们得到积分dp[i+1][pos-1][0]，
    然后再处理剩下的部分，得到积分dp[pos][j][k+1]，这里k加1点原因是，移除了中间的部分后，原本和boxes[pos]不相邻的boxes[i]现在相邻.
    又因为二者值相同，所以k应该加1，因为k的定义就是左边相等的数字的个数。
    */
    int dfs(vector<int>&boxes, int i, int j, int k, int dp[101][101][101])
    {
        if(i > j) return 0;
        if(dp[i][j][k]) return dp[i][j][k];
        int ans = (1 + k) * (1 + k) + dfs(boxes, i + 1, j, 0, dp);
        for(int pos = i + 1; pos <= j; pos++)
        {
            if(boxes[i] == boxes[pos])
            {
                ans = max(ans, dfs(boxes,i + 1, pos - 1, 0, dp) + dfs(boxes, pos, j ,k + 1, dp));
            }
        }
        dp[i][j][k] = ans;
        return ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        int sz = boxes.size();
        if(sz == 0) return 0;
        int dp[101][101][101]={0};
        return dfs(boxes, 0 ,sz - 1, 0 , dp);
    }
};