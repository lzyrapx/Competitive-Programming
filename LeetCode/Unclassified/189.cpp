/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 20:35:07
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        reverse(nums.begin(), nums.begin() + len);
        reverse(nums.begin(), nums.begin() + k % len);
        reverse(nums.begin() + k % len, nums.begin() + len);
    }
}; 