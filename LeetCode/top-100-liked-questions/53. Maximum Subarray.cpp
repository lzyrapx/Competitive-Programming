class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = 0;
        int ans = -INT_MAX;
        for(int i = 0;i < nums.size();i++) {
            if(dp >= 0){
                dp += nums[i];
            }
            else dp = nums[i];
            
            if(ans < dp) {
                ans = dp;
            }
        }
        return ans;
    }
};