/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-17 22:56:29
 */
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i = 0; i < arr1.size(); i++) {
            mp[arr1[i]] += 1;
        }
        for(int i = 0; i < arr2.size(); i++) {
            if(mp[arr2[i]] > 0) {
                while(mp[arr2[i]] > 0) {
                    ans.push_back(arr2[i]);
                    mp[arr2[i]] -= 1;
                }
            }
        }
        vector<int>tmp;
        for(int i = 0; i < arr1.size(); i++) {
            if(mp[arr1[i]] > 0) {
                 while(mp[arr1[i]] > 0) {
                    tmp.push_back(arr1[i]);
                    mp[arr1[i]] -= 1;
                }
            }
        }
        sort(tmp.begin(), tmp.end());
        ans.insert(ans.end(), tmp.begin(), tmp.end());
        return ans;
    }
};