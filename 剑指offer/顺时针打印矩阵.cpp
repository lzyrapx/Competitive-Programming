class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        if(n == 0 || m == 0) return ans;
        int left=0,right=m-1;
        int up=0,bottom=n-1;
        while(left <= right && up <=bottom)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[up][i]);
            }
            for(int i=up+1;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            if(up!=bottom) //防止单行的情况
            for(int i=right-1;i>=left;--i)
            {
                ans.push_back(matrix[bottom][i]);
            }
            if(left!=right) // 防止单列的情况
            for(int i=bottom-1;i>up;--i)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;up++;
            right--;bottom--;
        }
        return ans;
    }
};