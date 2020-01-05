/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-05 22:09:27
 */
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ans;
        for(int i = 0; i < bits.size(); i++) {
            if(bits[i] > 0) {
                ans = 0;
                i += 1;
            }
            else {
                ans = 1;
            }
        }
        return ans;
    }
};