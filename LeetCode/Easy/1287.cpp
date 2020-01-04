/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-22 14:53:18
 */
class Solution {
public:
    // exactly one
    int findSpecialInteger(vector<int>& arr) {
        
        unordered_map<int,int>mp;
        
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
            if(mp[arr[i]] > arr.size() / 4) {
                return arr[i];
            }
        }
        return 0;
    }
};