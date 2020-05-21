/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-17 16:36:57
 */ 
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for(int i = 0; i <  min(startTime.size(), endTime.size()); i++) {
            if(startTime[i] <= queryTime && queryTime <= endTime[i]) {
                ans ++;
            }
        }
        return ans;
    }
};