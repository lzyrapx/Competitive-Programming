/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s),  end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval &x, Interval &y)
    {
        return x.start < y.start || (x.start == y.start && x.end < y.end);
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval>ans;
        if(intervals.size() == 0) return ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans.push_back(intervals[i]);
            }
            else if(intervals[i].start > ans.back().end) {
                ans.push_back(intervals[i]);
            }
            else if(intervals[i].end <= ans.back().end) continue;
            else if(intervals[i].end > ans.back().end) {
                ans.back().end = intervals[i].end;
            }
        }
        return ans;
    }
};