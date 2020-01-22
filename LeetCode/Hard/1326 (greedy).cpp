/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-22 23:35:38
 */
class Solution {
public:
    // greedy
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>ve;
        for(int i = 0; i < ranges.size(); i++) {
            ve.push_back({max(i - ranges[i], 0), min(i + ranges[i], n)});
        }
        sort(ve.begin(), ve.end());
        int cnt = 0;
        int end = 0;
        int new_end = 0;
        for(int i = 0; i < ve.size() && end != n; i++) {
            if(ve[i].first > end) {
                return -1;
            }
            new_end = max(new_end, ve[i].second);
            if(i + 1 == ve.size() || ve[i + 1].first > end) {
                cnt++;
                // cout << i << " " << ve[i].second << endl;
                end = new_end;
            }
        }
        if(end != n) {
            return -1;
        }
        return cnt;
    }
};