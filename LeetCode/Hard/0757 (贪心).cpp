/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-17 16:33:08
 */ 
class Solution {
public:
    // 贪心
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b) {
            if(a[1] != b[1]) {
                return a[1] < b[1];
            }
            else {
                return a[0] > b[0];
            }
        });
        
        int ans = 0;
        int pre_left = -1, pre_right = -1;
        for(int i = 0; i < intervals.size(); i++) {
            
            if(intervals[i][0] <= pre_left) continue;
            
            // 当前的区间的左值比上一个区间的右值还大
            if(intervals[i][0] > pre_right) {
                ans += 2;
                pre_right = intervals[i][1];
                pre_left = pre_right - 1;
            }
            // 重叠了
            else {
                ans += 1;
                pre_left = pre_right;
                pre_right = intervals[i][1];
            }
        }
        
        return ans;
    }
};