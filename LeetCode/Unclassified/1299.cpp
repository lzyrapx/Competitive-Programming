/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 01:08:36
 */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>ans;
        int maxNum = arr[arr.size() - 1];
        ans.push_back(-1);
        for(int i = arr.size() - 1; i >= 1; --i) {
            maxNum = max(arr[i], maxNum);
            ans.push_back(maxNum);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};