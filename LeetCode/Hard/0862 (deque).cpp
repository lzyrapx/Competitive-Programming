/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-31 16:17:41
 */
class Solution {
public:
    // segment tree
    // two points
    // deque
    // binary search 
    int shortestSubarray(vector<int>& A, int K) {
        deque<pair<int,int>>dq;
        dq.push_back({0, -1});
        int preSum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < A.size(); i++) {
            preSum += A[i];
            while(!dq.empty() && preSum - dq.front().first >= K) {
                ans = min(ans, i - dq.front().second);
                dq.pop_front();
            }
            while(!dq.empty() && preSum <= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({preSum, i});
        }
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};