class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int minn = INT_MAX;
        for(auto x : nums) {
            if(x < minn) minn = x;
        }
        int ans = 0;
        for(auto x : nums) {
            ans += (x - minn);
        }
        return ans;
    }
};