class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        map<int,int>mp;
        for(int i = 0 ; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > n / 2) return nums[i];
        }
        return 0;
    }
};