/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-26 10:57:01
 */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 2) return true;
        for(int i = 2; i < coordinates.size(); i++) {
            // (x - x2) * (y1 - y2) - (y - y2) * (x1 - x2) = 0
            if((coordinates[i][0] - coordinates[i - 2][0]) * (coordinates[i - 1][1] - coordinates[i - 2][1]) - 
              (coordinates[i][1] - coordinates[i - 2][1]) * (coordinates[i - 1][0] - coordinates[i - 2][0]) != 0) {
                return false;
            }
            
        }
        return true;
    }
};