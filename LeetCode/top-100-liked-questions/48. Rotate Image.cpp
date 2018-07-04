class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size(); // 行
        int c = matrix[0].size(); // 列
        for(int i = 0, j = r - 1; i < (r / 2); i++, j--) {
            swap(matrix[i],matrix[j]);
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};