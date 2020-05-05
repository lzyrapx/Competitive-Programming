/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-05 16:21:45
 */
class Solution {
public:
    //  The integer 1 <= d, t, n <= 10,000.
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>&a, vector<int>&b) {
            return a[1] < b[1];
        });
        int total_time = 0;
        priority_queue<int>pq;
        for(int i = 0; i < courses.size(); i++){
            pq.push(courses[i][0]);
            total_time += courses[i][0];
            if(total_time > courses[i][1]) {
                int tp = pq.top();
                pq.pop();
                total_time -= tp;
            }
        }
        return pq.size();
    }
};