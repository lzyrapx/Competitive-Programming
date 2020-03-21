/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-21 14:31:09
 */
class Solution {
public:
    // 1 <= arr.length <= 10^5
    int maximumSum(vector<int>& arr) {
        int ans = arr[0];
        int nonSkip = arr[0];
        int skip = 0;
        for(int i = 1; i < arr.size(); i++) {
            int tmp = nonSkip;
            nonSkip = max(0, nonSkip) + arr[i];
            skip = max(skip + arr[i], tmp);
            ans = max(ans, max(skip, nonSkip));
        }
        return ans;
    }
};