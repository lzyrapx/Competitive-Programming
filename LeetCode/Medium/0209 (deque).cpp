/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-06 00:49:15
 */ 
#include <vector>
#include <deque>
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        deque<int>dq;
        int n = nums.size();
        int min_len = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            dq.push_back(nums[i]);
            while(!dq.empty() && (sum - dq.front()) >= s) {
                sum -= dq.front();
                dq.pop_front();
            }
            if(sum >= s) {
                if(min_len == 0) {
                    min_len = dq.size();
                }
                else {
                    min_len = min(min_len, (int)dq.size());
                }
            }
        }
        return min_len;
    }
};