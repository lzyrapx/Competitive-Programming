class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int,int>mp;
        for(auto x : nums) {
            mp[x]++;
            if(mp[x] > 1) return x;
        }
        return 0;
    }
};