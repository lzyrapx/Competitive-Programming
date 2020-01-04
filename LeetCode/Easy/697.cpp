/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-25 00:33:46
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() <= 1) return 1;
        map<int, pair<int,int>>mp;
        map<int,int>vis;
        int maxn = 1;
        int maxnum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(vis[nums[i]] == 0) {
                vis[nums[i]] ++;
                mp[nums[i]] = make_pair(i, i);
            } 
            else 
            {
                vis[nums[i]]++;
                if(vis[nums[i]] >= maxn) {
                    maxn = vis[nums[i]];
                    mp[nums[i]] = make_pair(mp[nums[i]].first, i);
                }
            }
        }
        int ans = 1e9;
        for(int i = 0; i < nums.size(); i++) {
            if(vis[nums[i]] == maxn) {
                cout << "nums = " << nums[i] << endl;
                ans = min(ans, mp[nums[i]].second  - mp[nums[i]].first + 1);
            }
        }
        return ans;
    }
};