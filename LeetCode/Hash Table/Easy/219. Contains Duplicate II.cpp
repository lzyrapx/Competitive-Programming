class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] && i + 1 - mp[nums[i]] <= k) return true;
            mp[nums[i]] = i + 1;
        }
        return false;
    }
};