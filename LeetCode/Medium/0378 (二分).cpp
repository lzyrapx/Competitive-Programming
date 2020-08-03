class Solution {
public:
    int count(vector<vector<int>>&matrix, int val) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        int row = 0;
        int col = m - 1;
        while(row < n && col >= 0) {
            if(val >= matrix[row][col]) {
                cnt += col + 1;
                row ++;
            } else {
                col--;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n - 1][m - 1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = count(matrix, mid); // 矩阵中小于等于 mid 的个数
            if(cnt < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};