/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-16 18:31:33
 */
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans;
        if(arr.size() == 0) {
            return ans;
        }
        map<int,int>mp;
        
        vector<int>tmp = arr;
        sort(tmp.begin(), tmp.end());
        int len = unique(tmp.begin(), tmp.end()) - tmp.begin();
        for(int i = 0; i < len; i++) {
            mp[tmp[i]] = i + 1;
        }
        for(int i = 0; i < arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};