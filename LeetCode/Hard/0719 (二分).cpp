/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-16 19:05:21
 */ 
class Solution {
public:
    // 求出小于当前距离 diff 的个数 cnt
    int count(vector<int>&nums, int diff) {
        int cnt = 0;
        int j = 1;
        for(int i = 0; i < nums.size(); i++) {
            while(j < nums.size() && nums[j] - nums[i] <= diff) {
                j++;
            }
            cnt += j - i - 1;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums[nums.size() - 1] - nums[0];
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(count(nums, mid) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return high;
    }
};