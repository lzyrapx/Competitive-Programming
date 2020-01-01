/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-01 21:42:08
 */
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i = sqrt(area);
        while(area % i != 0) {
            i--;
        }
       return vector<int>{area / i, i};
    }
};