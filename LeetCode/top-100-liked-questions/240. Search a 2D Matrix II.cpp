class Solution {
public:
    // O(n + m)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int r = matrix.size();
        int c = matrix[0].size();
        int i = 0;
        int j = c - 1;
        while(j >= 0 && i <= r - 1)
        {
            if(target == matrix[i][j]) return true;
            else if(target > matrix[i][j]) i++;
            else if(target < matrix[i][j]) j--;
        }
        return false;
    }
};