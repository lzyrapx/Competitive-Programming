class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) return true;
        }
        return false;
    }
};