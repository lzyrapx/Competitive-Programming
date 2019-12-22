/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-14 01:27:08
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-14 13:08:48
 */
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans;
        int level = log2(label);
        while(level > 0) {
            ans.insert(ans.begin(), label);
            int twoLevelSum = pow(2, level) + pow(2 ,level - 1) - 1;
            label = twoLevelSum - label / 2;
            level -= 1;
        }
        ans.insert(ans.begin(), 1);
        return ans;
    }
};
