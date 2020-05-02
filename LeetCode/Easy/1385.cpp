/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-02 14:24:03
 */
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(int i = 0; i < arr1.size(); i++) {
            int ok = 1;
            for(int j = 0; j < arr2.size(); j++) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    ok = 0;
                    break;
                }
            }
            if(ok == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};