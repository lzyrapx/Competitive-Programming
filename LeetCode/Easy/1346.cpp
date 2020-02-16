/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-16 19:19:27
 */
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        if(arr.size() == 0) {
            return false;
        }
        map<int,int>mp;
        for(int i = 0; i < arr.size(); i++) {
             mp[arr[i]] += 1;
        }
        if(mp[0] > 1) return true;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) continue;
            if(mp[2 * arr[i]]) return true;
        }
        return false;
    }
};