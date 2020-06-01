/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-06-01 22:48:54
 */ 
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for(int i = 0; i < target.size(); i++) {
            if(target[i] != arr[i]) {
                return false;
            }
        }
        return true;
    }
};