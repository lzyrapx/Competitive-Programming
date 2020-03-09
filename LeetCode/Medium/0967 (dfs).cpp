/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-08 20:02:19
 */
class Solution {
public:
    // the absolute difference between every two consecutive digits is K
    void dfs(vector<int>&ans, int cur_num, int N, int K) {
        if(N == 0) {
            ans.push_back(cur_num);
            return;
        }
        int last = cur_num % 10;
        if(last + K < 10) {
            dfs(ans, cur_num * 10 + last + K, N - 1, K);
        }
        if(last >= K && K > 0) {
            dfs(ans, cur_num * 10 + last - K, N - 1, K);
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int>ans;
        if(N == 1) {
            ans.push_back(0);
        }
        
        for(int i = 1; i <= 9; i++) {
            dfs(ans, i, N - 1, K);
        }
        return ans;
    }
};