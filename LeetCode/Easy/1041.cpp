/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 15:21:25
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 15:21:25
 */
class Solution {
public:
    bool isRobotBounded(string instructions) {
        // 1: up, 2: right, 3: down, 4 : left
        int dir = 1;
        int x = 0, y = 0;
        for(int i = 0; i < instructions.size(); i++) {
            char c = instructions[i];
            if(c == 'L') {
                if(dir == 1) {
                    dir = 4;
                } else {
                    dir -= 1;
                }
            }
            else if(c == 'R') {
                if(dir == 4) {
                    dir = 1;
                }
                else {
                    dir += 1;
                }
            }
            else if(c == 'G') {
                if(dir == 1) y++; // up
                else if(dir == 2) x++; // right
                else if(dir == 3) y--; // down
                else if(dir == 4) x--; // left
            }
        }
        if(dir == 1) {
            if(x == 0 && y == 0) return true;
            else return false;
        }
        return true;
    }
};