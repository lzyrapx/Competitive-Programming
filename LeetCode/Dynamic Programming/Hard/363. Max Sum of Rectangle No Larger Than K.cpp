class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0) return 0;
        
        // rowsum[i][j] 表示第 i 行 前 j 个数的和
        vector<vector<int> > rowsum(matrix.size() + 1,vector<int>(matrix[0].size() + 1,0));
        
        int m = matrix.size();
        int n = matrix[0].size();
      
        for(int i = 0 ; i < matrix.size();i++)
        {
            rowsum[i][0] = 0;
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                rowsum[i][j] = rowsum[i][j-1] + matrix[i-1][j-1];
               // cout << "sum = " << rowsum[i][j] << endl;
            }
        }
        int area = 0;
        int ans = -9999999;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = i; j <= n; j++)
            {
                for(int k1 = 1; k1 <= m; k1++) //从 第 k1 行开始
                {
                    area = 0;
                    for(int r = k1; r <= m; r++) //枚举行
                    {
                   
                        area += rowsum[r][j] - rowsum[r][i - 1];
                        // cout <<"area = " << area << endl;
                        if(area <= k ) {
                            ans = max(ans,area);
                        }
                         // if(area < 0) area = 0;
                     }
                }
                
            }
        }
        return ans;
    }
};