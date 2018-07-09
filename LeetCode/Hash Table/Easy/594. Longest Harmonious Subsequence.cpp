class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        map<int,int>mp;
        int ans = 0;
        for(auto x: nums){
            mp[x]++;
            if(mp[x - 1] != 0) {
                ans = max(ans , mp[x] + mp[x - 1]);
            }
            if(mp[x + 1] != 0) {
                ans = max(ans, mp[x] + mp[x + 1]);
            }
        }
        return ans;
    }
};