/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-11 23:48:09
 */ 
class Solution {
public:
    // abs(nums[i] - nums[j]) <= t
    // abs(i - j) <= k
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() == 0) {
            return false;
        }
        vector<pair<long long, long long>>ve;
        for(int i = 0; i < nums.size(); i++) {
            ve.push_back(make_pair(nums[i], i));
        }
        sort(ve.begin(), ve.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(abs(ve[i].first - ve[j].first) > t) {
                    break;
                }
                if(abs(ve[i].second - ve[j].second) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};