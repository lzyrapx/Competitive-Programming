/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-20 22:39:29
 */ 
class Solution {
public:
    // space complexity: O(1)
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        if(n == 0) {
            return ans;
        }
        int cand1 = nums[0];
        int cand2 = nums[0];
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == cand1) {
                cnt1++;
                continue;
            }
            if(nums[i] == cand2) {
                cnt2++;
                continue;
            }
            if(cnt1 == 0) {
                cand1 = nums[i];
                cnt1++;
                continue;
            }
            if(cnt2 == 0) {
                cand2 = nums[i];
                cnt2++;
                continue;
            }
            cnt1--;
            cnt2--;
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == cand1) {
                cnt1++;
            }
            else if(nums[i] == cand2) {
                cnt2++;
            }
        }
        if(cnt1 > n / 3) {
            ans.push_back(cand1);
        }
        if(cnt2 > n / 3) {
            ans.push_back(cand2);
        }
        return ans;
    }
};