/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-24 15:42:21
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if(intervals.size() == 0) {
            vector<vector<int>>ans;
            ans.push_back(newInterval);
            return ans;
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int k = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= intervals[k][1]) {
                intervals[k][1] = max(intervals[k][1], intervals[i][1]);
            }
            else {
                k += 1;
                intervals[k] = intervals[i];
            }
        }
        if(k  < intervals.size() - 1) {
            intervals.erase(intervals.begin() + k + 1, intervals.end());
        }
        return intervals;
    }
};