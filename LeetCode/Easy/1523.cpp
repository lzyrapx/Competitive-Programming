/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-08-01 19:39:09
 */ 
class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        if(low % 2 == 0 && high % 2 == 0) {
            return (high - low ) / 2;
        }
        if(low % 2 == 0 && high % 2 == 1) {
            return (high - low - 1) / 2 + 1;
        }
        if(low % 2 == 1 && high % 2 == 1) {
            return (high - low - 2) / 2+ 2;
        }
        if(low % 2 == 1 && high % 2 == 0) {
            return (high - low - 1) / 2 + 1;
        }
        return 0;
    }
};