class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = 0;
        for(auto x : nums) {
            ans ^= x;
        }
        return ans;
    }
};