/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 15:22:09
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(i < k) {
                sum += nums[i];
            }
            else {
                ans = max(ans, sum);
                sum += (nums[i] - nums[i - k]);
            }
        }
        ans = max(ans, sum);
        return ans / k;
    }
};