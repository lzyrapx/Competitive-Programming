/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-01 16:25:45
 */
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(heaters.size() == 0) {
            return 0;
        }
        int ans = 0;
        int index = 0;
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        for(int i = 0; i < houses.size(); i++) {
            // 找到距离 house[i] 最近的加热器
            while((index + 1) < (int)heaters.size() && (abs(heaters[index + 1] - houses[i]) <= abs(heaters[index] - houses[i]))) {
                      index++;
            }
            ans = max(ans, abs(heaters[index] - houses[i]));
        }
        return ans;
    }
};