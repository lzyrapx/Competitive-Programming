/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 16:52:17
 */
class Solution {
public:
    // 1 <= arr.length <= 1000
    // -1000 <= arr[i] <= 1000
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(auto x : arr) {
            mp[x]++;
        }
        map<int,int>mpp;
        for(auto x: mp) {
            mpp[x.second]++;
            if(mpp[x.second] > 1) return false;
        }
        return true;
    }
};