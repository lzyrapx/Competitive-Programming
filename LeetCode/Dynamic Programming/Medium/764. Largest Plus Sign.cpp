class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        
        if(N == 0) return 0;
        //对于第i行第j列的元素grid[i][j]表示的是这个元素的plus sign的大小
        //初始化不在mines中的元素对应的grid值为较大值（只要大于N/2即可）
        vector<vector<int>>grid(N+1,vector<int>(N+1,N));
        
        for(vector<int>& m : mines)
        {//在mines中的元素对应的grid值为 0
            grid[m[0]][m[1]] = 0;
        }
        for(int i = 0; i < N; i++)
        {
            int l = 0, r = 0, u = 0, d = 0;
            
            for(int j = 0, k = N - 1; j < N ; j++, k--)
            {
                //左到右
                grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));
                //右到左
                grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0 ? 0 : r + 1));
                //上到下
                grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));
                //下到上
                grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0 ? 0 : d + 1));
            }
        }
        int ans = 0;
        for(int i = 0; i < N ; i++)
        {
            for(int j = 0; j < N; j++)
            {
                ans = max(ans,grid[i][j]);
            }
        }
        return ans;
    }
};