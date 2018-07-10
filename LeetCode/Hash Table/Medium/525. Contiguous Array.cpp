class Solution {
public:
	// 求最大区间的长度，区间满足区间内的01个数都相等
    int findMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        map<int,int>mp;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) sum++;
            else sum --;
            if(sum == 0) {
                ans = i + 1;
            }
            else if(mp.count(sum)) {
                ans = max(i - mp[sum], ans);
            }
            else mp[sum] = i;
        }
        return ans;
    }
};