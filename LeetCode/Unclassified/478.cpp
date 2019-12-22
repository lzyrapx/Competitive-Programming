/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-15 18:33:40
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-15 18:33:40
 */
class Solution {
private:
    double r, x, y;
public:
    // [1,0,0]: 1 is radius, 0,0: is the center of a circle
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        while(true){
            double x1 = (2 * 1.0 * rand() / RAND_MAX - 1.0) * r;
            double y1 = (2 * 1.0 * rand() / RAND_MAX - 1.0) * r;
            if(x1 * x1 + y1 * y1 <= r * r) {
                return {x + x1, y + y1};
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */