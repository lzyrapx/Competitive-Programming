/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-07 13:48:57
 */ 
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cur_diff = 0;
        int last_diff = -1;
        for(int i = 1; i < arr.size(); i++) {
            cur_diff = arr[i] - arr[i - 1];
            if(last_diff == -1) {
                last_diff = cur_diff;
            }
            else {
                if(last_diff != cur_diff) {
                    return false;
                }
            }
        }
        return true;
    }
};