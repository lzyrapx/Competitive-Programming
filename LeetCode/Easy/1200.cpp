/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-09 14:59:09
 */
class Solution {
public:
    // 2 <= arr.length <= 10^5
    // -10^6 <= arr[i] <= 10^6
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minn = 3e6;
        for(int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            minn = min(diff, minn);
        }
        vector<vector<int>>ans;
        for(int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if(diff == minn) {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};