/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-07 22:57:53
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > a) {
                c = b;
                b = a;
                a = nums[i];
            }
            else if(nums[i] < a && nums[i] > b) {
                c = b;
                b = nums[i];
            }
            else if(nums[i] < b && nums[i] > c) {
                c = nums[i];
            }
        }
        //  If it does not exist, return the maximum number.
        if(c == LONG_MIN) {
            return a;
        }
        return c;
    }
};