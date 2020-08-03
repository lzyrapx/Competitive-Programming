class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() <= 2) {
            return false;
        }
        int mx = INT_MAX;
        int mn = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mn) { // 最小
                mn = nums[i];
            } else if(nums[i] <= mx) { // 次小
                mx = nums[i];
            } else { // 第三大
                return true;
            }
        }
        return false;
    }
};