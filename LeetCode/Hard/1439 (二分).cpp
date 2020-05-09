/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-05 17:51:08
 */
class Solution {
public:
    // 这个数据量这么少...可以直接暴力...暴力的话复杂度是O(n * m * k * log(m*k))...
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int left = m, right = m * 5000;
        while(left < right) {
            int mid = left + (right - left) / 2;
            // target-sum, mat, k, path-sum, row
            int cnt = dfs(mid, mat, k, 0, 0);
            if(cnt >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    int dfs(int target_sum, vector<vector<int>>&mat, int k, int path_sum, int row) {
        if(path_sum > target_sum) return 0;
        if(row == mat.size()) return 1;
        int ans = 0;
        for(int c = 0; c < mat[0].size(); c++) {
            int cnt = dfs(target_sum, mat, k - ans, path_sum + mat[row][c], row + 1);
            ans += cnt;
            if(cnt == 0) break; // 剪枝
            if(cnt > k) break; 
        }
        return ans;
    }
};