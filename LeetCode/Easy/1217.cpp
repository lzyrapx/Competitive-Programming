/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-26 15:00:49
 */
class Solution {
public:
    // 1 <= chips.length <= 100
    // 1 <= chips[i] <= 10^9
    int minCostToMoveChips(vector<int>& chips) {
        int n = chips.size();
        map<string,int> m;
        for(int i = 0; i < n; i++){
            if(chips[i] % 2 == 0)
            {
                m["even"]++;
            }
            else{
                m["odd"]++;
            }
        }
        return min(m["odd"], m["even"]);
    }
};