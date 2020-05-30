/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-30 18:11:36
 */ 
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        deque<int>dq;
        vector<int>ve;
        int sum;
        for(int i = 0; i < nums.size(); i++) {
            if(dq.empty()) {
                sum = nums[i];
            } else {
                sum = dq.front() + nums[i];
            }
            ans = max(ans, sum);
            // deque 维护的是一个单调递减队列， front value <= back value
            while(!dq.empty() && dq.back() < sum) dq.pop_back();
            if(sum > 0) {
                dq.push_back(sum);
            }
            ve.push_back(sum);
            if(i - k >= 0) {
                if(ve[i - k] >= dq.front() && !dq.empty()) {
                    dq.pop_front();
                }
            }
        }
        return ans;
    }
};