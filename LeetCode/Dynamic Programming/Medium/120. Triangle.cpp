class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         // 从底到上
        for(int i = triangle.size() -2 ;i >= 0; --i) {
            for(int j = 0; j <triangle[i].size() ; j++) {
                triangle[i][j] = min(triangle[i+1][j+1],triangle[i+1][j]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};